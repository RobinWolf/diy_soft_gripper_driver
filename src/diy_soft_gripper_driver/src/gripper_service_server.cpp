#include "rclcpp/rclcpp.hpp"
#include "gripper_interface/srv/gripper.hpp"
#include "diy_soft_gripper_driver/RobotConnection.hpp"

class GripperControlServer : public rclcpp::Node
{
public:
  GripperControlServer(const std::string& gripper_ip_adress)
      : Node("gripper_control_server"), robotConnection()
  {
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Server Initializing...");

    // Attempt to connect to the gripper
    uint8_t gripper_port = 80;

    std::string errorMessage;
    if (robotConnection.initialize(gripper_ip_adress, "", errorMessage))
    {
      RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Successfully connected to the gripper at %s:%d", gripper_ip_adress.c_str(), gripper_port);
    }
    else
    {
      RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Failed to connect to the gripper at %s:%d", gripper_ip_adress.c_str(), gripper_port);
      rclcpp::shutdown();
      return;
    }

    // Service-Callback for gripper server (connects to the interface defined in the gripper_srv_interface package)
    auto grip_cb = [this](const std::shared_ptr<gripper_interface::srv::Gripper::Request> request,          //import the request and control interfaces from the srv in gripper_interface package
                          std::shared_ptr<gripper_interface::srv::Gripper::Response> response) -> void {

      RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Incoming request cmd: %d", request->cmd);

      if (request->cmd == 0 || request->cmd == 1)
      {
        robotConnection.cmd_gripper = request->cmd;

        if (!robotConnection.sendData())
        {
          RCLCPP_ERROR(this->get_logger(), "ERROR sending data to the robot.");
          response->status = false;
        }

        // Wait for the robot's response
        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        if (!robotConnection.readData())
        {
          RCLCPP_ERROR(this->get_logger(), "ERROR receiving data from the robot.");
          response->status = false;
        }
        else
        {
          response->status = true;
        }
      }
      else
      {
        RCLCPP_ERROR(this->get_logger(), "Invalid input. Please enter 0 or 1.");
        response->status = false;
      }
    };

    // build the gripper-service
    gripper_service_ = create_service<gripper_interface::srv::Gripper>("gripper_control", grip_cb);

    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Gripper Control Server Ready");
  }

private:
  RobotConnection robotConnection;
  rclcpp::Service<gripper_interface::srv::Gripper>::SharedPtr gripper_service_;
};

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);

  if (argc < 3) {
    RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Usage: %s <gripper_ip_adress> <gripper_port>", argv[0]);
    return 1;
  }

  std::string gripper_ip_adress = argv[1];
  uint8_t gripper_port = std::atoi(argv[2]);

  auto gripper_control_server = std::make_shared<GripperControlServer>(gripper_ip_adress, gripper_port);

  rclcpp::spin(gripper_control_server);
  rclcpp::shutdown();

  return 0;
}