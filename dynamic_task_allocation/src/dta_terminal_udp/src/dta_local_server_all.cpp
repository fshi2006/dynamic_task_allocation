#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <signal.h>
#include <time.h>
#include <ros/ros.h>
using namespace std;

int main(int argc, char **argv){
    ros::init(argc, argv, "all_dta_local_server_node");
    ros::NodeHandle nh_;
    nh_.setParam("/control_terminal/robots_num", 50);


    bool is_robot_exsit_ =false;
    if(is_robot_exsit_)
        return true;
    else
    {
        is_robot_exsit_=true;
        ROS_INFO("allocation_local all start");
        FILE *fp = NULL;

        fp = popen("/home/luyaomin/catkin_planning/1dynamic_task_allocation/src/allocation_local.sh","w");
        if(fp == NULL)
            return false;
        pclose(fp);
        return true;
    }
}

