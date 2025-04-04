// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from xrf2_msgs:msg/Ros2Xeno.idl
// generated code does not contain a copyright notice

#ifndef XRF2_MSGS__MSG__DETAIL__ROS2_XENO__FUNCTIONS_H_
#define XRF2_MSGS__MSG__DETAIL__ROS2_XENO__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "xrf2_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "xrf2_msgs/msg/detail/ros2_xeno__struct.h"

/// Initialize msg/Ros2Xeno message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * xrf2_msgs__msg__Ros2Xeno
 * )) before or use
 * xrf2_msgs__msg__Ros2Xeno__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_xrf2_msgs
bool
xrf2_msgs__msg__Ros2Xeno__init(xrf2_msgs__msg__Ros2Xeno * msg);

/// Finalize msg/Ros2Xeno message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_xrf2_msgs
void
xrf2_msgs__msg__Ros2Xeno__fini(xrf2_msgs__msg__Ros2Xeno * msg);

/// Create msg/Ros2Xeno message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * xrf2_msgs__msg__Ros2Xeno__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_xrf2_msgs
xrf2_msgs__msg__Ros2Xeno *
xrf2_msgs__msg__Ros2Xeno__create();

/// Destroy msg/Ros2Xeno message.
/**
 * It calls
 * xrf2_msgs__msg__Ros2Xeno__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_xrf2_msgs
void
xrf2_msgs__msg__Ros2Xeno__destroy(xrf2_msgs__msg__Ros2Xeno * msg);

/// Check for msg/Ros2Xeno message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_xrf2_msgs
bool
xrf2_msgs__msg__Ros2Xeno__are_equal(const xrf2_msgs__msg__Ros2Xeno * lhs, const xrf2_msgs__msg__Ros2Xeno * rhs);

/// Copy a msg/Ros2Xeno message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_xrf2_msgs
bool
xrf2_msgs__msg__Ros2Xeno__copy(
  const xrf2_msgs__msg__Ros2Xeno * input,
  xrf2_msgs__msg__Ros2Xeno * output);

/// Initialize array of msg/Ros2Xeno messages.
/**
 * It allocates the memory for the number of elements and calls
 * xrf2_msgs__msg__Ros2Xeno__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_xrf2_msgs
bool
xrf2_msgs__msg__Ros2Xeno__Sequence__init(xrf2_msgs__msg__Ros2Xeno__Sequence * array, size_t size);

/// Finalize array of msg/Ros2Xeno messages.
/**
 * It calls
 * xrf2_msgs__msg__Ros2Xeno__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_xrf2_msgs
void
xrf2_msgs__msg__Ros2Xeno__Sequence__fini(xrf2_msgs__msg__Ros2Xeno__Sequence * array);

/// Create array of msg/Ros2Xeno messages.
/**
 * It allocates the memory for the array and calls
 * xrf2_msgs__msg__Ros2Xeno__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_xrf2_msgs
xrf2_msgs__msg__Ros2Xeno__Sequence *
xrf2_msgs__msg__Ros2Xeno__Sequence__create(size_t size);

/// Destroy array of msg/Ros2Xeno messages.
/**
 * It calls
 * xrf2_msgs__msg__Ros2Xeno__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_xrf2_msgs
void
xrf2_msgs__msg__Ros2Xeno__Sequence__destroy(xrf2_msgs__msg__Ros2Xeno__Sequence * array);

/// Check for msg/Ros2Xeno message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_xrf2_msgs
bool
xrf2_msgs__msg__Ros2Xeno__Sequence__are_equal(const xrf2_msgs__msg__Ros2Xeno__Sequence * lhs, const xrf2_msgs__msg__Ros2Xeno__Sequence * rhs);

/// Copy an array of msg/Ros2Xeno messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_xrf2_msgs
bool
xrf2_msgs__msg__Ros2Xeno__Sequence__copy(
  const xrf2_msgs__msg__Ros2Xeno__Sequence * input,
  xrf2_msgs__msg__Ros2Xeno__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // XRF2_MSGS__MSG__DETAIL__ROS2_XENO__FUNCTIONS_H_
