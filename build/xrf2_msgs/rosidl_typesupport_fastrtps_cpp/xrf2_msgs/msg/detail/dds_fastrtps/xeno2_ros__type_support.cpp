// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from xrf2_msgs:msg/Xeno2Ros.idl
// generated code does not contain a copyright notice
#include "xrf2_msgs/msg/detail/xeno2_ros__rosidl_typesupport_fastrtps_cpp.hpp"
#include "xrf2_msgs/msg/detail/xeno2_ros__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace xrf2_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xrf2_msgs
cdr_serialize(
  const xrf2_msgs::msg::Xeno2Ros & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: example_c
  cdr << ros_message.example_c;
  // Member: example_d
  cdr << ros_message.example_d;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xrf2_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  xrf2_msgs::msg::Xeno2Ros & ros_message)
{
  // Member: example_c
  cdr >> ros_message.example_c;

  // Member: example_d
  cdr >> ros_message.example_d;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xrf2_msgs
get_serialized_size(
  const xrf2_msgs::msg::Xeno2Ros & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: example_c
  {
    size_t item_size = sizeof(ros_message.example_c);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: example_d
  {
    size_t item_size = sizeof(ros_message.example_d);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xrf2_msgs
max_serialized_size_Xeno2Ros(
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


  // Member: example_c
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: example_d
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
    using DataType = xrf2_msgs::msg::Xeno2Ros;
    is_plain =
      (
      offsetof(DataType, example_d) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _Xeno2Ros__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const xrf2_msgs::msg::Xeno2Ros *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Xeno2Ros__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<xrf2_msgs::msg::Xeno2Ros *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Xeno2Ros__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const xrf2_msgs::msg::Xeno2Ros *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Xeno2Ros__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_Xeno2Ros(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _Xeno2Ros__callbacks = {
  "xrf2_msgs::msg",
  "Xeno2Ros",
  _Xeno2Ros__cdr_serialize,
  _Xeno2Ros__cdr_deserialize,
  _Xeno2Ros__get_serialized_size,
  _Xeno2Ros__max_serialized_size
};

static rosidl_message_type_support_t _Xeno2Ros__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Xeno2Ros__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace xrf2_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_xrf2_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<xrf2_msgs::msg::Xeno2Ros>()
{
  return &xrf2_msgs::msg::typesupport_fastrtps_cpp::_Xeno2Ros__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, xrf2_msgs, msg, Xeno2Ros)() {
  return &xrf2_msgs::msg::typesupport_fastrtps_cpp::_Xeno2Ros__handle;
}

#ifdef __cplusplus
}
#endif
