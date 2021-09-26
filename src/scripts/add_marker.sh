#!/bin/sh
xterm -e "roslaunch turtlebot_gazebo turtlebot_world.launch"& 
sleep 3
xterm -e "roslaunch turtlebot_gazebo amcl_demo.launch" &
sleep 3
xterm -e "roslaunch turtlebot_rviz_launchers view_navigation.launch rviz_config_file:=$(pwd)/../rvizConfig/home_service.rviz" &
sleep 3 
xterm -e "rosrun add_markers add_markers_test " 
