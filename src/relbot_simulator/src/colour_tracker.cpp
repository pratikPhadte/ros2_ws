#include "colour_tracker.hpp"

ColourTracker::ColourTracker(const std::string &cam_input) : Node("colour_tracker_node") {
    // HSV range for orange color
    this->declare_parameter<int>("hue_low", 35);
    this->declare_parameter<int>("hue_high", 85);
    this->declare_parameter<int>("saturation_low", 60);
    this->declare_parameter<int>("saturation_high", 255);
    this->declare_parameter<int>("value_low", 60);
    this->declare_parameter<int>("value_high", 255);

    // Get parameters
    this->get_parameter("hue_low", hue_low_);
    this->get_parameter("hue_high", hue_high_);
    this->get_parameter("saturation_low", saturation_low_);
    this->get_parameter("saturation_high", saturation_high_);
    this->get_parameter("value_low", value_low_);
    this->get_parameter("value_high", value_high_);

    // Determine image topic based on cam_input argument
    std::string image_topic = (cam_input == "webcam") ? "/image" : "/output/moving_camera";

    // Subscribe to selected image topic
    image_subscriber_ = this->create_subscription<sensor_msgs::msg::Image>(
        image_topic, 10, std::bind(&ColourTracker::image_callback, this, std::placeholders::_1));

    // Publisher for object position
    position_publisher_ = this->create_publisher<geometry_msgs::msg::Point>("/object_position", 10);

    // Dynamic parameter update
    parameter_callback_handle_ = this->add_on_set_parameters_callback(
        std::bind(&ColourTracker::on_parameter_change, this, std::placeholders::_1));

    RCLCPP_INFO(this->get_logger(), "Orange Object Tracker Node Started with topic: %s", image_topic.c_str());
}

rcl_interfaces::msg::SetParametersResult ColourTracker::on_parameter_change(const std::vector<rclcpp::Parameter> &params)
{
    for (const auto &param : params)
    {
        if (param.get_name() == "hue_low") hue_low_ = param.as_int();
        if (param.get_name() == "hue_high") hue_high_ = param.as_int();
        if (param.get_name() == "saturation_low") saturation_low_ = param.as_int();
        if (param.get_name() == "saturation_high") saturation_high_ = param.as_int();
        if (param.get_name() == "value_low") value_low_ = param.as_int();
        if (param.get_name() == "value_high") value_high_ = param.as_int();
    }

    RCLCPP_INFO(this->get_logger(), "HSV thresholds updated");

    rcl_interfaces::msg::SetParametersResult result;
    result.successful = true;
    return result;
}

void ColourTracker::image_callback(const sensor_msgs::msg::Image::SharedPtr msg)
{
    // Convert ROS2 image to OpenCV
    cv_bridge::CvImagePtr cv_ptr;
    try
    {
        cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
    }
    catch (cv_bridge::Exception &e)
    {
        RCLCPP_ERROR(this->get_logger(), "cv_bridge exception: %s", e.what());
        return;
    }

    // Convert to HSV color space
    cv::Mat hsv_image;
    cv::cvtColor(cv_ptr->image, hsv_image, cv::COLOR_BGR2HSV);

    // Threshold for orange color
    cv::Scalar lower_bound(hue_low_, saturation_low_, value_low_);
    cv::Scalar upper_bound(hue_high_, saturation_high_, value_high_);
    cv::Mat mask;
    cv::inRange(hsv_image, lower_bound, upper_bound, mask);

    // Calculate center of gravity (CoG)
    cv::Moments m = cv::moments(mask, true);
    geometry_msgs::msg::Point object_position;

    if (m.m00 > 0)
    {
        object_position.x = m.m10 / m.m00;
        object_position.y = m.m01 / m.m00;
        object_position.z = 0.0;

        // Draw detected object
        cv::circle(cv_ptr->image, cv::Point(object_position.x, object_position.y), 5, cv::Scalar(0, 255, 0), -1);
    }
    else
    {
        object_position.x = -1;
        object_position.y = -1;
        object_position.z = 0.0;
    }

    // Publish object position
    position_publisher_->publish(object_position);

    // Log window size
    RCLCPP_INFO(this->get_logger(), "Image size: %d x %d", cv_ptr->image.cols, cv_ptr->image.rows);

    // Show the result
    cv::imshow("Orange Object Detection", cv_ptr->image);
    cv::waitKey(1);
}

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);

    // Default camera input is "robotcam"
    std::string cam_input = "robotcam";
    if (argc > 1) {
        cam_input = argv[1]; // Get command line argument
    }
    
    rclcpp::spin(std::make_shared<ColourTracker>(cam_input));
    rclcpp::shutdown();
    return 0;
} 
