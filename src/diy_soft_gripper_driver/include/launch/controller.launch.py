from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, RegisterEventHandler
from launch.event_handlers import OnProcessExit
from launch.substitutions import Command, FindExecutable, PathJoinSubstitution, LaunchConfiguration

from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
from launch_ros.descriptions import ParameterValue
from launch.conditions import IfCondition


def generate_launch_description():

#declare launch arguments (can be passed in the command line while launching)
    declared_arguments = []

    declared_arguments.append(
        DeclareLaunchArgument(
            "gripper_ip",
            default_value='"192.168.212.202"',
            description="The IP-Adress with which the gripper hardware joins the common network",
        )
    )  
    declared_arguments.append(
        DeclareLaunchArgument(
            "gripper_ssid",
            default_value='"DIY-Robotics"',
            description="The SSID from the common network (PC and ESP must be member of this network)",
        )
    )


    gripper_ip = LaunchConfiguration("gripper_ip")
    gripper_ssid = LaunchConfiguration("gripper_ssid")



#define the nodes to launch 
    #Server
    server_node= Node(
        package='diy_soft_gripper_driver',
        executable='gripper_service_server.py',
        parameters=[{'gripper_IP_adress': gripper_ip}] 
    )
    #Client
    client_node= Node(
        package='diy_soft_gripper_driver',
        executable='gripper_service_client.py',
    )

    nodes_to_start = [
        server_node,
        client_node,
    ]

    return LaunchDescription(declared_arguments + nodes_to_start)