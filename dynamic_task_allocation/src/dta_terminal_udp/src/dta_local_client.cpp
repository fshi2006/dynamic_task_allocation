#include "dta_local_client.hpp"

namespace DtaLocalClient {

    DtaLocalClient::DtaLocalClient(const ros::NodeHandle &nh, const ros::NodeHandle &nh_private, std::string node_name):nh_(nh), nh_private_(nh_private),
    node_name(node_name)
    {
        initialize();
    }

    void DtaLocalClient::initialize() {

        initSocket();

        terminal_pub = nh_.advertise<allocation_common::terminal2robot_info>("/topic_info_talker/terminal2robot_info111",1);

        loop_timer_ = nh_.createTimer(ros::Duration(0.05), boost::bind(&DtaLocalClient::timerCb, this));

    }

    bool DtaLocalClient::initSocket() {
        local_port = 4703;
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
        // recvAddr.sin_port = htons(4010);
        // recvAddr.sin_addr.s_addr = INADDR_ANY;
        // // 必须绑定，否则无法监听
        // if(bind(this->UdpNetSocket, (struct sockaddr *)&recvAddr, sizeof(struct sockaddr)) == -1){
        //     printf("bind fail\n");
        //     return -1;
        // }

        std::cout << "Listen the broadcast haved finished. " <<std::endl;

        return true;
    }

    void DtaLocalClient::timerCb(){
        		
        recvmsgs();
        
        terminal_pub.publish(terminal2robot_pub_info_);

        // std::cout << "publish succecced---------------" << std::endl;
    }

    void DtaLocalClient::recvmsgs() {
        ///因为循环周期从原来的0.02s改为0.01s，所以隔一次发送。
       socklen_t addrLen = sizeof(struct sockaddr_in);

        int recvbytes = recvfrom(this->UdpNetSocket, this->recvbuf, BUF_SIZE, 0,
                               (struct sockaddr *)&peeraddr, &addrLen);

        if(recvbytes != -1)
        {
            recvbuf[recvbytes] = '\0';
            printf("receive a broadCast messgse:%s\n", recvbuf);
            //std::cout<<"receive a broadCast messgse:"<<recvbuf<<std::endl;
        }
        else{
            printf("recvfrom fail\n");
        }
        // std::cout << "resize over" << std::endl;
        recvData(&terminal_Data,recvbuf,0);

    }

    int DtaLocalClient::recvData(Terminal2RobotMSG *data, char *buf, int i){
        int index =i;
        
        // std::cout << "recvData start" << std::endl;
        memcpy(&data->allocation_mode, buf+index, 1);
        index+=1;
        memcpy(&data->greedorprobability, buf+index, 1);
        index+=1;
        memcpy(&data->allocation_method, buf+index, 1);
        index+=1;

        terminal2robot_pub_info_.allocation_mode = data->allocation_mode;
        terminal2robot_pub_info_.greedorprobability = data->greedorprobability;
        terminal2robot_pub_info_.allocation_method = data->allocation_method;

        // std::cout<<terminal2robot_pub_info_.allocation_mode<<" "<<data->allocation_mode<<std::endl;
        // std::cout<<terminal2robot_pub_info_.greedorprobability<<" "<<data->greedorprobability<<std::endl;
        // std::cout<<terminal2robot_pub_info_.allocation_method<<" "<<data->allocation_method<<std::endl;
   
        for(int i=0;i<MAXNUM_AGENT;i++){
            memcpy(&data->robot_ID[i],buf+index,4);
            index+=4;
        }
        for(int i=0;i<MAXNUM_AGENT;i++){
            memcpy(&data->robot_mode[i],buf+index,1);
            index+=1;
        }
        for(int i=0;i<MAXNUM_AGENT;i++){
            memcpy(&data->which_task[i],buf+index,4);
            index+=4;
        }
        for(int i=0;i<MAXNUM_AGENT;i++){
            memcpy(&data->which_target[i],buf+index,4);
            index+=4;
        }
        for(int i=0;i<MAXNUM_AGENT;i++){
            memcpy(&data->expect_posx[i],buf+index,4);
            index+=4;
        }
        for(int i=0;i<MAXNUM_AGENT;i++){
            memcpy(&data->expect_posy[i],buf+index,4);
            index+=4;
        }
        for(int i=0;i<MAXNUM_AGENT;i++){
            memcpy(&data->isvalid[i],buf+index,1);
            index+=1;
        }
        for(int i=0;i<MAXNUM_AGENT;i++){
            memcpy(&data->robot_power[i],buf+index,4);
            index+=4;
        }
        for(int i=0;i<MAXNUM_AGENT;i++){
            memcpy(&data->move_distance[i],buf+index,4);
            index+=4;
        }
        for(int i=0;i<MAXNUM_AGENT;i++){
            memcpy(&data->robot_isupdate[i],buf+index,1);
            index+=1;
        }
        for(int i=0;i<MAXNUM_TASK;i++){
            memcpy(&data->task_ID[i],buf+index,4);
            index+=4;
        }
        for(int i=0;i<MAXNUM_TASK;i++){
            memcpy(&data->known_power[i],buf+index,4);
            index+=4;
        }
        for(int i=0;i<MAXNUM_TASK;i++){
            memcpy(&data->current_distance[i],buf+index,4);
            index+=4;
        }
        for(int i=0;i<MAXNUM_TASK;i++){
            memcpy(&data->istarget[i],buf+index,1);
            index+=1;
        }
        for(int i=0;i<MAXNUM_TASK;i++){
            memcpy(&data->iscomplete[i],buf+index,1);
            index+=1;
        }
        for(int i=0;i<MAXNUM_TASK;i++){
            memcpy(&data->isexplored[i],buf+index,1);
            index+=1;
        }
        for(int i=0;i<MAXNUM_TASK;i++){
            memcpy(&data->isallocated[i],buf+index,1);
            index+=1;
        }
        for(int i=0;i<MAXNUM_TASK;i++){
            memcpy(&data->task_power[i],buf+index,4);
            index+=4;
        }
        for(int i=0;i<MAXNUM_TASK;i++){
            memcpy(&data->task_isupdate[i],buf+index,1);
            index+=1;
        }

        int robot_size = sizeof(data->robot_ID);
        int task_size = sizeof(data->task_ID);
        // std::cout<<robot_size<<" "<<task_size<<std::endl;

        allocation_common::allocation_robot_info _tmp_robot_info;
        allocation_common::allocation_task_info  _tmp_task_info;

        terminal2robot_pub_info_.all_allocation_robot_info.clear();
        terminal2robot_pub_info_.all_allocation_task_info.clear();
        terminal2robot_pub_info_.all_allocation_robot_info.resize(MAXNUM_AGENT);
        terminal2robot_pub_info_.all_allocation_task_info.resize(MAXNUM_TASK);

        for(int i =0 ;i< MAXNUM_AGENT; i++){
            _tmp_robot_info.isvalid=data->isvalid[i];
            _tmp_robot_info.robot_ID=data->robot_ID[i];
            _tmp_robot_info.robot_mode=data->robot_mode[i];
            _tmp_robot_info.which_target=data->which_target[i];
            _tmp_robot_info.which_task=data->which_task[i];
            _tmp_robot_info.expect_pos.position.x=data->expect_posx[i];
            _tmp_robot_info.expect_pos.position.y=data->expect_posy[i];
            _tmp_robot_info.isupdate=data->robot_isupdate[i];
            _tmp_robot_info.move_distance = data->move_distance[i];
            _tmp_robot_info.robot_power =data->robot_power[i];
            terminal2robot_pub_info_.all_allocation_robot_info[i]=_tmp_robot_info;
            // std::cout << "_tmp_robot_info.robot_ID" << _tmp_robot_info.robot_ID << std::endl;

        }

        for(int i =0 ;i< MAXNUM_TASK; i++){
            _tmp_task_info.task_ID = data->task_ID[i];
            _tmp_task_info.current_distance = data->current_distance[i];
            _tmp_task_info.iscomplete=data->iscomplete[i];
            _tmp_task_info.isexplored=data->isexplored[i];
            _tmp_task_info.istarget=data->istarget[i];
            _tmp_task_info.isallocated=data->isallocated[i];
            _tmp_task_info.known_power=data->known_power[i];
            _tmp_task_info.task_power=data->task_power[i];
            _tmp_task_info.isupdate=data->task_isupdate[i];
            terminal2robot_pub_info_.all_allocation_task_info[i]=_tmp_task_info;

            // std::cout << "data->task_ID" << data->task_ID << std::endl;
            // std::cout << "_tmp_task_info.task_ID" << _tmp_task_info.task_ID << std::endl;
        }

        std::cout << "index, end" << sizeof(*data) << std::endl;

        return index;
    }

}



int main(int argc, char **argv) {

        std::string node_name = "dta_local_client_node";
        ros::init(argc, argv, node_name);
        ros::NodeHandle nh("");
        ros::NodeHandle nh_private("~");
        DtaLocalClient::DtaLocalClient recv(nh, nh_private, node_name);
        ROS_INFO("Initialized recv node.");
        ros::spin();
}
