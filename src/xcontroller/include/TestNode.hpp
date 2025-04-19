#ifndef TESTING_NODE_HPP_
#define TESTING_NODE_HPP_

#include "rclcpp/rclcpp.hpp"
#include "xrf2_msgs/msg/ros2_xeno.hpp"
#include "std_msgs/msg/int32.hpp"
#include <map>
#include <string>

class TestingNode : public rclcpp::Node
{
public:
  TestingNode();

private:
  rclcpp::Publisher<xrf2_msgs::msg::Ros2Xeno>::SharedPtr ros2xeno_pub_;
  rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr xenocnd_pub_;
};

#endif  // TESTING_NODE_HPP_
