#include "dta_local_server.hpp"

namespace DtaLocalServer {

    DtaLocalServer::DtaLocalServer(const ros::NodeHandle &nh, const ros::NodeHandle &nh_private, std::string node_name,int argc,char** argv):nh_(nh), nh_private_(nh_private),
    node_name(node_name)
    {

        initialize(argc,argv);
    }   


    void DtaLocalServer::initialize(int argc, char ** argv) {

        initSocket();

        // std::string robot_name=argv[1];
        std::string robot_name="Robot4";
        const char * robot_ID;

        // 处理robot1和robot11区别,把最后两个字符串变成数字
        if(robot_name.size()==6)
            robot_ID = robot_name.substr(robot_name.size() - 1).c_str();
        else if(robot_name.size()==7)
            robot_ID = robot_name.substr(robot_name.size() - 2).c_str();

        int robot_id=atoi(robot_ID);
        std::cout << "robot_id: " << robot_id << std::endl;
        allocation_sub = nh_.subscribe <allocation_common::allocation2terminal_info>
            ("Robot"+std::to_string(robot_id)+"/task_allocation/allocation2terminal_info_from_plan",MAXNUM_AGENT,&DtaLocalServer::callbackAllocationMsg,this);
  
      //  loop_timer_ = nh_.createTimer(ros::Duration(0.02), boost::bind(&DtaLocalServer::timerCb, this));

    }

    bool DtaLocalServer::initSocket() {
        //&remote_ip = "230.1.1.1";
        remote_port = 4702;
        //local_ip[32] = "192.168.43.6";
        local_port = 4502;

        this->UdpNetSocket =  socket(AF_INET, SOCK_DGRAM, 0);
        if(this->UdpNetSocket == -1){
            printf("socket fail\n");
            return false;
        } else{
            std::cout << "create UdpNetSocket succeed!" << std::endl;
        }
        
        socklen = sizeof(struct sockaddr_in);
 
	/* 设置对方的端口和IP信息 */
	memset(&peeraddr, 0, socklen);
	peeraddr.sin_family = AF_INET;
	peeraddr.sin_port = htons(remote_port);

	/* 注意这里设置的对方地址是指组播地址，而不是对方的实际IP地址 */
	if (inet_pton(AF_INET,remote_ip, &peeraddr.sin_addr) <= 0) {
		printf("wrong group address!\n");
		exit(0);
	}

 
	/* 设置自己的端口和IP信息 */
	memset(&myaddr, 0, socklen);
	myaddr.sin_family = AF_INET;
    myaddr.sin_port = htons(local_port);
 
	if (inet_pton(AF_INET, local_ip, &myaddr.sin_addr) <= 0) {
		printf("self ip address error!\n");
		exit(0);
	}

	/* 绑定自己的端口和IP信息到socket上 */
	if (bind(UdpNetSocket, (struct sockaddr *) &myaddr,sizeof(struct sockaddr_in)) == -1) {
		printf("Bind error\n");
		exit(0);
	}

        // this->UdpNetSocket =  socket(PF_INET, SOCK_DGRAM, 0);
        // if(this->UdpNetSocket == -1){
        //     printf("socket fail\n");
        //     return false;
        // } else{
        //     std::cout << "create UdpNetSocket succeed!" << std::endl;
        // }

        // int optval = 1;//这个值一定要设置，否则可能导致sendto()失败
        // setsockopt(this->UdpNetSocket, SOL_SOCKET, SO_BROADCAST | SO_REUSEADDR, &optval, sizeof(int));
        // memset(&remoteAddr, 0, sizeof(struct sockaddr_in));
        // this->remoteAddr.sin_family = AF_INET;
        // this->remoteAddr.sin_addr.s_addr = inet_addr("255.255.255.255");//此处可以设置为全网的广播地址，例如255.255.255.255
        // this->remoteAddr.sin_port = htons(4009);

        std::cout << "Listen the broadcast haved finished. " <<std::endl;

        return true;
    }

    void DtaLocalServer::callbackAllocationMsg(const allocation_common::allocation2terminal_info::ConstPtr& _msg){
        //robot_info"""
        std::cout<<"in the udp callback"<<std::endl;
        allocation_Data.robot_info.robot_ID=_msg->robot_info.robot_ID;
        allocation_Data.robot_info.isvalid=_msg->robot_info.isvalid;
        allocation_Data.robot_info.robot_mode=_msg->robot_info.robot_mode;
        allocation_Data.robot_info.robot_power=_msg->robot_info.robot_power;
        allocation_Data.robot_info.which_target=_msg->robot_info.which_target;
        allocation_Data.robot_info.which_task=_msg->robot_info.which_task;
        allocation_Data.robot_info.move_distance = _msg->robot_info.move_distance;
        allocation_Data.robot_info.isupdate = _msg->robot_info.isupdate;
        allocation_Data.robot_info.expect_pos.x = _msg->robot_info.expect_pos.position.x;
        allocation_Data.robot_info.expect_pos.y = _msg->robot_info.expect_pos.position.y;
        //task_info
        allocation_Data.task_info.task_ID=_msg->task_info.task_ID;
        allocation_Data.task_info.current_distance=_msg->task_info.current_distance;
        allocation_Data.task_info.iscomplete=_msg->task_info.iscomplete;
        allocation_Data.task_info.isexplored=_msg->task_info.isexplored;
        allocation_Data.task_info.istarget=_msg->task_info.istarget;
        allocation_Data.task_info.isallocated=_msg->task_info.isallocated;
        allocation_Data.task_info.known_power=_msg->task_info.known_power;
        allocation_Data.task_info.task_power=_msg->task_info.task_power;
        allocation_Data.task_info.isupdate=_msg->task_info.isupdate;

        std::cout << allocation_Data.robot_info.robot_ID;
        sendmsgs();
    }

    void DtaLocalServer::timerCb(){

        sendmsgs();
    }

    void DtaLocalServer::sendmsgs() {
        ///因为循环周期从原来的0.02s改为0.01s，所以隔一次发送。
        ROS_INFO("sending messages");
        //std::cout<<"terminal_Data"<<terminal_Data.size()<<std::endl;

        int len = sendData(&allocation_Data, sendbuf);

	ROS_INFO("len:%d",len);

        int sendBytes = sendto(this->UdpNetSocket, this->sendbuf, len, 0,
                           (struct sockaddr *)&peeraddr, sizeof(struct sockaddr));

        if(sendBytes == -1) {
            printf("sendto fail, errno=%d\n", errno);
        }

    }

    int DtaLocalServer::sendData(Allocation2TerminalMSG* data, char *buf) {

        ROS_INFO("send data to buf start.");

        int index = 0;        
        int size1 = sizeof(allocation_task_info);
        int size2 = sizeof(allocation_robot_info);
        int size = size1 + size2;
        memcpy(buf + index, data, size);

        index += size;
        // std::cout<<index<<std::endl;
        std::cout<<sizeof(buf)<<std::endl;
        return index;
    }

}



int main(int argc, char **argv) {

        std::string node_name = "dta_local_server_node";
        ros::init(argc, argv, node_name);
        ros::NodeHandle nh("");
        ros::NodeHandle nh_private("~");
        DtaLocalServer::DtaLocalServer sender(nh, nh_private, node_name, argc, argv);
        ROS_INFO("Initialized sender node.");
        ros::spin();
}
