// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from xrf2_msgs:msg/Ros2Xeno.idl
// generated code does not contain a copyright notice

#ifndef XRF2_MSGS__MSG__DETAIL__ROS2_XENO__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define XRF2_MSGS__MSG__DETAIL__ROS2_XENO__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "xrf2_msgs/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "xrf2_msgs/msg/detail/ros2_xeno__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace xrf2_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xrf2_msgs
cdr_serialize(
  const xrf2_msgs::msg::Ros2Xeno & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xrf2_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  xrf2_msgs::msg::Ros2Xeno & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xrf2_msgs
get_serialized_size(
  const xrf2_msgs::msg::Ros2Xeno & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xrf2_msgs
max_serialized_size_Ros2Xeno(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace xrf2_msgs

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xrf2_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, xrf2_msgs, msg, Ros2Xeno)();

#ifdef __cplusplus
}
#endif

#endif  // XRF2_MSGS__MSG__DETAIL__ROS2_XENO__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
