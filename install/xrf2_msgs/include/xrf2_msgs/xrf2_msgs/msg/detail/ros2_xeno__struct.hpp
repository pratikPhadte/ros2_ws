// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from xrf2_msgs:msg/Ros2Xeno.idl
// generated code does not contain a copyright notice

#ifndef XRF2_MSGS__MSG__DETAIL__ROS2_XENO__STRUCT_HPP_
#define XRF2_MSGS__MSG__DETAIL__ROS2_XENO__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__xrf2_msgs__msg__Ros2Xeno __attribute__((deprecated))
#else
# define DEPRECATED__xrf2_msgs__msg__Ros2Xeno __declspec(deprecated)
#endif

namespace xrf2_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Ros2Xeno_
{
  using Type = Ros2Xeno_<ContainerAllocator>;

  explicit Ros2Xeno_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->leftmotvel = 0.0;
      this->rightmotvel = 0.0;
    }
  }

  explicit Ros2Xeno_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->leftmotvel = 0.0;
      this->rightmotvel = 0.0;
    }
  }

  // field types and members
  using _leftmotvel_type =
    double;
  _leftmotvel_type leftmotvel;
  using _rightmotvel_type =
    double;
  _rightmotvel_type rightmotvel;

  // setters for named parameter idiom
  Type & set__leftmotvel(
    const double & _arg)
  {
    this->leftmotvel = _arg;
    return *this;
  }
  Type & set__rightmotvel(
    const double & _arg)
  {
    this->rightmotvel = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    xrf2_msgs::msg::Ros2Xeno_<ContainerAllocator> *;
  using ConstRawPtr =
    const xrf2_msgs::msg::Ros2Xeno_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<xrf2_msgs::msg::Ros2Xeno_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<xrf2_msgs::msg::Ros2Xeno_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      xrf2_msgs::msg::Ros2Xeno_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<xrf2_msgs::msg::Ros2Xeno_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      xrf2_msgs::msg::Ros2Xeno_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<xrf2_msgs::msg::Ros2Xeno_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<xrf2_msgs::msg::Ros2Xeno_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<xrf2_msgs::msg::Ros2Xeno_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__xrf2_msgs__msg__Ros2Xeno
    std::shared_ptr<xrf2_msgs::msg::Ros2Xeno_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__xrf2_msgs__msg__Ros2Xeno
    std::shared_ptr<xrf2_msgs::msg::Ros2Xeno_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Ros2Xeno_ & other) const
  {
    if (this->leftmotvel != other.leftmotvel) {
      return false;
    }
    if (this->rightmotvel != other.rightmotvel) {
      return false;
    }
    return true;
  }
  bool operator!=(const Ros2Xeno_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Ros2Xeno_

// alias to use template instance with default allocator
using Ros2Xeno =
  xrf2_msgs::msg::Ros2Xeno_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace xrf2_msgs

#endif  // XRF2_MSGS__MSG__DETAIL__ROS2_XENO__STRUCT_HPP_
