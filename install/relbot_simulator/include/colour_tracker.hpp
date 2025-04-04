#ifndef COLOUR_TRACKER_HPP
#define COLOUR_TRACKER_HPP

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "geometry_msgs/msg/point.hpp"
#include "cv_bridge/cv_bridge.h"
#include "opencv2/opencv.hpp"

class ColourTracker : public rclcpp::Node {
public:
    explicit ColourTracker(const std::string &cam_input);  // Updated constructor

private:
    void image_callback(const sensor_msgs::msg::Image::SharedPtr msg);
    rcl_interfaces::msg::SetParametersResult on_parameter_change(const std::vector<rclcpp::Parameter> &params);

    rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr image_subscriber_;
    rclcpp::Publisher<geometry_msgs::msg::Point>::SharedPtr position_publisher_;
    OnSetParametersCallbackHandle::SharedPtr parameter_callback_handle_;

    int hue_low_, hue_high_, saturation_low_, saturation_high_, value_low_, value_high_;
};

#endif // COLOUR_TRACKER_HPP
