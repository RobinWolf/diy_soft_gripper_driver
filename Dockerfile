##############################################################################
##                           1. stage: Base Image                           ##
##############################################################################
ARG ROS_DISTRO=humble
FROM osrf/ros:$ROS_DISTRO-desktop as base

# Configure DDS
COPY dds_profile.xml /opt/misc/dds_profile.xml
ENV FASTRTPS_DEFAULT_PROFILES_FILE=/opt/misc/dds_profile.xml

# Create user
ARG USER=hephaestus
ARG PASSWORD=automaton
ARG UID=1000
ARG GID=1000
ENV USER=$USER
RUN groupadd -g $GID $USER \
    && useradd -m -u $UID -g $GID -p "$(openssl passwd -1 $PASSWORD)" \
    --shell $(which bash) $USER -G sudo

#install additional necessarity packages
USER root
RUN apt-get update && apt-get install -y ros-$ROS_DISTRO-rclcpp
RUN apt-get update && apt-get install -y ros-$ROS_DISTRO-rosidl-default-generators
RUN apt-get update && apt-get install -y ros-$ROS_DISTRO-std-srvs
USER ${USER}

# Setup workpace
USER $USER
RUN mkdir -p /home/$USER/ros2_ws/src
WORKDIR /home/$USER/ros2_ws