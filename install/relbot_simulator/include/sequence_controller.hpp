#ifndef SETPOINT_GENERATOR_HPP
#define SETPOINT_GENERATOR_HPP

#include <rclcpp/rclcpp.hpp>
#include <example_interfaces/msg/float64.hpp>
#include <geometry_msgs/msg/point.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <xrf2_msgs/msg/ros2_xeno.hpp>

class SequenceController : public rclcpp::Node {
public:
    SequenceController();

    double center_x;

private:
    void timer_callback();
    void object_position_callback(const geometry_msgs::msg::Point::SharedPtr msg);
    void image_callback(const sensor_msgs::msg::Image::SharedPtr msg);

    // rclcpp::Publisher<example_interfaces::msg::Float64>::SharedPtr left_pub_;
    // rclcpp::Publisher<example_interfaces::msg::Float64>::SharedPtr right_pub_;
    rclcpp::Publisher<xrf2_msgs::msg::Ros2Xeno>::SharedPtr publisher_;
    rclcpp::Subscription<geometry_msgs::msg::Point>::SharedPtr object_position_sub_;
    rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr image_sub_;
    rclcpp::TimerBase::SharedPtr timer_;
    
    double elapsed_time_;
    int phase_;
    bool use_tracking_mode_;  // Toggle between sequence and tracking
    double obj_x_;            // Latest object position x-coordinate
    double obj_y_;            // Latest object position y-coordinate (optional use)
    double image_width_;      // Webcam image width for centering
    double image_height_;     // Webcam image height
    std::string mode_;
};

#endif // SETPOINT_GENERATOR_HPP
