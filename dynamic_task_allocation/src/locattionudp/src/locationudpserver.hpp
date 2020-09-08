//
// Created by lizhiwei on 20-07-02.
//

#ifndef LOCATIONUDPSERVER_HPP
#define LOCATIONUDPSERVER_HPP

#define NUM_ROBOT 6
#define BUF_SIZE  2048

#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstring>
#include <arpa/inet.h>
#include <queue>
#include <chrono>
#include <string>
#include <vector>
#include <cstdlib>
//added for ros
#include <ros/ros.h>
#include "nav_msgs/Path.h"
#include "sensor_driver_msgs/GpswithHeading.h"


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

namespace locationudpserver {

    class locationudpserver {

    public:
        locationudpserver(const ros::NodeHandle &nh, const ros::NodeHandle &nh_private,
                 std::string node_name);

        // ros
        ros::NodeHandle nh_;
        ros::NodeHandle nh_private_;
        ros::Timer loop_timer_;
        std::string node_name;

        ros::Subscriber gps_sub;

        //UDP
        int UdpNetSocket;

        // struct sockaddr_in remoteAddr;

        struct sockaddr_in peeraddr, myaddr;
 
	    int sockfd;
 	    char remote_ip[32] = "230.1.1.1" ;
	    char local_ip[32] = "192.168.10.51";
	    int local_port;
	    int remote_port;
	    unsigned int socklen;

        void initialize();

        void callbackGpsmsgs(const sensor_driver_msgs::GpswithHeading msg);

        bool initSocket(void);

        void sendmsgs();

        void timerCb();

        double path_elapse_time_;

        int sendData(GpsMsg* data, char* buf);

    private:

        GpsMsg our_gps;

        char sendbuf[BUF_SIZE];


    };
}//namespace acoplannerudp

#pragma pack()

#endif //ACOPLANNERUDP_HPP


