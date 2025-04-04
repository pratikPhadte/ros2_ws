// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from xrf2_msgs:msg/Xeno2Ros.idl
// generated code does not contain a copyright notice

#ifndef XRF2_MSGS__MSG__DETAIL__XENO2_ROS__TRAITS_HPP_
#define XRF2_MSGS__MSG__DETAIL__XENO2_ROS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "xrf2_msgs/msg/detail/xeno2_ros__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace xrf2_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Xeno2Ros & msg,
  std::ostream & out)
{
  out << "{";
  // member: example_c
  {
    out << "example_c: ";
    rosidl_generator_traits::value_to_yaml(msg.example_c, out);
    out << ", ";
  }

  // member: example_d
  {
    out << "example_d: ";
    rosidl_generator_traits::value_to_yaml(msg.example_d, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Xeno2Ros & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: example_c
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "example_c: ";
    rosidl_generator_traits::value_to_yaml(msg.example_c, out);
    out << "\n";
  }

  // member: example_d
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "example_d: ";
    rosidl_generator_traits::value_to_yaml(msg.example_d, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Xeno2Ros & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace xrf2_msgs

namespace rosidl_generator_traits
{

[[deprecated("use xrf2_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const xrf2_msgs::msg::Xeno2Ros & msg,
  std::ostream & out, size_t indentation = 0)
{
  xrf2_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use xrf2_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const xrf2_msgs::msg::Xeno2Ros & msg)
{
  return xrf2_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<xrf2_msgs::msg::Xeno2Ros>()
{
  return "xrf2_msgs::msg::Xeno2Ros";
}

template<>
inline const char * name<xrf2_msgs::msg::Xeno2Ros>()
{
  return "xrf2_msgs/msg/Xeno2Ros";
}

template<>
struct has_fixed_size<xrf2_msgs::msg::Xeno2Ros>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<xrf2_msgs::msg::Xeno2Ros>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<xrf2_msgs::msg::Xeno2Ros>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // XRF2_MSGS__MSG__DETAIL__XENO2_ROS__TRAITS_HPP_
