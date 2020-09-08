//
// Created by lizhiwei on 20-07-02.
//

#ifndef DTALOCALSERVER_HPP
#define DTALOCALSERVER_HPP

#define BUF_SIZE  4096
// #define robot_id 1

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
#include "Core.hpp"
#include "nav_msgs/Path.h"
#include "allocation_common/allocation2terminal_info.h"
#include "allocation_common/allocation_task_info.h"
#include "allocation_common/allocation_robot_info.h"

using namespace std;


#pragma pack(1)

typedef struct Pose{
    float x;
    float y;
}_Pose;

typedef struct allocation_robot_info{
    int    robot_ID;
    char     robot_mode;
    int    which_task;
    int    which_target;
    Pose     expect_pos;
    bool     isvalid;

    int    robot_power;
    float  move_distance;
    bool     isupdate;
}_allocation_robot_info;

typedef struct allocation_task_info{
    int    task_ID;
    int    known_power;
    float  current_distance;
    bool     istarget;
    bool     iscomplete;
    bool     isexplored;
    bool     isallocated;

    int    task_power;
    bool     isupdate;
}_allocation_task_info;

typedef struct Allocation2TerminalMSG{
    allocation_robot_info  robot_info;
    allocation_task_info task_info;
}_Allocation2TerminalMSG;

namespace DtaLocalServer {

    class DtaLocalServer {

    public:
        DtaLocalServer(const ros::NodeHandle &nh, const ros::NodeHandle &nh_private,
                 std::string node_name,int argc,char** argv);

        // ros
        ros::NodeHandle nh_;
        ros::NodeHandle nh_private_;
        ros::Timer loop_timer_;
        std::string node_name;

        ros::Subscriber allocation_sub;

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

        void initialize(int argc,char** argv);

        void callbackAllocationMsg(const allocation_common::allocation2terminal_info::ConstPtr& _msg);

        bool initSocket(void);

        void sendmsgs();

        void timerCb();

        int sendData(Allocation2TerminalMSG* data, char* buf);

    private:

        Allocation2TerminalMSG allocation_Data;

        char sendbuf[BUF_SIZE];

    };
}//namespace DtaLocalServer

#pragma pack()

#endif //DTALOCALSERVER_HPP


