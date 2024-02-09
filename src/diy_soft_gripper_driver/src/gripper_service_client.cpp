#include "rclcpp/rclcpp.hpp"
#include "gripper_interface/srv/gripper.hpp"

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);

  if (argc != 2)
  {
    RCLCPP_ERROR(rclcpp::get_logger("gripper_control_client"), "please pass 0 (open) od 1 (close)");
    return 1;
  }

  int cmd = std::stoi(argv[1]);
  if (cmd != 0 && cmd != 1)
  {
    RCLCPP_ERROR(rclcpp::get_logger("gripper_control_client"), "invalid input argument - please pass 0 (open) od 1 (close)");
    return 1;
  }

  auto client = rclcpp::Node::make_shared("gripper_control_client");
  auto grip_client = client->create_client<gripper_interface::srv::Gripper>("gripper_control"); //imports the service interfaces from the gripper_interface packages

  while (!grip_client->wait_for_service(std::chrono::seconds(1)))
  {
    RCLCPP_INFO(client->get_logger(), "Wait for gripper service inztialization...");
  }

  auto request = std::make_shared<gripper_interface::srv::Gripper::Request>();  //imports the request definition from the srv file in gripper_interface package
  request->cmd = cmd;

  // send the service call from the cilient to the server
  auto result_future = grip_client->async_send_request(request);

  // wait for answer from the service server node
  if (rclcpp::spin_until_future_complete(client, result_future) !=
      rclcpp::FutureReturnCode::SUCCESS)
  {
    RCLCPP_ERROR(client->get_logger(), "ERROR recieved no answer from the server.");
    return 1;
  }

  auto response = result_future.get();
  if (response->status)
  {
    RCLCPP_INFO(client->get_logger(), "input correct. gripper %s", (cmd ? "close" : "open"));
  }
  else
  {
    RCLCPP_ERROR(client->get_logger(), "ERROR while controlling the gripper.");
    return 1;
  }

  rclcpp::shutdown();
  return 0;
}