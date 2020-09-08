#include <poses_talker.h>
using namespace std;
void Poses_talker::robot_dymatic_listener_Callback(const nav_msgs::Path &robot_location_list){
/*--------------------------------------*/
    std::string full_path = ros::package::getPath("allocation_gazebo") + "/src/Nodes.txt";
    ifstream loadData(full_path);
	double tempX, tempY, tempT;
	int tempF;                   //结束标志

	while(1)
	{
		loadData>>tempX; //偏离realmap地图中心的x方向距离，单位为200m/100
		loadData>>tempY;
		loadData>>tempT;
		loadData>>tempF;
		if(tempF == 999)
		{
			loadData.close();
			break;
		}
		 tempX= (tempX - origin_x) * singleGridSize;
       		 tempY=(origin_y - tempY) * singleGridSize;
		tasks_info_.task_ID = tempF;
        	tasks_info_.task_pose.x  = tempX;
        	tasks_info_.task_pose.y  = tempY;

		_gazebo2world_info.gazebo_tasks_info.push_back(tasks_info_);		

		
	}
        
        
	
/*--------------------------------------*/
	if(robot_location_list.header.frame_id == "robot_poses"){
		for (auto it : robot_location_list.poses){
			int robot_id = atoi(it.header.frame_id.c_str());
			robots_info_.robot_ID  = robot_id -1;
			robots_info_.robot_pose.position.x = (-it.pose.position.x);
			robots_info_.robot_pose.position.y = (-it.pose.position.y);
			robots_info_.robot_pose.theta      = 0;
            robots_info_.robot_twist.angular   = 0;
            robots_info_.robot_twist.linear.x  = 0;
            robots_info_.robot_twist.linear.y  = 0;
            _gazebo2world_info.gazebo_robots_info.push_back(robots_info_);
			}
	}
	poses_pub.publish(_gazebo2world_info);
	_gazebo2world_info.gazebo_robots_info.clear();
	_gazebo2world_info.gazebo_tasks_info.clear();

}

void Poses_talker::robot_dymatic_listener_self_Callback(const sensor_driver_msgs::GpswithHeading &msg){
	    robots_info_.robot_ID  = 0;
	    robots_info_.robot_pose.position.x = msg.gps.latitude;
	    robots_info_.robot_pose.position.y = msg.gps.longitude;
	    robots_info_.robot_pose.theta      = 0;
            robots_info_.robot_twist.angular   = 0;
            robots_info_.robot_twist.linear.x  = 0;
            robots_info_.robot_twist.linear.y  = 0;
            _gazebo2world_info.gazebo_robots_info.push_back(robots_info_);
}

void Poses_talker::init(){
	std::cout<<"init"<<std::endl;

	//poses_self_sub = nh_.subscribe("bigrobot6/gpsdata_UTM",10,&Poses_talker::robot_dymatic_listener_self_Callback,this);
	poses_sub = nh_.subscribe("robot_location_all",10,&Poses_talker::robot_dymatic_listener_Callback,this);
	poses_pub = nh_.advertise<allocation_common::gazebo2world_info>("allocation_gazebo/gazebo2world_info",MAXNUM_AGENT);
  
	
}

int main(int argc, char **argv)
{
	ros::init(argc,argv,"poses_talker");
	Poses_talker poses_talker;
	poses_talker.init();
	//world_gazebo.poses_sub = subscribe("robot_location_all",10,&World_Gazebo::robot_dymatic_listener_Callback,this);
	ros::Rate loop_rate(50);
	while(ros::ok()){
	 	ros::spinOnce();    
	loop_rate.sleep();
	 }	
}
