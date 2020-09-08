

#ifndef LOCATIONUDPSERVER_HPP
#define LOCATIONUDPSERVER_HPP

#define BUF_SIZE  4096

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
#include "Core.hpp"
//added for ros
#include <ros/ros.h>
#include "nav_msgs/Path.h"
#include "allocation_common/terminal2robot_info.h"
#include "allocation_common/allocation_robot_info.h"
#include "allocation_common/allocation_task_info.h"

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

typedef struct Terminal2RobotMSG{

    char allocation_mode;
    bool greedorprobability;
    char allocation_method;

    int    robot_ID[MAXNUM_AGENT];
    char     robot_mode[MAXNUM_AGENT];
    int    which_task[MAXNUM_AGENT];
    int    which_target[MAXNUM_AGENT];
    float     expect_posx[MAXNUM_AGENT];
    float     expect_posy[MAXNUM_AGENT];
    bool     isvalid[MAXNUM_AGENT];
    int    robot_power[MAXNUM_AGENT];
    float  move_distance[MAXNUM_AGENT];
    bool     robot_isupdate[MAXNUM_AGENT];

    int    task_ID[MAXNUM_TASK];
    int    known_power[MAXNUM_TASK];
    float  current_distance[MAXNUM_TASK];
    bool     istarget[MAXNUM_TASK];
    bool     iscomplete[MAXNUM_TASK];
    bool     isexplored[MAXNUM_TASK];
    bool     isallocated[MAXNUM_TASK];
    int    task_power[MAXNUM_TASK];
    bool     task_isupdate[MAXNUM_TASK];

    // vector<allocation_robot_info> all_allocation_robot_info;
    // vector<allocation_task_info> all_allocation_task_info ; 
}_Terminal2RobotMSG;

namespace DtaTerminalServer {

    class DtaTerminalServer {

    public:
        DtaTerminalServer(const ros::NodeHandle &nh, const ros::NodeHandle &nh_private,
                 std::string node_name);

        // ros
        ros::NodeHandle nh_;
        ros::NodeHandle nh_private_;
        ros::Timer loop_timer_;
        std::string node_name;

        allocation_robot_info _robot_info_tmp;
        allocation_task_info _task_info_tmp;
        
        ros::Subscriber terminal_sub;

        //UDP
        int UdpNetSocket;

        // struct sockaddr_in remoteAddr;

        struct sockaddr_in peeraddr, myaddr;
	    int sockfd;
 	    char remote_ip[32] = "230.1.1.1" ;
	    char local_ip[32] = "192.168.43.6";
	    int local_port;
	    int remote_port;
	    unsigned int socklen;

        void initialize();

        void callbackTerminalMsg(const allocation_common::terminal2robot_info::ConstPtr& _msg);

        bool initSocket(void);

        void sendmsgs();

        void timerCb();

        int sendData(Terminal2RobotMSG* data, char* buf);

    private:

        Terminal2RobotMSG terminal_Data;

        char sendbuf[BUF_SIZE];

    };
}//namespace DtaTerminalServer

#pragma pack()

#endif //LOCATIONUDPSERVER_HPP


