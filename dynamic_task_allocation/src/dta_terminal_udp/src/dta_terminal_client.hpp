
#ifndef DTATERMINALCLIENT_HPP
#define DTATERMINALCLIENT_HPP

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
#include <Core.hpp>
#include <netdb.h>
#include <errno.h>
#include <stdlib.h>
//added for ros
#include <ros/ros.h>
#include "nav_msgs/Path.h"
#include "allocation_common/allocation2terminal_info.h"
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
    char   robot_mode;
    int    which_task;
    int    which_target;
    Pose   expect_pos;
    bool   isvalid;

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

namespace DtaTerminalClient {

    class DtaTerminalClient {

    public:
        DtaTerminalClient(const ros::NodeHandle &nh, const ros::NodeHandle &nh_private,
                 std::string node_name);

        // ros
        ros::NodeHandle nh_;
        ros::NodeHandle nh_private_;
        ros::Timer loop_timer_;
        std::string node_name;

        ros::Publisher allocation_pub0,allocation_pub1,allocation_pub2,allocation_pub3,allocation_pub4,allocation_pub5;
        allocation_common::allocation2terminal_info allocation_pub_info_;

        //UDP
        int UdpNetSocket;

        // struct sockaddr_in recvAddr;

        struct sockaddr_in peeraddr;
	    struct in_addr ia;
	    int sockfd;
	    unsigned int socklen, n;
	    struct hostent *group;
	    struct ip_mreq mreq;
	    int local_port;
	    char remote_ip[32] = "230.1.1.1" ;

        void initialize();

        bool initSocket(void);

        void recvmsgs();

        void timerCb();

        int recvData(Allocation2TerminalMSG* data, char* buf, int i);
        int count;

        // string robot_name = "/0";

        

    private:

        Allocation2TerminalMSG allocation_Data;

        char recvbuf[BUF_SIZE];

    };
}//namespace DtaTerminalClient

#pragma pack()

#endif //DTATERMINALCLIENT_HPP


