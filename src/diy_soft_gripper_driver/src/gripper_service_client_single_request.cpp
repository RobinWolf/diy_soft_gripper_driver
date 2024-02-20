#include "rclcpp/rclcpp.hpp"
//#include "gripper_interface/srv/gripper.hpp"
#include "std_srvs/srv/set_bool.hpp"

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);

  if (argc < 2)
  {
    RCLCPP_ERROR(rclcpp::get_logger("gripper_control_client"), "Please provide the command (0 or 1) as an argument.");
    return 1;
  }

  int cmd = std::stoi(argv[1]);
  if (cmd != 0 && cmd != 1)
  {
    RCLCPP_ERROR(rclcpp::get_logger("gripper_control_client"), "Invalid command %d. Please provide 0 or 1 as an argument.", cmd);
    return 1;
  }

  auto client = rclcpp::Node::make_shared("gripper_control_client");
  auto grip_client = client->create_client<std_srvs::srv::SetBool>("gripper_control");

  while (!grip_client->wait_for_service(std::chrono::seconds(1)))
  {
    RCLCPP_INFO(client->get_logger(), "Waiting for the gripper service...");
  }

  auto request = std::make_shared<<std_srvs::srv::SetBool::Request>();
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

  rclcpp::shutdown();
  return 0;
}