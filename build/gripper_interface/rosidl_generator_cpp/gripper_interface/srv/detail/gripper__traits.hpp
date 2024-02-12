// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from gripper_interface:srv/Gripper.idl
// generated code does not contain a copyright notice

#ifndef GRIPPER_INTERFACE__SRV__DETAIL__GRIPPER__TRAITS_HPP_
#define GRIPPER_INTERFACE__SRV__DETAIL__GRIPPER__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "gripper_interface/srv/detail/gripper__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace gripper_interface
{

namespace srv
{

inline void to_flow_style_yaml(
  const Gripper_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: cmd
  {
    out << "cmd: ";
    rosidl_generator_traits::value_to_yaml(msg.cmd, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Gripper_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: cmd
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cmd: ";
    rosidl_generator_traits::value_to_yaml(msg.cmd, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Gripper_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace gripper_interface

namespace rosidl_generator_traits
{

[[deprecated("use gripper_interface::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const gripper_interface::srv::Gripper_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  gripper_interface::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use gripper_interface::srv::to_yaml() instead")]]
inline std::string to_yaml(const gripper_interface::srv::Gripper_Request & msg)
{
  return gripper_interface::srv::to_yaml(msg);
}

template<>
inline const char * data_type<gripper_interface::srv::Gripper_Request>()
{
  return "gripper_interface::srv::Gripper_Request";
}

template<>
inline const char * name<gripper_interface::srv::Gripper_Request>()
{
  return "gripper_interface/srv/Gripper_Request";
}

template<>
struct has_fixed_size<gripper_interface::srv::Gripper_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<gripper_interface::srv::Gripper_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<gripper_interface::srv::Gripper_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace gripper_interface
{

namespace srv
{

inline void to_flow_style_yaml(
  const Gripper_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Gripper_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Gripper_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace gripper_interface

namespace rosidl_generator_traits
{

[[deprecated("use gripper_interface::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const gripper_interface::srv::Gripper_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  gripper_interface::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use gripper_interface::srv::to_yaml() instead")]]
inline std::string to_yaml(const gripper_interface::srv::Gripper_Response & msg)
{
  return gripper_interface::srv::to_yaml(msg);
}

template<>
inline const char * data_type<gripper_interface::srv::Gripper_Response>()
{
  return "gripper_interface::srv::Gripper_Response";
}

template<>
inline const char * name<gripper_interface::srv::Gripper_Response>()
{
  return "gripper_interface/srv/Gripper_Response";
}

template<>
struct has_fixed_size<gripper_interface::srv::Gripper_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<gripper_interface::srv::Gripper_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<gripper_interface::srv::Gripper_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<gripper_interface::srv::Gripper>()
{
  return "gripper_interface::srv::Gripper";
}

template<>
inline const char * name<gripper_interface::srv::Gripper>()
{
  return "gripper_interface/srv/Gripper";
}

template<>
struct has_fixed_size<gripper_interface::srv::Gripper>
  : std::integral_constant<
    bool,
    has_fixed_size<gripper_interface::srv::Gripper_Request>::value &&
    has_fixed_size<gripper_interface::srv::Gripper_Response>::value
  >
{
};

template<>
struct has_bounded_size<gripper_interface::srv::Gripper>
  : std::integral_constant<
    bool,
    has_bounded_size<gripper_interface::srv::Gripper_Request>::value &&
    has_bounded_size<gripper_interface::srv::Gripper_Response>::value
  >
{
};

template<>
struct is_service<gripper_interface::srv::Gripper>
  : std::true_type
{
};

template<>
struct is_service_request<gripper_interface::srv::Gripper_Request>
  : std::true_type
{
};

template<>
struct is_service_response<gripper_interface::srv::Gripper_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // GRIPPER_INTERFACE__SRV__DETAIL__GRIPPER__TRAITS_HPP_
