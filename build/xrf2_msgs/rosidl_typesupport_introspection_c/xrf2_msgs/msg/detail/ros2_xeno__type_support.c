// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from xrf2_msgs:msg/Ros2Xeno.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "xrf2_msgs/msg/detail/ros2_xeno__rosidl_typesupport_introspection_c.h"
#include "xrf2_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "xrf2_msgs/msg/detail/ros2_xeno__functions.h"
#include "xrf2_msgs/msg/detail/ros2_xeno__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void xrf2_msgs__msg__Ros2Xeno__rosidl_typesupport_introspection_c__Ros2Xeno_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  xrf2_msgs__msg__Ros2Xeno__init(message_memory);
}

void xrf2_msgs__msg__Ros2Xeno__rosidl_typesupport_introspection_c__Ros2Xeno_fini_function(void * message_memory)
{
  xrf2_msgs__msg__Ros2Xeno__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember xrf2_msgs__msg__Ros2Xeno__rosidl_typesupport_introspection_c__Ros2Xeno_message_member_array[2] = {
  {
    "left_mot_vel",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(xrf2_msgs__msg__Ros2Xeno, left_mot_vel),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "right_mot_vel",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(xrf2_msgs__msg__Ros2Xeno, right_mot_vel),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers xrf2_msgs__msg__Ros2Xeno__rosidl_typesupport_introspection_c__Ros2Xeno_message_members = {
  "xrf2_msgs__msg",  // message namespace
  "Ros2Xeno",  // message name
  2,  // number of fields
  sizeof(xrf2_msgs__msg__Ros2Xeno),
  xrf2_msgs__msg__Ros2Xeno__rosidl_typesupport_introspection_c__Ros2Xeno_message_member_array,  // message members
  xrf2_msgs__msg__Ros2Xeno__rosidl_typesupport_introspection_c__Ros2Xeno_init_function,  // function to initialize message memory (memory has to be allocated)
  xrf2_msgs__msg__Ros2Xeno__rosidl_typesupport_introspection_c__Ros2Xeno_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t xrf2_msgs__msg__Ros2Xeno__rosidl_typesupport_introspection_c__Ros2Xeno_message_type_support_handle = {
  0,
  &xrf2_msgs__msg__Ros2Xeno__rosidl_typesupport_introspection_c__Ros2Xeno_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_xrf2_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, xrf2_msgs, msg, Ros2Xeno)() {
  if (!xrf2_msgs__msg__Ros2Xeno__rosidl_typesupport_introspection_c__Ros2Xeno_message_type_support_handle.typesupport_identifier) {
    xrf2_msgs__msg__Ros2Xeno__rosidl_typesupport_introspection_c__Ros2Xeno_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &xrf2_msgs__msg__Ros2Xeno__rosidl_typesupport_introspection_c__Ros2Xeno_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
