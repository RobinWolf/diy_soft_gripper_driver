// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from gripper_interface:srv/Gripper.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "gripper_interface/srv/detail/gripper__rosidl_typesupport_introspection_c.h"
#include "gripper_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "gripper_interface/srv/detail/gripper__functions.h"
#include "gripper_interface/srv/detail/gripper__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void gripper_interface__srv__Gripper_Request__rosidl_typesupport_introspection_c__Gripper_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  gripper_interface__srv__Gripper_Request__init(message_memory);
}

void gripper_interface__srv__Gripper_Request__rosidl_typesupport_introspection_c__Gripper_Request_fini_function(void * message_memory)
{
  gripper_interface__srv__Gripper_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember gripper_interface__srv__Gripper_Request__rosidl_typesupport_introspection_c__Gripper_Request_message_member_array[1] = {
  {
    "cmd",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gripper_interface__srv__Gripper_Request, cmd),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers gripper_interface__srv__Gripper_Request__rosidl_typesupport_introspection_c__Gripper_Request_message_members = {
  "gripper_interface__srv",  // message namespace
  "Gripper_Request",  // message name
  1,  // number of fields
  sizeof(gripper_interface__srv__Gripper_Request),
  gripper_interface__srv__Gripper_Request__rosidl_typesupport_introspection_c__Gripper_Request_message_member_array,  // message members
  gripper_interface__srv__Gripper_Request__rosidl_typesupport_introspection_c__Gripper_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  gripper_interface__srv__Gripper_Request__rosidl_typesupport_introspection_c__Gripper_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t gripper_interface__srv__Gripper_Request__rosidl_typesupport_introspection_c__Gripper_Request_message_type_support_handle = {
  0,
  &gripper_interface__srv__Gripper_Request__rosidl_typesupport_introspection_c__Gripper_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_gripper_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, gripper_interface, srv, Gripper_Request)() {
  if (!gripper_interface__srv__Gripper_Request__rosidl_typesupport_introspection_c__Gripper_Request_message_type_support_handle.typesupport_identifier) {
    gripper_interface__srv__Gripper_Request__rosidl_typesupport_introspection_c__Gripper_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &gripper_interface__srv__Gripper_Request__rosidl_typesupport_introspection_c__Gripper_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "gripper_interface/srv/detail/gripper__rosidl_typesupport_introspection_c.h"
// already included above
// #include "gripper_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "gripper_interface/srv/detail/gripper__functions.h"
// already included above
// #include "gripper_interface/srv/detail/gripper__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void gripper_interface__srv__Gripper_Response__rosidl_typesupport_introspection_c__Gripper_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  gripper_interface__srv__Gripper_Response__init(message_memory);
}

void gripper_interface__srv__Gripper_Response__rosidl_typesupport_introspection_c__Gripper_Response_fini_function(void * message_memory)
{
  gripper_interface__srv__Gripper_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember gripper_interface__srv__Gripper_Response__rosidl_typesupport_introspection_c__Gripper_Response_message_member_array[1] = {
  {
    "status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gripper_interface__srv__Gripper_Response, status),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers gripper_interface__srv__Gripper_Response__rosidl_typesupport_introspection_c__Gripper_Response_message_members = {
  "gripper_interface__srv",  // message namespace
  "Gripper_Response",  // message name
  1,  // number of fields
  sizeof(gripper_interface__srv__Gripper_Response),
  gripper_interface__srv__Gripper_Response__rosidl_typesupport_introspection_c__Gripper_Response_message_member_array,  // message members
  gripper_interface__srv__Gripper_Response__rosidl_typesupport_introspection_c__Gripper_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  gripper_interface__srv__Gripper_Response__rosidl_typesupport_introspection_c__Gripper_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t gripper_interface__srv__Gripper_Response__rosidl_typesupport_introspection_c__Gripper_Response_message_type_support_handle = {
  0,
  &gripper_interface__srv__Gripper_Response__rosidl_typesupport_introspection_c__Gripper_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_gripper_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, gripper_interface, srv, Gripper_Response)() {
  if (!gripper_interface__srv__Gripper_Response__rosidl_typesupport_introspection_c__Gripper_Response_message_type_support_handle.typesupport_identifier) {
    gripper_interface__srv__Gripper_Response__rosidl_typesupport_introspection_c__Gripper_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &gripper_interface__srv__Gripper_Response__rosidl_typesupport_introspection_c__Gripper_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "gripper_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "gripper_interface/srv/detail/gripper__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers gripper_interface__srv__detail__gripper__rosidl_typesupport_introspection_c__Gripper_service_members = {
  "gripper_interface__srv",  // service namespace
  "Gripper",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // gripper_interface__srv__detail__gripper__rosidl_typesupport_introspection_c__Gripper_Request_message_type_support_handle,
  NULL  // response message
  // gripper_interface__srv__detail__gripper__rosidl_typesupport_introspection_c__Gripper_Response_message_type_support_handle
};

static rosidl_service_type_support_t gripper_interface__srv__detail__gripper__rosidl_typesupport_introspection_c__Gripper_service_type_support_handle = {
  0,
  &gripper_interface__srv__detail__gripper__rosidl_typesupport_introspection_c__Gripper_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, gripper_interface, srv, Gripper_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, gripper_interface, srv, Gripper_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_gripper_interface
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, gripper_interface, srv, Gripper)() {
  if (!gripper_interface__srv__detail__gripper__rosidl_typesupport_introspection_c__Gripper_service_type_support_handle.typesupport_identifier) {
    gripper_interface__srv__detail__gripper__rosidl_typesupport_introspection_c__Gripper_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)gripper_interface__srv__detail__gripper__rosidl_typesupport_introspection_c__Gripper_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, gripper_interface, srv, Gripper_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, gripper_interface, srv, Gripper_Response)()->data;
  }

  return &gripper_interface__srv__detail__gripper__rosidl_typesupport_introspection_c__Gripper_service_type_support_handle;
}