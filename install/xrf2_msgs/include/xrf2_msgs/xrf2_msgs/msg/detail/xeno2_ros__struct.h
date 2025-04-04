// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from xrf2_msgs:msg/Xeno2Ros.idl
// generated code does not contain a copyright notice

#ifndef XRF2_MSGS__MSG__DETAIL__XENO2_ROS__STRUCT_H_
#define XRF2_MSGS__MSG__DETAIL__XENO2_ROS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Xeno2Ros in the package xrf2_msgs.
typedef struct xrf2_msgs__msg__Xeno2Ros
{
  double example_c;
  double example_d;
} xrf2_msgs__msg__Xeno2Ros;

// Struct for a sequence of xrf2_msgs__msg__Xeno2Ros.
typedef struct xrf2_msgs__msg__Xeno2Ros__Sequence
{
  xrf2_msgs__msg__Xeno2Ros * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} xrf2_msgs__msg__Xeno2Ros__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // XRF2_MSGS__MSG__DETAIL__XENO2_ROS__STRUCT_H_
