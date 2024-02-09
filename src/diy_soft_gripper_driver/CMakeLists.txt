cmake_minimum_required(VERSION 3.8)
project(diy_soft_gripper_driver)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

find_package(gripper_interface REQUIRED) #this package is also in this container and defines the service with its messages (they are requested and responsed by the client and server node)


#Build the service server
add_executable(server src/gripper_service_server.cpp)
ament_target_dependencies(server rclcpp gripper_interface) 

#Build the service client
add_executable(client src/gripper_service_client.cpp)
ament_target_dependencies(client rclcpp gripper_interface)


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
  DESTINATION lib
)

#INSTALL directories to specific destination (only include for the used headers)
install(
    DIRECTORY include/
    DESTINATION include
)

install(
    DIRECTORY include
    DESTINATION include
)

#EXPORT include directory
include_directories(include)

ament_export_include_directories(
  include
)
  
ament_package()
