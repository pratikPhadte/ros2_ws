// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from xrf2_msgs:msg/Ros2Xeno.idl
// generated code does not contain a copyright notice

#ifndef XRF2_MSGS__MSG__DETAIL__ROS2_XENO__STRUCT_H_
#define XRF2_MSGS__MSG__DETAIL__ROS2_XENO__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Ros2Xeno in the package xrf2_msgs.
typedef struct xrf2_msgs__msg__Ros2Xeno
{
  double leftmotvel;
  double rightmotvel;
} xrf2_msgs__msg__Ros2Xeno;

// Struct for a sequence of xrf2_msgs__msg__Ros2Xeno.
typedef struct xrf2_msgs__msg__Ros2Xeno__Sequence
{
  xrf2_msgs__msg__Ros2Xeno * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} xrf2_msgs__msg__Ros2Xeno__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // XRF2_MSGS__MSG__DETAIL__ROS2_XENO__STRUCT_H_
