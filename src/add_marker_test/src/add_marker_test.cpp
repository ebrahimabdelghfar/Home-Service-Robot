#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
int main( int argc, char** argv )
{
  ros::init(argc, argv, "add_marker_test");
  ros::NodeHandle n;
  ros::Rate rate(20);
  ros::Publisher cube_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);
  bool picked = false;
  float pickx=14.0;
  float picky=-0.2;
  float dropx=14.0;
  float dropy=-1.0;
  visualization_msgs::Marker cube;
  // Set the frame ID and timestamp.  See the TF tutorials for information on these.
  cube.header.frame_id = "map";
  cube.header.stamp = ros::Time::now();

  // Set the namespace and id for this marker.  This serves to create a unique ID
  // Any marker sent with the same namespace and id will overwrite the old one
  cube.ns = "add_marker_test";
  cube.id = 0;

  // Set the marker type.  Initially this is CUBE, and cycles between that and SPHERE, ARROW, and CYLINDER
  cube.type = visualization_msgs::Marker::CUBE;

  // Set the size of the marker 
  cube.scale.x = 0.2;
  cube.scale.y = 0.2;
  cube.scale.z = 0.2;
  // Set the color
  cube.color.r = 0.0f;
  cube.color.g = 0.0f;
  cube.color.b = 1.0f;
  cube.color.a = 1.0;

  cube.lifetime = ros::Duration();

  while (ros::ok())
  {
	    cube.action = visualization_msgs::Marker::ADD;
            cube.pose.position.x = pickx;
            cube.pose.position.y = picky;
            cube.pose.orientation.z = 0;
	    cube_pub.publish(cube);
	    ros::Duration(5.0).sleep();
        cube.action = visualization_msgs::Marker::DELETE;
            cube_pub.publish(cube);
            ros::Duration(5.0).sleep();
            cube.action = visualization_msgs::Marker::ADD;
            cube.pose.position.x = dropx-pickx;
            cube.pose.position.y = dropy-picky;
            cube.pose.orientation.z = 0;
            cube_pub.publish(cube);
            ros::Duration(5.0).sleep();
    ros::spinOnce();
    rate.sleep();
    }
    return 0;
}
