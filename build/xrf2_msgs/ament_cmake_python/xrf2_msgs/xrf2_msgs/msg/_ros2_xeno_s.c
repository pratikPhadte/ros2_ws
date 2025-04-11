// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from xrf2_msgs:msg/Ros2Xeno.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "xrf2_msgs/msg/detail/ros2_xeno__struct.h"
#include "xrf2_msgs/msg/detail/ros2_xeno__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool xrf2_msgs__msg__ros2_xeno__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[34];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("xrf2_msgs.msg._ros2_xeno.Ros2Xeno", full_classname_dest, 33) == 0);
  }
  xrf2_msgs__msg__Ros2Xeno * ros_message = _ros_message;
  {  // leftmotvel
    PyObject * field = PyObject_GetAttrString(_pymsg, "leftmotvel");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->leftmotvel = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // rightmotvel
    PyObject * field = PyObject_GetAttrString(_pymsg, "rightmotvel");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->rightmotvel = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * xrf2_msgs__msg__ros2_xeno__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Ros2Xeno */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("xrf2_msgs.msg._ros2_xeno");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Ros2Xeno");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  xrf2_msgs__msg__Ros2Xeno * ros_message = (xrf2_msgs__msg__Ros2Xeno *)raw_ros_message;
  {  // leftmotvel
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->leftmotvel);
    {
      int rc = PyObject_SetAttrString(_pymessage, "leftmotvel", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rightmotvel
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->rightmotvel);
    {
      int rc = PyObject_SetAttrString(_pymessage, "rightmotvel", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
