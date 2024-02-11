# diy_soft_gripper_driver

This ROS2 package contains a driver to communicate to a hardware component based on an ESP32 microcontroller.
The ESP32 will be connected via TCP-IP over a local Hotspot.

This Package contains to the whole DIY-Robotics series, please refer to the main repo.



## Commands for using the service server and client:
1. navigate to the ros2_ws with cd ...
2. ./run_dev.sh
3. colcon build
4. source install/setup.bash
5. ros2 run diy_soft_gripper_driver server <IP-Adress> <Port> (e.g.: ros2 run diy_soft_gripper_driver server 192.168.212.202 80)
6. Open second Terminal
7. docker ps --> find out the ID of the docker container  
8. docker exec -it <Container ID> bash 
9. ros2 run diy_soft_gripper_driver client <0 to open, 1 to close the gripper>