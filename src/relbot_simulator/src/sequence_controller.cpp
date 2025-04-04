#include "sequence_controller.hpp"
#include <chrono>
#include <algorithm>  // For std::min and std::max

SequenceController::SequenceController() : Node("Sequence_Controller"), 
    elapsed_time_(0.0), phase_(0), obj_x_(0.0), obj_y_(0.0), image_width_(320.0) {
    
    // Declare and get parameter for mode selection (default: tracking)
    declare_parameter("mode", "tracking");
    mode_ = get_parameter("mode").as_string();

 
    // Publishers
    left_pub_ = create_publisher<example_interfaces::msg::Float64>("/input/left_motor/setpoint_vel", 10);
    right_pub_ = create_publisher<example_interfaces::msg::Float64>("/input/right_motor/setpoint_vel", 10);

    // Subscriber for object position
    object_position_sub_ = create_subscription<geometry_msgs::msg::Point>(
        "/object_position", 10, std::bind(&SequenceController::object_position_callback, this, std::placeholders::_1));

    // Timer
    timer_ = create_wall_timer(std::chrono::milliseconds(100), std::bind(&SequenceController::timer_callback, this));

    // Assume webcam width
    //declare_parameter("image_width", 640.0);
    //image_width_ = get_parameter("image_width").as_double();

    RCLCPP_INFO(get_logger(), "Sequence Controller Node started in %s mode", mode_.c_str());
}

void SequenceController::timer_callback() {
    auto left_msg = example_interfaces::msg::Float64();
    auto right_msg = example_interfaces::msg::Float64();

    if (mode_ == "tracking") {
        // Tracking mode: Follow the bright spot
        double center_x = 60;
        double error_x = abs(obj_x_ - center_x); 
        double turn_vel = 4;

        if(obj_x_ == -1 && obj_y_ == -1) {
            // Zoom out to find object in frame
            left_msg.data = 2.0;
            right_msg.data = -2.0;
            RCLCPP_INFO(get_logger(), "Zooming out to find object");
        } else {
            // std::cout << "Error: " << error_x << std::endl;
            if (error_x < 2) {
                // Turn right
                left_msg.data = -2.0;  
                right_msg.data = 2.0;
                RCLCPP_INFO(get_logger(), "Zooming in to focus on object");
            } else {
                if (obj_x_ > center_x) {
                    // Turn right
                    left_msg.data = -turn_vel * (error_x / center_x);  
                    right_msg.data = 0.0;
                }
                if (obj_x_ < center_x) {
                    // Turn left
                    left_msg.data = 0.0;     
                    right_msg.data = turn_vel * (error_x / center_x);
                }
            }
        }

        // RCLCPP_INFO_THROTTLE(get_logger(), *get_clock(), 1000, 
        //                     "Tracking: Spot x=%.1f, Left=%.2f, Right=%.2f", 
        //                     obj_x_, left_msg.data, right_msg.data);
    } else if(mode_ =="testing") {
        // Sequence mode: Original pre-programmed sequence
        elapsed_time_ += 0.1;

        if (elapsed_time_ < 5.0) {
            left_msg.data = -1.0;      
            right_msg.data = 1.0;
            RCLCPP_INFO_THROTTLE(get_logger(), *get_clock(), 1000, "Phase 1: Moving forward vel:1.0");
        } else if (elapsed_time_ < 10.0) {
            left_msg.data = 0.0;    
            right_msg.data = 0.5;
            RCLCPP_INFO_THROTTLE(get_logger(), *get_clock(), 1000, "Phase 2: Turning left vel:0.5");
        } else if (elapsed_time_ < 15.0) {
            left_msg.data = -1.5;      
            right_msg.data = 1.5;
            RCLCPP_INFO_THROTTLE(get_logger(), *get_clock(), 1000, "Phase 3: Moving forward vel:2.0");
        } else if (elapsed_time_ < 20.0) {
            left_msg.data = -0.5;      
            right_msg.data = 0.0;
            RCLCPP_INFO_THROTTLE(get_logger(), *get_clock(), 1000, "Phase 4: Turning right vel:0.5");
        } else if (elapsed_time_ < 25.0) {
            left_msg.data = 2.0;     
            right_msg.data = -2.0;
            RCLCPP_INFO_THROTTLE(get_logger(), *get_clock(), 1000, "Phase 5: Moving backward vel:2.0");
        } else {
            left_msg.data = 0.0;
            right_msg.data = 0.0;
            RCLCPP_INFO_THROTTLE(get_logger(), *get_clock(), 1000, "Phase 6: Stopped");
        }
    }

    // Publish setpoints
    left_pub_->publish(left_msg);
    right_pub_->publish(right_msg);
}

void SequenceController::object_position_callback(const geometry_msgs::msg::Point::SharedPtr msg) {
    obj_x_ = msg->x;
    obj_y_ = msg->y;
    // RCLCPP_INFO_THROTTLE(get_logger(), *get_clock(), 1000, "Object position at x=%.1f, y=%.1f", obj_x_, obj_y_);
}

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<SequenceController>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
