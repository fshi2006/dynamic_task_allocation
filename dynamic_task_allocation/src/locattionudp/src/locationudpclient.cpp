#include "locationudpclient.hpp"

namespace locationudpclient {

    locationudpclient::locationudpclient(const ros::NodeHandle &nh, const ros::NodeHandle &nh_private, std::string node_name):nh_(nh), nh_private_(nh_private),
    node_name(node_name)
    {

        initialize();
    }

    void locationudpclient::initialize() {

        initSocket();
        pub_all_location = nh_.advertise<nav_msgs::Path>("robot_location_all",1000);
        // loop_timer_ = nh_.createTimer(ros::Duration(0.01), boost::bind(&locationudpclient::timerCb, this));
        poses_self_sub = nh_.subscribe("bigrobot5/gpsdata_UTM",10,&locationudpclient::robot_dymatic_listener_self_Callback,this);

    }

    bool locationudpclient::initSocket() {

        local_port = 4701;
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

        // int set = 1;
        // setsockopt(this->UdpNetSocket, SOL_SOCKET, SO_REUSEADDR, &set, sizeof(int));
        // memset(&recvAddr, 0, sizeof(struct sockaddr_in));
        // recvAddr.sin_family = AF_INET;
        // recvAddr.sin_port = htons(4008);
        // recvAddr.sin_addr.s_addr = INADDR_ANY;
        // // 必须绑定，否则无法监听
        // if(bind(this->UdpNetSocket, (struct sockaddr *)&recvAddr, sizeof(struct sockaddr)) == -1){
        //     printf("bind fail\n");
        //     return -1;
        // }

        std::cout << "Listen the broadcast haved finished. " <<std::endl;

        return true;
    }


    void locationudpclient::robot_dymatic_listener_self_Callback(const sensor_driver_msgs::GpswithHeading msg){
		std::cout<<"selfcb"<<std::endl;

        robot_location robot_tmp;
        robot_tmp.ID = '5';
        // robot_tmp.robot_x = msg.gps.latitude;
        // robot_tmp.robot_y = msg.gps.longitude;
        robot_tmp.robot_y = msg.gps.latitude-4176230.5936185;
        robot_tmp.robot_x = msg.gps.longitude-147993.2398021;
        robot_location_all.push_back(robot_tmp);

        std::cout<<"selfcbend"<<std::endl;

        nav_msgs::Path robot_poses_all;
		robot_poses_all.header.frame_id = "robot_poses";
        recvmsgs();
        for(unsigned int i=0; i<robot_location_all.size();i++){
			//std::cout << Aco_Init.TotalTaskNode.at(i).x << " ";
			geometry_msgs::PoseStamped tempose;
            tempose.header.frame_id = robot_location_all[i].ID;
			tempose.pose.position.x = robot_location_all[i].robot_x;
			tempose.pose.position.y = robot_location_all[i].robot_y ;
			robot_poses_all.poses.push_back(tempose);
			}
        pub_all_location.publish(robot_poses_all);
        robot_location_all.clear();
    }


    // void locationudpclient::timerCb(){

    //     nav_msgs::Path robot_poses_all;
	// 	robot_poses_all.header.frame_id = "robot_poses";
    //     recvmsgs();
    //     for(unsigned int i=0; i<robot_location_all.size();i++){
	// 		//std::cout << Aco_Init.TotalTaskNode.at(i).x << " ";
	// 		geometry_msgs::PoseStamped tempose;
    //         tempose.header.frame_id = robot_location_all[i].ID;
	// 		tempose.pose.position.x = robot_location_all[i].robot_x;
	// 		tempose.pose.position.y = robot_location_all[i].robot_y ;
	// 		robot_poses_all.poses.push_back(tempose);
	// 		}
    //     pub_all_location.publish(robot_poses_all);
    // }


    void locationudpclient::recvmsgs(){

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

        for(int i = 0; i < recvbytes; i++){
            if(recvbuf[i] == 'a' && recvbuf[i+1] == 'a'){
                switch (recvbuf[i+2]){
                    
                    case '1': recvData(&gps_first,recvbuf, i+3);
                        break;
                    case '2': recvData(&gps_second,recvbuf, i+3);
                        break;
                    case '3': recvData(&gps_third, recvbuf, i+3);
                        break;
                    case '4': recvData(&gps_forth, recvbuf, i+3);
                        break;
                    case '5': recvData(&gps_fifth, recvbuf, i+3);
                        break;
                    case '6': recvData(&gps_sixth, recvbuf, i+3);
                        break;
                    default:
                        break;
                }
            }
        }
    }

    int locationudpclient::recvData(GpsMsg *data, char *buf, int i) {

        int index =i;
        memcpy(data, buf+index, sizeof(*data));
	    msg.position.x = data->longitude;
        msg.position.y = data->latitude;
        robot_location robot_tmp;
        robot_tmp.ID = buf[i-1];
        robot_tmp.robot_x = data->longitude;
        robot_tmp.robot_y = data->latitude;
        msg.position.z = data->altitude;
        msg.heading  = data->heading;
        msg.roll = data->roll;
        msg.pitch = data->pitch;
        msg.re_position.x = data->dlongitude;
        msg.re_position.y = data->dlatitude;
        msg.re_position.z = data->daltitude;
        msg.GNSS_status = data->GNSS_status;
        robot_location_all.push_back(robot_tmp);
	return index;
    }

}



int main(int argc, char **argv) {

        std::string node_name = "locationudpclient_node";
        ros::init(argc, argv, node_name);
        ros::NodeHandle nh("");
        ros::NodeHandle nh_private("~");
        locationudpclient::locationudpclient recv(nh, nh_private, node_name);
        ROS_INFO("Initialized recv node.");
        ros::spin();
}
