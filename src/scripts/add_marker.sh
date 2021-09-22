#!/bin/sh

# launch turtlebot_world.launch to deploy turtlebot environment
xterm -e "export ROBOT_INITIAL_POSE='-x -5 -y -2 -z 0 -R 0 -P 0 -Y 0';
roslaunch turtlebot_gazebo turtlebot_world.launch"& 

sleep 5

# launch amcl_demo.launch for localization
xterm -e "roslaunch turtlebot_gazebo amcl_demo.launch" &

sleep 5
xterm -e "roslaunch add_markers home_service_rviz_config.launch rviz_config_file:=$(pwd)/../rvizConfig/robot.rviz" &

sleep 20 # keeping large to enable visualization

# launch add_markers node
xterm -e "rosrun add_markers add_markers_test " &
