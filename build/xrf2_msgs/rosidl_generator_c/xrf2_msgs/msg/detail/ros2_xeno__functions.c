// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from xrf2_msgs:msg/Ros2Xeno.idl
// generated code does not contain a copyright notice
#include "xrf2_msgs/msg/detail/ros2_xeno__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
xrf2_msgs__msg__Ros2Xeno__init(xrf2_msgs__msg__Ros2Xeno * msg)
{
  if (!msg) {
    return false;
  }
  // leftmotvel
  // rightmotvel
  return true;
}

void
xrf2_msgs__msg__Ros2Xeno__fini(xrf2_msgs__msg__Ros2Xeno * msg)
{
  if (!msg) {
    return;
  }
  // leftmotvel
  // rightmotvel
}

bool
xrf2_msgs__msg__Ros2Xeno__are_equal(const xrf2_msgs__msg__Ros2Xeno * lhs, const xrf2_msgs__msg__Ros2Xeno * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // leftmotvel
  if (lhs->leftmotvel != rhs->leftmotvel) {
    return false;
  }
  // rightmotvel
  if (lhs->rightmotvel != rhs->rightmotvel) {
    return false;
  }
  return true;
}

bool
xrf2_msgs__msg__Ros2Xeno__copy(
  const xrf2_msgs__msg__Ros2Xeno * input,
  xrf2_msgs__msg__Ros2Xeno * output)
{
  if (!input || !output) {
    return false;
  }
  // leftmotvel
  output->leftmotvel = input->leftmotvel;
  // rightmotvel
  output->rightmotvel = input->rightmotvel;
  return true;
}

xrf2_msgs__msg__Ros2Xeno *
xrf2_msgs__msg__Ros2Xeno__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  xrf2_msgs__msg__Ros2Xeno * msg = (xrf2_msgs__msg__Ros2Xeno *)allocator.allocate(sizeof(xrf2_msgs__msg__Ros2Xeno), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(xrf2_msgs__msg__Ros2Xeno));
  bool success = xrf2_msgs__msg__Ros2Xeno__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
xrf2_msgs__msg__Ros2Xeno__destroy(xrf2_msgs__msg__Ros2Xeno * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    xrf2_msgs__msg__Ros2Xeno__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
xrf2_msgs__msg__Ros2Xeno__Sequence__init(xrf2_msgs__msg__Ros2Xeno__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  xrf2_msgs__msg__Ros2Xeno * data = NULL;

  if (size) {
    data = (xrf2_msgs__msg__Ros2Xeno *)allocator.zero_allocate(size, sizeof(xrf2_msgs__msg__Ros2Xeno), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = xrf2_msgs__msg__Ros2Xeno__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        xrf2_msgs__msg__Ros2Xeno__fini(&data[i - 1]);
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
xrf2_msgs__msg__Ros2Xeno__Sequence__fini(xrf2_msgs__msg__Ros2Xeno__Sequence * array)
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
      xrf2_msgs__msg__Ros2Xeno__fini(&array->data[i]);
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

xrf2_msgs__msg__Ros2Xeno__Sequence *
xrf2_msgs__msg__Ros2Xeno__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  xrf2_msgs__msg__Ros2Xeno__Sequence * array = (xrf2_msgs__msg__Ros2Xeno__Sequence *)allocator.allocate(sizeof(xrf2_msgs__msg__Ros2Xeno__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = xrf2_msgs__msg__Ros2Xeno__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
xrf2_msgs__msg__Ros2Xeno__Sequence__destroy(xrf2_msgs__msg__Ros2Xeno__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    xrf2_msgs__msg__Ros2Xeno__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
xrf2_msgs__msg__Ros2Xeno__Sequence__are_equal(const xrf2_msgs__msg__Ros2Xeno__Sequence * lhs, const xrf2_msgs__msg__Ros2Xeno__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!xrf2_msgs__msg__Ros2Xeno__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
xrf2_msgs__msg__Ros2Xeno__Sequence__copy(
  const xrf2_msgs__msg__Ros2Xeno__Sequence * input,
  xrf2_msgs__msg__Ros2Xeno__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(xrf2_msgs__msg__Ros2Xeno);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    xrf2_msgs__msg__Ros2Xeno * data =
      (xrf2_msgs__msg__Ros2Xeno *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!xrf2_msgs__msg__Ros2Xeno__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          xrf2_msgs__msg__Ros2Xeno__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!xrf2_msgs__msg__Ros2Xeno__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
