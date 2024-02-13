#include "rclcpp/rclcpp.hpp"
#include "gripper_interface/srv/gripper.hpp"
#include <iostream>

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);

  if (argc != 1 && std::string(argv[1]) != "--ros-args")    // (--ros-args seems to automatically added by ROS2 when using ros2 launch)
  {
    RCLCPP_ERROR(
        rclcpp::get_logger("gripper_control_client"),
        "This client does not expect any arguments, but received: %s", argv[1]);
    return 1;
  }

  auto client = rclcpp::Node::make_shared("gripper_control_client");
  auto grip_client = client->create_client<gripper_interface::srv::Gripper>("gripper_control");

  while (!grip_client->wait_for_service(std::chrono::seconds(1)))
  {
    RCLCPP_INFO(client->get_logger(), "Waiting for the gripper service...");
  }

  rclcpp::Rate rate(10);  // Adjust the rate as needed

  while (rclcpp::ok())
  {
    std::cout << "Please enter the command (0 or 1) ('q' to quit): ";
    std::string input;
    std::getline(std::cin, input);

    if (input == "q")
    {
      break;
    }

    try
    {
      int cmd = std::stoi(input);
      if (cmd != 0 && cmd != 1)
      {
        RCLCPP_ERROR(client->get_logger(), "Invalid command. Please enter 0 or 1 as an argument.");
        continue;
      }

      auto request = std::make_shared<gripper_interface::srv::Gripper::Request>();
      request->cmd = cmd;

      // Send the service call
      auto result_future = grip_client->async_send_request(request);

      // Wait for the response
      if (rclcpp::spin_until_future_complete(client, result_future) !=
          rclcpp::FutureReturnCode::SUCCESS)
      {
        RCLCPP_ERROR(client->get_logger(), "Error receiving response from the server.");
        return 1;
      }

      auto response = result_future.get();
      if (response->status)
      {
        RCLCPP_INFO(client->get_logger(), "Input accepted. Gripper %s", (cmd ? "close" : "open"));
      }
      else
      {
        RCLCPP_ERROR(client->get_logger(), "Error controlling the gripper.");
        return 1;
      }
    }
    catch (const std::invalid_argument &e)
    {
      RCLCPP_ERROR(client->get_logger(), "Invalid input. Please enter 0 or 1 as an argument.");
    }

    rate.sleep();
  }

  rclcpp::shutdown();
  return 0;
}