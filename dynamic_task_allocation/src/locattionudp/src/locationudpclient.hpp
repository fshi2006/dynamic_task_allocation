//
// Created by lizhiwei on 20-07-02.
//

#ifndef LOCATIONUDPCLIENT_HPP
#define LOCATIONUDPCLIENT_HPP

#define NUM_ROBOT 6
#define BUF_SIZE  2048

#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstring>
#include <arpa/inet.h>
#include <queue>
#include <stdio.h>
#include <chrono>
#include <string>
#include <vector>
#include <cstdlib>
#include <netdb.h>
#include <errno.h>
#include <stdlib.h>

//added for ros
#include <ros/ros.h>
#include "nav_msgs/Path.h"
#include "sensor_driver_msgs/GpswithHeading.h"
#include "multi_vehicle_msgs/Lo_Location.h"

#pragma pack(1)

typedef struct GPSMSG{

    double longitude;
    double latitude;
    double altitude;

    double heading;
    double roll;
    double pitch;

    double dlatitude;
    double dlongitude;
    double daltitude;
    int GNSS_status;

}GpsMsg;


using namespace std;

namespace locationudpclient {

    class locationudpclient {

    public:
        locationudpclient(const ros::NodeHandle &nh, const ros::NodeHandle &nh_private,
                 std::string node_name);

        // ros
        ros::NodeHandle nh_;
        ros::NodeHandle nh_private_;
        ros::Timer loop_timer_;
        std::string node_name;

        struct sockaddr_in peeraddr;
	    struct in_addr ia;
	    int sockfd;
	    unsigned int socklen, n;
	    struct hostent *group;
	    struct ip_mreq mreq;
	    int local_port;
	    char remote_ip[32] = "230.1.1.1" ;

         ros::Publisher pub_all_location;
        ros::Subscriber poses_self_sub;

        multi_vehicle_msgs::Lo_Location msg;

        //UDP
        struct robot_location
        {
            int ID;
            double robot_x;
            double robot_y;
        };
        
        int UdpNetSocket;

        // struct sockaddr_in recvAddr;

        void initialize();

        bool initSocket(void);

        void recvmsgs();

        // void timerCb();
        void robot_dymatic_listener_self_Callback(const sensor_driver_msgs::GpswithHeading msg);

        double path_elapse_time_;

        int recvData(GpsMsg* data, char* buf, int i);

        vector<robot_location> robot_location_all;

    private:

        GpsMsg gps_first;

        GpsMsg gps_second;

        GpsMsg gps_third;

        GpsMsg gps_forth;

        GpsMsg gps_fifth;

        GpsMsg gps_sixth;

        char recvbuf[BUF_SIZE];
    };
}//namespace acoplannerudp

#pragma pack()

#endif //ACOPLANNERUDP_HPP


