#include <ros/ros.h>
#include <ros/package.h>
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <stdlib.h>
#include <string>
#include "sensor_driver_msgs/GpswithHeading.h"

int main(int argc, char **argv)
{
	ros::init(argc,argv,"gps_talker");
	ros::NodeHandle n;
	ros::Publisher pub = n.advertise<sensor_driver_msgs::GpswithHeading>("bigrobot5/gpsdata_UTM",1);
	
	ros::Rate loop_rate(10);


	while (ros::ok())
	{
		sensor_driver_msgs::GpswithHeading msg;
		msg.gps.latitude = 150+4176230.5936185;
		msg.gps.longitude = 150+147993.2398021;
		// msg.heading = "gps";
	
		pub.publish(msg);
		std::cout << msg << std::endl;
		
		loop_rate.sleep();
		ros::spinOnce();
	}
	
}
