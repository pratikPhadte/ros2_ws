// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from xrf2_msgs:msg/Ros2Xeno.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "xrf2_msgs/msg/detail/ros2_xeno__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace xrf2_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void Ros2Xeno_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) xrf2_msgs::msg::Ros2Xeno(_init);
}

void Ros2Xeno_fini_function(void * message_memory)
{
  auto typed_message = static_cast<xrf2_msgs::msg::Ros2Xeno *>(message_memory);
  typed_message->~Ros2Xeno();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Ros2Xeno_message_member_array[2] = {
  {
    "left_mot_vel",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(xrf2_msgs::msg::Ros2Xeno, left_mot_vel),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "right_mot_vel",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(xrf2_msgs::msg::Ros2Xeno, right_mot_vel),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Ros2Xeno_message_members = {
  "xrf2_msgs::msg",  // message namespace
  "Ros2Xeno",  // message name
  2,  // number of fields
  sizeof(xrf2_msgs::msg::Ros2Xeno),
  Ros2Xeno_message_member_array,  // message members
  Ros2Xeno_init_function,  // function to initialize message memory (memory has to be allocated)
  Ros2Xeno_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Ros2Xeno_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Ros2Xeno_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace xrf2_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<xrf2_msgs::msg::Ros2Xeno>()
{
  return &::xrf2_msgs::msg::rosidl_typesupport_introspection_cpp::Ros2Xeno_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, xrf2_msgs, msg, Ros2Xeno)() {
  return &::xrf2_msgs::msg::rosidl_typesupport_introspection_cpp::Ros2Xeno_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
