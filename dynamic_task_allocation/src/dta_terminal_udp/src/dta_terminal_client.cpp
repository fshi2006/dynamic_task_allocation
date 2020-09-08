#include "dta_terminal_client.hpp"

namespace DtaTerminalClient {

    DtaTerminalClient::DtaTerminalClient(const ros::NodeHandle &nh, const ros::NodeHandle &nh_private, std::string node_name):nh_(nh), nh_private_(nh_private),
    node_name(node_name)
    {

        initialize();

    }

    void DtaTerminalClient::initialize() {
    allocation_pub0 = nh_.advertise<allocation_common::allocation2terminal_info>("Robot0/task_allocation/allocation2terminal_info_fromudp",MAXNUM_AGENT);
    allocation_pub1 = nh_.advertise<allocation_common::allocation2terminal_info>("Robot1/task_allocation/allocation2terminal_info_fromudp",MAXNUM_AGENT);
    allocation_pub2 = nh_.advertise<allocation_common::allocation2terminal_info>("Robot2/task_allocation/allocation2terminal_info_fromudp",MAXNUM_AGENT);
    allocation_pub3 = nh_.advertise<allocation_common::allocation2terminal_info>("Robot3/task_allocation/allocation2terminal_info_fromudp",MAXNUM_AGENT);
    allocation_pub4 = nh_.advertise<allocation_common::allocation2terminal_info>("Robot4/task_allocation/allocation2terminal_info_fromudp",MAXNUM_AGENT);
    allocation_pub5 = nh_.advertise<allocation_common::allocation2terminal_info>("Robot5/task_allocation/allocation2terminal_info_fromudp",MAXNUM_AGENT);

        initSocket();

        // count = 0;
        // int robot_id = 1;
        // string robot_name = "Robot"+std::to_string(robot_id);
        // allocation_pub = nh_.advertise<allocation_common::allocation2terminal_info>(robot_name+"/task_allocation/allocation2terminal_info_fromudp",MAXNUM_AGENT);

        loop_timer_ = nh_.createTimer(ros::Duration(0.02), boost::bind(&DtaTerminalClient::timerCb, this));
        // while (ros::ok())
        // {
        //     /* code */
        //     recvmsgs();
        // }
        
    }

    bool DtaTerminalClient::initSocket() {
        local_port = 4702;
        //remote_ip = "230.1.1.1";

        this->UdpNetSocket =  socket(AF_INET, SOCK_DGRAM, 0);
        if(this->UdpNetSocket == -1){
            printf("socket fail\n");
            return false;
        } else{
            std::cout << "create UdpNetSocket succeed!" << std::endl;
        }

        /* 设置要加入组播的地址 */
	bzero(&mreq, sizeof(struct ip_mreq));

	if ((group = gethostbyname(remote_ip)) == (struct hostent *) 0) {
		perror("gethostbyname");
		exit(errno);
	}
 
	bcopy((void *) group->h_addr, (void *) &ia, group->h_length);
	/* 设置组地址 */
	bcopy(&ia, &mreq.imr_multiaddr.s_addr, sizeof(struct in_addr));
 
	/* 设置发送组播消息的源主机的地址信息 */
	mreq.imr_interface.s_addr = htonl(INADDR_ANY);
 
	/* 把本机加入组播地址，即本机网卡作为组播成员，只有加入组才能收到组播消息 */
	if (setsockopt(UdpNetSocket, IPPROTO_IP, IP_ADD_MEMBERSHIP, &mreq,sizeof(struct ip_mreq)) == -1) {
		perror("setsockopt");
		exit(-1);
	}
 
	socklen = sizeof(struct sockaddr_in);
	memset(&peeraddr, 0, socklen);
	peeraddr.sin_family = AF_INET;

	peeraddr.sin_port = htons(local_port);


	if (inet_pton(AF_INET, remote_ip, &peeraddr.sin_addr) <= 0) {
		printf("Wrong dest IP address!\n");
		exit(0);
	}

 
	/* 绑定自己的端口和IP信息到socket上 */
	if (bind(UdpNetSocket, (struct sockaddr *) &peeraddr,sizeof(struct sockaddr_in)) == -1) {
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

        // int set = 1;
        // setsockopt(this->UdpNetSocket, SOL_SOCKET, SO_REUSEADDR, &set, sizeof(int));
        // memset(&recvAddr, 0, sizeof(struct sockaddr_in));
        // recvAddr.sin_family = AF_INET;
        // recvAddr.sin_port = htons(4003);
        // recvAddr.sin_addr.s_addr = INADDR_ANY;
        // // 必须绑定，否则无法监听
        // if(bind(this->UdpNetSocket, (struct sockaddr *)&recvAddr, sizeof(struct sockaddr)) == -1){
        //     printf("bind fail\n");
        //     return -1;
        // }

        std::cout << "Listen the broadcast haved finished. " <<std::endl;

        return true;
    }

    void DtaTerminalClient::timerCb(){
        		
        recvmsgs();

        int robot_id = allocation_Data.robot_info.robot_ID;
        //string robot_name = "Robot"+std::to_string(robot_id);
        switch (robot_id){
            case 0: 
                allocation_pub0.publish(allocation_pub_info_);
                break;
            case 1: 
                allocation_pub1.publish(allocation_pub_info_);
                break;
            case 2: 
                allocation_pub2.publish(allocation_pub_info_);
                break;
            case 3: 
                allocation_pub3.publish(allocation_pub_info_);
                break;
            case 4: 
                allocation_pub4.publish(allocation_pub_info_);
                break;
            case 5: 
                allocation_pub5.publish(allocation_pub_info_);
                break;                
            default:
                break;
                }     
        //allocation_pub.publish(allocation_pub_info_);
          // if(allocation_pub_info_.robot_info.robot_ID == 1){
        
    }

    void DtaTerminalClient::recvmsgs() {
        ///因为循环周期从原来的0.02s改为0.01s，所以隔一次发送。
       socklen_t addrLen = sizeof(struct sockaddr_in);

        int recvbytes = recvfrom(this->UdpNetSocket, this->recvbuf, BUF_SIZE, 0,
                               (struct sockaddr *)&peeraddr, &addrLen);

        if(recvbytes != -1)
        {
            recvbuf[recvbytes] = '\0';
           // printf("receive a broadCast messgse:%s\n", recvbuf);
            //std::cout<<"receive a broadCast messgse:"<<recvbuf<<std::endl;
        }
        else{
            printf("recvfrom fail\n");
        }

        recvData(&allocation_Data,recvbuf,0);
        // allocation_pub.publish(allocation_pub_info_);

    }

    int DtaTerminalClient::recvData(Allocation2TerminalMSG *data, char *buf, int i){
        int index =i;
        int size1 = sizeof(allocation_task_info);
        int size2 = sizeof(allocation_robot_info);
        int size = size1 + size2;
        memcpy(data, buf+index, size);

        //robot_info
        allocation_pub_info_.robot_info.isvalid=data->robot_info.isvalid;
        allocation_pub_info_.robot_info.robot_ID=data->robot_info.robot_ID;
        allocation_pub_info_.robot_info.robot_mode=data->robot_info.robot_mode;
        allocation_pub_info_.robot_info.which_target=data->robot_info.which_target;
        allocation_pub_info_.robot_info.which_task=data->robot_info.which_task;
        allocation_pub_info_.robot_info.expect_pos.position.x=data->robot_info.expect_pos.x;
        allocation_pub_info_.robot_info.expect_pos.position.y=data->robot_info.expect_pos.y;
        allocation_pub_info_.robot_info.isupdate=data->robot_info.isupdate;
        allocation_pub_info_.robot_info.move_distance = data->robot_info.move_distance;
        allocation_pub_info_.robot_info.robot_power =data->robot_info.robot_power;;
        
        //task_info
        allocation_pub_info_.task_info.task_ID = data->task_info.task_ID;
        allocation_pub_info_.task_info.current_distance = data->task_info.current_distance;
        allocation_pub_info_.task_info.iscomplete=data->task_info.iscomplete;
        allocation_pub_info_.task_info.isexplored=data->task_info.isexplored;
        allocation_pub_info_.task_info.istarget=data->task_info.istarget;
        allocation_pub_info_.task_info.isallocated=data->task_info.isallocated;
        allocation_pub_info_.task_info.known_power=data->task_info.known_power;
        allocation_pub_info_.task_info.task_power=data->task_info.task_power;
        allocation_pub_info_.task_info.isupdate=data->task_info.isupdate;    
         std::cout << "data->robot_info.robot_ID  " << data->robot_info.robot_ID <<"  "<<allocation_pub_info_.robot_info.robot_ID<<std::endl;
        //  std::cout << count<<std::endl;
        std::cout << "robot_info.which_task  "<<allocation_pub_info_.robot_info.which_task<<" "<<data->robot_info.which_task<<std::endl;
        return index;
    }

}



int main(int argc, char **argv) {

        std::string node_name = "dta_terminal_client_node";
        ros::init(argc, argv, node_name);
        ros::NodeHandle nh("");
        ros::NodeHandle nh_private("~");
        DtaTerminalClient::DtaTerminalClient recv(nh, nh_private, node_name);
        ROS_INFO("Initialized recv node.");
        ros::spin();
}
