cmake_minimum_required(VERSION 3.8)
project(diy_soft_gripper_driver)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rosidl_default_generators REQUIRED)


#generate service interface header from srv config file (generate the new custom message for the service)
rosidl_generate_interfaces(${PROJECT_NAME}
  srv/gripper.srv
)

#Build the service server
add_executable(server src/gripper_service_server.cpp)
ament_target_dependencies(server rclcpp ${PROJECT_NAME}_rosidl_typesupport_cpp)

#Build the service client
add_executable(client src/gripper_service_client.cpp)
ament_target_dependencies(client rclcpp ${PROJECT_NAME}_rosidl_typesupport_cpp)


if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()


#INSTALL executables (e.g. server and client)
install(TARGETS
  server
  client
  DESTINATION lib/${PROJECT_NAME})

 #INSTALL directories to specific destination 
install(
    DIRECTORY include/
    DESTINATION include
  )
install(DIRECTORY
    srv
    DESTINATION share/${PROJECT_NAME}/srv
  )

ament_package()
