#include "rclcpp/rclcpp.hpp"
#include "xrf2_msgs/msg/ros2_xeno.hpp"
#include "std_msgs/msg/int32.hpp"
#include <TestNode.hpp>

class TestingNode : public rclcpp::Node
{
public:
  TestingNode()
    : Node("TestingNode")
  {
    // Declare parameters
    this->declare_parameter<std::string>("mode", "velocity");
    this->declare_parameter<double>("leftmotvel", 0.0);
    this->declare_parameter<double>("rightmotvel", 0.0);
    this->declare_parameter<std::string>("state", "Idle");

    std::string mode = this->get_parameter("mode").as_string();

    ros2xeno_pub_ = this->create_publisher<xrf2_msgs::msg::Ros2Xeno>("/Ros2Xeno", 10);
    xenocnd_pub_ = this->create_publisher<std_msgs::msg::Int32>("/XenoCnd", 10);

    if (mode == "velocity") {
      double left = this->get_parameter("leftmotvel").as_double();
      double right = this->get_parameter("rightmotvel").as_double();

      xrf2_msgs::msg::Ros2Xeno msg;
      msg.leftmotvel = left;
      msg.rightmotvel = right;

      ros2xeno_pub_->publish(msg);
      RCLCPP_INFO(this->get_logger(), "Published velocity: left=%.2f, right=%.2f", left, right);

    } else if (mode == "state") {
      std::string state_val = this->get_parameter("state").as_string();
      int int_state;

      if (isdigit(state_val[0])) {
        int_state = std::stoi(state_val);
      } else {
        // Map string state to integer
        std::map<std::string, int> state_map = {
          {"Idle", 1}, {"Initialising", 2}, {"Initialised", 3}, {"Run", 4},
          {"Stopping", 5}, {"Stopped", 6}, {"Pausing", 7}, {"Paused", 8},
          {"Error", 9}, {"Quit", 10}
        };
        if (state_map.find(state_val) != state_map.end()) {
          int_state = state_map[state_val];
        } else {
          RCLCPP_ERROR(this->get_logger(), "Invalid state string: %s", state_val.c_str());
          rclcpp::shutdown();
          return;
        }
      }

      std_msgs::msg::Int32 msg;
      msg.data = int_state;
      xenocnd_pub_->publish(msg);
      RCLCPP_INFO(this->get_logger(), "Published state: %s -> %d", state_val.c_str(), int_state);

    } else {
      RCLCPP_ERROR(this->get_logger(), "Invalid mode: %s", mode.c_str());
      rclcpp::shutdown();
      return;
    }

    rclcpp::shutdown(); // Exit immediately after publishing
  }

private:
  rclcpp::Publisher<xrf2_msgs::msg::Ros2Xeno>::SharedPtr ros2xeno_pub_;
  rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr xenocnd_pub_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<TestingNode>());
  return 0;
}
