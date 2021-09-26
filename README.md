# Home-Services-Robot
In this project, a mobile robot is asked to navigate to a pick-up zone for picking up a green cube. After that, it moves while carrying the cube to the drop-off zone position and drops the cube there.
# How-it-works
The mobile robot first drives around and scan the house using laser for generating a static map about this place. Having the map, it uses odometry and laser data to localize itself with adaptive monte carlo localization (AMCL). Upon receiving a navigation goal, it plans forward the trajectory using Dijkstra's algorithm and navigate to the goal.
# Description
The project consists of the following parts:

1- A Gazebo world and a mobile robot.
2- ROS packages: map_server, amcl, move_base, slam-gmapping and teleop_twist_keyboard.

# Prerequisites

   1- ROS (Melodic or Kinetic), Gazebo on Linux <br />
   2- CMake & g++/gcc, C++11 <br />
   3- Install xterm sudo apt-get install xterm <br /> 
   4- Python with pip ```sudo apt-get install python-pip``` <br /> 
   5- Install some dependencies <br />
   ```
$ sudo apt-get install ros-kinetic-turtlebot*
$ mkdir -p ~/catkin_ws/src
$ cd ~/catkin_ws/src
$ catkin_init_workspace
$ cd ..
$ catkin_make
$ sudo apt-get update
$ cd ~/catkin_ws/
$ source devel/setup.bash
$ rosdep -i install gmapping
$ rosdep -i install turtlebot_teleop
$ rosdep -i install turtlebot_rviz_launchers
$ rosdep -i install turtlebot_gazebo
$ catkin_make
$ source devel/setup.bash
```
# build and launch
```
$ cd ~/catkin_ws
$ chmod +x src/scripts/Home_Service_robot.sh\
$ ./src/scripts/Home_Service_robot.sh\
```
Note: To redraw the map, close all ros terminals and re-run the script test.sh instead. While all terminal is open, ```run rosrun map_server map_saver -f my_map```. Replace the ``map/SimpleMap`` files with the newly created ```my_map```.
# Package explaination
1- The turetlebot packages: <br />
The turtlebot meta package provides all the basic drivers for running and using a TurtleBot. <br />
2- the Gmapping package: <br />
This package contains a ROS wrapper for OpenSlam's Gmapping. The gmapping package provides laser-based SLAM (Simultaneous Localization and Mapping), as a ROS node called slam_gmapping. Using slam_gmapping, you can create a 2-D occupancy grid map (like a building floorplan) from laser and pose data collected by a mobile robot.<br /> 
3-AMCL package :<br /> 
 amcl is a probabilistic localization system for a robot moving in 2D. It implements the adaptive (or KLD-sampling) Monte Carlo localization approach (as described by Dieter Fox), which uses a particle filter to track the pose of a robot against a known map.
This node is derived, with thanks, from Andrew Howard's excellent 'amcl' Player driver.<br /> 
4-The add marker Package: <br />
the add marker package is used to add a shape like cube , cylinder ,etc in pickup point thats is specified in the code the after the robot reached pick it will disapear then apear in the dropoff zone . it use Visualziation and odometry msg , visulaization to add shapes and odometry msg to recieve and update robot position from the encoder. <br />
