// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from gripper_interface:srv/Gripper.idl
// generated code does not contain a copyright notice

#ifndef GRIPPER_INTERFACE__SRV__DETAIL__GRIPPER__BUILDER_HPP_
#define GRIPPER_INTERFACE__SRV__DETAIL__GRIPPER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "gripper_interface/srv/detail/gripper__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace gripper_interface
{

namespace srv
{

namespace builder
{

class Init_Gripper_Request_cmd
{
public:
  Init_Gripper_Request_cmd()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::gripper_interface::srv::Gripper_Request cmd(::gripper_interface::srv::Gripper_Request::_cmd_type arg)
  {
    msg_.cmd = std::move(arg);
    return std::move(msg_);
  }

private:
  ::gripper_interface::srv::Gripper_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::gripper_interface::srv::Gripper_Request>()
{
  return gripper_interface::srv::builder::Init_Gripper_Request_cmd();
}

}  // namespace gripper_interface


namespace gripper_interface
{

namespace srv
{

namespace builder
{

class Init_Gripper_Response_status
{
public:
  Init_Gripper_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::gripper_interface::srv::Gripper_Response status(::gripper_interface::srv::Gripper_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::gripper_interface::srv::Gripper_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::gripper_interface::srv::Gripper_Response>()
{
  return gripper_interface::srv::builder::Init_Gripper_Response_status();
}

}  // namespace gripper_interface

#endif  // GRIPPER_INTERFACE__SRV__DETAIL__GRIPPER__BUILDER_HPP_
