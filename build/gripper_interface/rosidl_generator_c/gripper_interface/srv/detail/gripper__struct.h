// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from gripper_interface:srv/Gripper.idl
// generated code does not contain a copyright notice

#ifndef GRIPPER_INTERFACE__SRV__DETAIL__GRIPPER__STRUCT_H_
#define GRIPPER_INTERFACE__SRV__DETAIL__GRIPPER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/Gripper in the package gripper_interface.
typedef struct gripper_interface__srv__Gripper_Request
{
  bool cmd;
} gripper_interface__srv__Gripper_Request;

// Struct for a sequence of gripper_interface__srv__Gripper_Request.
typedef struct gripper_interface__srv__Gripper_Request__Sequence
{
  gripper_interface__srv__Gripper_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} gripper_interface__srv__Gripper_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/Gripper in the package gripper_interface.
typedef struct gripper_interface__srv__Gripper_Response
{
  bool status;
} gripper_interface__srv__Gripper_Response;

// Struct for a sequence of gripper_interface__srv__Gripper_Response.
typedef struct gripper_interface__srv__Gripper_Response__Sequence
{
  gripper_interface__srv__Gripper_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} gripper_interface__srv__Gripper_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // GRIPPER_INTERFACE__SRV__DETAIL__GRIPPER__STRUCT_H_
