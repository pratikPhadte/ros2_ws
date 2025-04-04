// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from xrf2_msgs:msg/Xeno2Ros.idl
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
#include "xrf2_msgs/msg/detail/xeno2_ros__struct.h"
#include "xrf2_msgs/msg/detail/xeno2_ros__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool xrf2_msgs__msg__xeno2_ros__convert_from_py(PyObject * _pymsg, void * _ros_message)
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
    assert(strncmp("xrf2_msgs.msg._xeno2_ros.Xeno2Ros", full_classname_dest, 33) == 0);
  }
  xrf2_msgs__msg__Xeno2Ros * ros_message = _ros_message;
  {  // example_c
    PyObject * field = PyObject_GetAttrString(_pymsg, "example_c");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->example_c = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // example_d
    PyObject * field = PyObject_GetAttrString(_pymsg, "example_d");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->example_d = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * xrf2_msgs__msg__xeno2_ros__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Xeno2Ros */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("xrf2_msgs.msg._xeno2_ros");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Xeno2Ros");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  xrf2_msgs__msg__Xeno2Ros * ros_message = (xrf2_msgs__msg__Xeno2Ros *)raw_ros_message;
  {  // example_c
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->example_c);
    {
      int rc = PyObject_SetAttrString(_pymessage, "example_c", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // example_d
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->example_d);
    {
      int rc = PyObject_SetAttrString(_pymessage, "example_d", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
