// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from xrf2_msgs:msg/Xeno2Ros.idl
// generated code does not contain a copyright notice
#include "xrf2_msgs/msg/detail/xeno2_ros__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
xrf2_msgs__msg__Xeno2Ros__init(xrf2_msgs__msg__Xeno2Ros * msg)
{
  if (!msg) {
    return false;
  }
  // example_c
  // example_d
  return true;
}

void
xrf2_msgs__msg__Xeno2Ros__fini(xrf2_msgs__msg__Xeno2Ros * msg)
{
  if (!msg) {
    return;
  }
  // example_c
  // example_d
}

bool
xrf2_msgs__msg__Xeno2Ros__are_equal(const xrf2_msgs__msg__Xeno2Ros * lhs, const xrf2_msgs__msg__Xeno2Ros * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // example_c
  if (lhs->example_c != rhs->example_c) {
    return false;
  }
  // example_d
  if (lhs->example_d != rhs->example_d) {
    return false;
  }
  return true;
}

bool
xrf2_msgs__msg__Xeno2Ros__copy(
  const xrf2_msgs__msg__Xeno2Ros * input,
  xrf2_msgs__msg__Xeno2Ros * output)
{
  if (!input || !output) {
    return false;
  }
  // example_c
  output->example_c = input->example_c;
  // example_d
  output->example_d = input->example_d;
  return true;
}

xrf2_msgs__msg__Xeno2Ros *
xrf2_msgs__msg__Xeno2Ros__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  xrf2_msgs__msg__Xeno2Ros * msg = (xrf2_msgs__msg__Xeno2Ros *)allocator.allocate(sizeof(xrf2_msgs__msg__Xeno2Ros), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(xrf2_msgs__msg__Xeno2Ros));
  bool success = xrf2_msgs__msg__Xeno2Ros__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
xrf2_msgs__msg__Xeno2Ros__destroy(xrf2_msgs__msg__Xeno2Ros * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    xrf2_msgs__msg__Xeno2Ros__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
xrf2_msgs__msg__Xeno2Ros__Sequence__init(xrf2_msgs__msg__Xeno2Ros__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  xrf2_msgs__msg__Xeno2Ros * data = NULL;

  if (size) {
    data = (xrf2_msgs__msg__Xeno2Ros *)allocator.zero_allocate(size, sizeof(xrf2_msgs__msg__Xeno2Ros), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = xrf2_msgs__msg__Xeno2Ros__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        xrf2_msgs__msg__Xeno2Ros__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
xrf2_msgs__msg__Xeno2Ros__Sequence__fini(xrf2_msgs__msg__Xeno2Ros__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      xrf2_msgs__msg__Xeno2Ros__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

xrf2_msgs__msg__Xeno2Ros__Sequence *
xrf2_msgs__msg__Xeno2Ros__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  xrf2_msgs__msg__Xeno2Ros__Sequence * array = (xrf2_msgs__msg__Xeno2Ros__Sequence *)allocator.allocate(sizeof(xrf2_msgs__msg__Xeno2Ros__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = xrf2_msgs__msg__Xeno2Ros__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
xrf2_msgs__msg__Xeno2Ros__Sequence__destroy(xrf2_msgs__msg__Xeno2Ros__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    xrf2_msgs__msg__Xeno2Ros__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
xrf2_msgs__msg__Xeno2Ros__Sequence__are_equal(const xrf2_msgs__msg__Xeno2Ros__Sequence * lhs, const xrf2_msgs__msg__Xeno2Ros__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!xrf2_msgs__msg__Xeno2Ros__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
xrf2_msgs__msg__Xeno2Ros__Sequence__copy(
  const xrf2_msgs__msg__Xeno2Ros__Sequence * input,
  xrf2_msgs__msg__Xeno2Ros__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(xrf2_msgs__msg__Xeno2Ros);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    xrf2_msgs__msg__Xeno2Ros * data =
      (xrf2_msgs__msg__Xeno2Ros *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!xrf2_msgs__msg__Xeno2Ros__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          xrf2_msgs__msg__Xeno2Ros__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!xrf2_msgs__msg__Xeno2Ros__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
