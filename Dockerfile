##############################################################################
##                           1. stage: Base Image                           ##
##############################################################################
ARG ROS_DISTRO=humble
FROM osrf/ros:$ROS_DISTRO-desktop as base

# Configure DDS
COPY dds_profile.xml /opt/misc/dds_profile.xml
ENV FASTRTPS_DEFAULT_PROFILES_FILE=/opt/misc/dds_profile.xml

# Create user (for deployment container without root privileges)
ARG USER=hephaestus
ARG PASSWORD=automaton
ARG UID=1000
ARG GID=1000
ENV USER=$USER
RUN groupadd -g $GID $USER \
    && useradd -m -u $UID -g $GID --shell $(which bash) $USER   


# Setup workpace
USER $USER
RUN mkdir -p /home/$USER/ros2_ws/src
WORKDIR /home/$USER/ros2_ws

##############################################################################
##          2. stage: clone the gripper-driver repo from github             ##
##############################################################################
FROM base as diy-gripper-driver

# Install git to clone diy-soft-gripper-description packages
USER root
RUN apt-get update && apt-get install --no-install-recommends -y git
USER $USER

# Clone the diy-soft-gripper-driver package into its own workspace
RUN mkdir -p /home/$USER/dependencies/diy_soft_gripper_driver_ws/src
RUN cd /home/$USER/dependencies/diy_soft_gripper_driver_ws/src && \
    git clone https://github.com/RobinWolf/diy_soft_gripper_driver.git


#install additional necessarity packages
USER root
RUN apt-get update && apt-get install -y ros-$ROS_DISTRO-rclcpp
RUN apt-get update && apt-get install -y ros-$ROS_DISTRO-rosidl-default-generators
RUN apt-get update && apt-get install -y ros-$ROS_DISTRO-std-srvs
USER ${USER}


# Build the diy-gripper package
RUN cd /home/$USER/dependencies/diy_soft_gripper_driver_ws && \
    . /opt/ros/$ROS_DISTRO/setup.sh && \
    colcon build


# Add built diy-gripper package to entrypoint
USER root
RUN sed -i 's|exec "\$@"|source "/home/'"${USER}"'/dependencies/diy_soft_gripper_driver_ws/install/setup.bash"\n&|' /ros_entrypoint.sh
USER $USER