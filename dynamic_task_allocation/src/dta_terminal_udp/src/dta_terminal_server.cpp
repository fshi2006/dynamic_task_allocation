#include "dta_terminal_server.hpp"

namespace DtaTerminalServer {

    DtaTerminalServer::DtaTerminalServer(const ros::NodeHandle &nh, const ros::NodeHandle &nh_private, std::string node_name):nh_(nh), nh_private_(nh_private),
    node_name(node_name)
    {

        initialize();
    }

    void DtaTerminalServer::initialize() {

        initSocket();

        terminal_sub = nh_.subscribe("/topic_info_talker/terminal2robot_info", 1, &DtaTerminalServer::callbackTerminalMsg, this);

        loop_timer_ = nh_.createTimer(ros::Duration(0.05), boost::bind(&DtaTerminalServer::timerCb, this));

    }

    bool DtaTerminalServer::initSocket() {
        //&remote_ip = "230.1.1.1";
        remote_port = 4703;
        //local_ip[32] = "192.168.43.6";
        local_port = 4103;

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
        // this->remoteAddr.sin_port = htons(4002);

        std::cout << "Listen the broadcast haved finished. " <<std::endl;

        return true;
    }

    void DtaTerminalServer::callbackTerminalMsg(const allocation_common::terminal2robot_info::ConstPtr& _msg){

        // terminal_Data.all_allocation_robot_info.clear();
        // terminal_Data.all_allocation_task_info.clear();
        // terminal_Data.all_allocation_robot_info.resize(_msg->all_allocation_robot_info.size());
        // terminal_Data.all_allocation_task_info.resize(_msg->all_allocation_task_info.size());
  
        this->terminal_Data.allocation_mode = _msg->allocation_mode;
        this->terminal_Data.greedorprobability = _msg->greedorprobability;
        this->terminal_Data.allocation_method = _msg->allocation_method; 

        // allocation_robot_info _robot_info_tmp;
        
        for(unsigned int i=0;i<_msg->all_allocation_robot_info.size();i++){
            terminal_Data.robot_ID[i]=_msg->all_allocation_robot_info[i].robot_ID;
            terminal_Data.isvalid[i]=_msg->all_allocation_robot_info[i].isvalid;
            terminal_Data.robot_mode[i]=_msg->all_allocation_robot_info[i].robot_mode;
            terminal_Data.robot_power[i]=_msg->all_allocation_robot_info[i].robot_power;
            terminal_Data.which_target[i]=_msg->all_allocation_robot_info[i].which_target;
            terminal_Data.which_task[i]=_msg->all_allocation_robot_info[i].which_task;
            terminal_Data.move_distance[i] = _msg->all_allocation_robot_info[i].move_distance;
            terminal_Data.robot_isupdate[i] = _msg->all_allocation_robot_info[i].isupdate;
            terminal_Data.expect_posx[i] = _msg->all_allocation_robot_info[i].expect_pos.position.x;
            terminal_Data.expect_posy[i] = _msg->all_allocation_robot_info[i].expect_pos.position.y;
            //this->terminal_Data.all_allocation_robot_info[i] =_robot_info_tmp;
        }
       // allocation_task_info _task_info_tmp;
        for(unsigned int j=0;j<_msg->all_allocation_task_info.size();j++){
            terminal_Data.task_ID[j]=_msg->all_allocation_task_info[j].task_ID;
            terminal_Data.current_distance[j] =_msg->all_allocation_task_info[j].current_distance;
            terminal_Data.iscomplete[j] =_msg->all_allocation_task_info[j].iscomplete;
            terminal_Data.isexplored[j] =_msg->all_allocation_task_info[j].isexplored;
            terminal_Data.istarget[j] =_msg->all_allocation_task_info[j].istarget;
            terminal_Data.isallocated[j] =_msg->all_allocation_task_info[j].isallocated;
            terminal_Data.known_power[j] =_msg->all_allocation_task_info[j].known_power;
            terminal_Data.task_power[j] =_msg->all_allocation_task_info[j].task_power;
            terminal_Data.task_isupdate[j] =_msg->all_allocation_task_info[j].isupdate;
         //   this->terminal_Data.all_allocation_task_info[j] =_task_info_tmp;
        }
        // sendmsgs();
    }

    void DtaTerminalServer::timerCb(){

        sendmsgs();
    }

    void DtaTerminalServer::sendmsgs() {
        ///因为循环周期从原来的0.02s改为0.01s，所以隔一次发送。
        ROS_INFO("sending messages");

        int len = sendData(&terminal_Data, sendbuf);

        int sendBytes = sendto(this->UdpNetSocket, this->sendbuf, len, 0,
                           (struct sockaddr *)&peeraddr, sizeof(struct sockaddr));

        if(sendBytes == -1) {
            printf("sendto fail, errno=%d\n", errno);
        }

    }

    int DtaTerminalServer::sendData(Terminal2RobotMSG* data, char *buf) {

        ROS_INFO("send data to buf start.");

        int index = 0;
        int size = sizeof(Terminal2RobotMSG);


        // for(int i=0;i<MAXNUM_AGENT;i++){
        //     std::cout<<"robot_id: "<<data->robot_ID[i]<<std::endl;
        // }
        // for(int i=0;i<MAXNUM_TASK;i++){
        //     std::cout<<"task_id: "<<data->task_ID[i]<<std::endl;
        // }

        memcpy(buf, data, size);
        std::cout<<"sizeof(Terminal2RobotMSG)"<<size<<"sizeof(buf)"<<sizeof(buf)<<std::endl;
        
        index=size;
        return index;
    }

}



int main(int argc, char **argv) {

        std::string node_name = "dta_terminal_server_node";
        ros::init(argc, argv, node_name);
        ros::NodeHandle nh("");
        ros::NodeHandle nh_private("~");
        DtaTerminalServer::DtaTerminalServer sender(nh, nh_private, node_name);
        ROS_INFO("Initialized sender node.");
        ros::spin();
}
