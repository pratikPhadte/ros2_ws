// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from xrf2_msgs:msg/Xeno2Ros.idl
// generated code does not contain a copyright notice
#include "xrf2_msgs/msg/detail/xeno2_ros__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "xrf2_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "xrf2_msgs/msg/detail/xeno2_ros__struct.h"
#include "xrf2_msgs/msg/detail/xeno2_ros__functions.h"
#include "fastcdr/Cdr.h"

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

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _Xeno2Ros__ros_msg_type = xrf2_msgs__msg__Xeno2Ros;

static bool _Xeno2Ros__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Xeno2Ros__ros_msg_type * ros_message = static_cast<const _Xeno2Ros__ros_msg_type *>(untyped_ros_message);
  // Field name: example_c
  {
    cdr << ros_message->example_c;
  }

  // Field name: example_d
  {
    cdr << ros_message->example_d;
  }

  return true;
}

static bool _Xeno2Ros__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Xeno2Ros__ros_msg_type * ros_message = static_cast<_Xeno2Ros__ros_msg_type *>(untyped_ros_message);
  // Field name: example_c
  {
    cdr >> ros_message->example_c;
  }

  // Field name: example_d
  {
    cdr >> ros_message->example_d;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_xrf2_msgs
size_t get_serialized_size_xrf2_msgs__msg__Xeno2Ros(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Xeno2Ros__ros_msg_type * ros_message = static_cast<const _Xeno2Ros__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name example_c
  {
    size_t item_size = sizeof(ros_message->example_c);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name example_d
  {
    size_t item_size = sizeof(ros_message->example_d);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _Xeno2Ros__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_xrf2_msgs__msg__Xeno2Ros(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_xrf2_msgs
size_t max_serialized_size_xrf2_msgs__msg__Xeno2Ros(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: example_c
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: example_d
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = xrf2_msgs__msg__Xeno2Ros;
    is_plain =
      (
      offsetof(DataType, example_d) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _Xeno2Ros__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_xrf2_msgs__msg__Xeno2Ros(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Xeno2Ros = {
  "xrf2_msgs::msg",
  "Xeno2Ros",
  _Xeno2Ros__cdr_serialize,
  _Xeno2Ros__cdr_deserialize,
  _Xeno2Ros__get_serialized_size,
  _Xeno2Ros__max_serialized_size
};

static rosidl_message_type_support_t _Xeno2Ros__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Xeno2Ros,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, xrf2_msgs, msg, Xeno2Ros)() {
  return &_Xeno2Ros__type_support;
}

#if defined(__cplusplus)
}
#endif
