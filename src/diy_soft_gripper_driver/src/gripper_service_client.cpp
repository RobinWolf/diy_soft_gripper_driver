#include "rclcpp/rclcpp.hpp"
#include "gripper_interface/srv/gripper.hpp"

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);

  if (argc != 2)
  {
    RCLCPP_ERROR(rclcpp::get_logger("gripper_control_client"), "Bitte geben Sie den Befehl (0 oder 1) als Argument ein.");
    return 1;
  }

  int cmd = std::stoi(argv[1]);
  if (cmd != 0 && cmd != 1)
  {
    RCLCPP_ERROR(rclcpp::get_logger("gripper_control_client"), "Ungültiger Befehl. Bitte geben Sie 0 oder 1 als Argument ein.");
    return 1;
  }

  auto client = rclcpp::Node::make_shared("gripper_control_client");
  auto grip_client = client->create_client<gripper_interface::srv::Gripper>("gripper_control");

  while (!grip_client->wait_for_service(std::chrono::seconds(1)))
  {
    RCLCPP_INFO(client->get_logger(), "Warte auf den Gripper-Service...");
  }

  auto request = std::make_shared<gripper_interface::srv::Gripper::Request>();
  request->cmd = cmd;

  // Senden des Service-Aufrufs
  auto result_future = grip_client->async_send_request(request);

  // Warte auf die Antwort
  if (rclcpp::spin_until_future_complete(client, result_future) !=
      rclcpp::FutureReturnCode::SUCCESS)
  {
    RCLCPP_ERROR(client->get_logger(), "Fehler beim Empfangen der Antwort vom Server.");
    return 1;
  }

  auto response = result_future.get();
  if (response->status)
  {
    RCLCPP_INFO(client->get_logger(), "Eingabe akzeptiert. Greifer %s", (cmd ? "schließen" : "öffnen"));
  }
  else
  {
    RCLCPP_ERROR(client->get_logger(), "Fehler beim Steuern des Greifers.");
    return 1;
  }

  rclcpp::shutdown();
  return 0;
}