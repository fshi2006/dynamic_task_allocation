#include <algorithm>
#include <ros/package.h>
#include <ros/ros.h>
#include <fstream>
#include <iostream>
#include <iomanip>

#include <ros/callback_queue.h>
#include <ros/subscribe_options.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/Twist.h>
#include <nav_msgs/Path.h>
#include "sensor_driver_msgs/GpswithHeading.h"

#include <allocation_common/gazebo2world_info.h>
#include <allocation_common/gazebo_robot_info.h>
#include <allocation_common/gazebo_task_info.h>
#include <allocation_common/allocation_task_info.h>
#include <allocation_common/robot2gazebo_info.h>
#include <allocation_common/terminal2gazebo_info.h>
#include <Core.hpp>
#define MAXNUM_AGENT 50

class Poses_talker
{
    public:
    allocation_common::gazebo_robot_info    robots_info_;
    allocation_common::gazebo_task_info     tasks_info_;
    void init();
    void robot_dymatic_listener_Callback(const nav_msgs::Path &robot_location_list);
    ros::NodeHandle nh_;
    ros::Subscriber poses_sub;
    ros::Publisher  poses_pub; 
    ros::Subscriber poses_self_sub;
    allocation_common::gazebo2world_info _gazebo2world_info;
    void robot_dymatic_listener_self_Callback(const sensor_driver_msgs::GpswithHeading &msg);
};
