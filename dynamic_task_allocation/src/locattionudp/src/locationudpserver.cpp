#include "locationudpserver.hpp"

namespace locationudpserver {

    locationudpserver::locationudpserver(const ros::NodeHandle &nh, const ros::NodeHandle &nh_private, std::string node_name):nh_(nh), nh_private_(nh_private),
    node_name(node_name)
    {

        initialize();
    }

    void locationudpserver::initialize() {

        initSocket();
        gps_sub = nh_.subscribe("bigrobot5/gpsdata_UTM", 1, &locationudpserver::callbackGpsmsgs, this);
        loop_timer_ = nh_.createTimer(ros::Duration(0.05), boost::bind(&locationudpserver::timerCb, this));

    }

    bool locationudpserver::initSocket() {
        //&remote_ip = "230.1.1.1";
        remote_port = 4701;
        //local_ip[32] = "192.168.43.61";
        local_port = 4501;

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

        // int optval = 1;//这个值一定要设置，否则可能导致sendto()失败
        // setsockopt(this->UdpNetSocket, SOL_SOCKET, SO_BROADCAST | SO_REUSEADDR, &optval, sizeof(int));
        // memset(&remoteAddr, 0, sizeof(struct sockaddr_in));
        // this->remoteAddr.sin_family = AF_INET;
        // this->remoteAddr.sin_addr.s_addr = inet_addr("255.255.255.255");//此处可以设置为全网的广播地址，例如255.255.255.255
        // this->remoteAddr.sin_port = htons(4008);

        std::cout << "Listen the broadcast haved finished. " <<std::endl;

        return true;
    }

    void locationudpserver::callbackGpsmsgs(const sensor_driver_msgs::GpswithHeading msg){

        // this->our_gps.latitude = msg.gps.latitude;
        // this->our_gps.longitude = msg.gps.longitude;
        this->our_gps.latitude = msg.gps.latitude-4176230.5936185;
        this->our_gps.longitude = msg.gps.longitude-147993.2398021;
//        this->our_gps.altitude = 3; //msg.gps.altitude;
//
        // this->our_gps.heading = msg.heading;
//        this->our_gps.roll = 5;//msg.roll;
//        this->our_gps.pitch = 6;// msg.pitch;


    }

    void locationudpserver::timerCb(){

        sendmsgs();
    }

    void locationudpserver::sendmsgs() {
        ///因为循环周期从原来的0.02s改为0.01s，所以隔一次发送。
        ROS_INFO("sending messages");

        int len = sendData(&our_gps, sendbuf);

        int sendBytes = sendto(this->UdpNetSocket, this->sendbuf, len, 0,
                           (struct sockaddr *)&peeraddr, sizeof(struct sockaddr));

        if(sendBytes == -1) {
            printf("sendto fail, errno=%d\n", errno);
        }

    }

    int locationudpserver::sendData(GpsMsg* data, char *buf) {

        ROS_INFO("send data to buf start.");

        int index = 0;

        char *p  = new char[3];
        *(p) = 'a';
        *(p+1) = 'a';
        *(p+2) = '5';
        //*(p+3) = '\0';
        memcpy(buf,p,3);
        index += 3;
        std::cout<< "data= "<< sizeof(*data)<<std::endl;
        memcpy(buf + index, data, 72);

        index += sizeof(*data);
        std::cout<< "data= "<<index<<std::endl;
        return index;
    }

}



int main(int argc, char **argv) {

        std::string node_name = "locationudpserver_node";
        ros::init(argc, argv, node_name);
        ros::NodeHandle nh("");
        ros::NodeHandle nh_private("~");
        locationudpserver::locationudpserver sender(nh, nh_private, node_name);
        ROS_INFO("Initialized sender node.");
        ros::spin();
}
