#include <topic_info_talker.h>

void Topic_Info_talker::update_allocation_info(const allocation_common::allocation2terminal_info::ConstPtr & _msg, int topic_id)
{
     //std::cout<< " "<<terminal2robots_info.all_allocation_robot_info.size()<<std::endl;
        // for(int i = 0; i< MAXNUM_AGENT;i++)
        // {
            //std::cout <<"_____________________"<< topic_id << std::endl;
        // }
   // terminal2robot_pub_info_.allocation_mode=terminal2robots_info.allocation_mode;
    terminal2robot_pub_info_.greedorprobability=terminal2robots_info.greedorprobability;
    terminal2robot_pub_info_.allocation_method=terminal2robots_info.allocation_method;

    //update for control terminal show
    //std::cout<< "+==========================="<<terminal2robots_info.all_allocation_robot_info.size()<<std::endl;
    terminal2robots_info.all_allocation_robot_info[topic_id].isvalid=_msg->robot_info.isvalid;
    terminal2robots_info.all_allocation_robot_info[topic_id].robot_ID=_msg->robot_info.robot_ID;
    terminal2robots_info.all_allocation_robot_info[topic_id].robot_mode=_msg->robot_info.robot_mode;
    terminal2robots_info.all_allocation_robot_info[topic_id].which_target=_msg->robot_info.which_target;
    terminal2robots_info.all_allocation_robot_info[topic_id].which_task=_msg->robot_info.which_task;
    terminal2robots_info.all_allocation_robot_info[topic_id].robot_power=10;
//    terminal2robots_info.all_allocation_robot_info[topic_id].expect_pos.x_=_msg->robot_info.expect_pos.position.x;
//    terminal2robots_info.all_allocation_robot_info[topic_id].expect_pos.y_=_msg->robot_info.expect_pos.position.y;
    terminal2robots_info.all_allocation_robot_info[topic_id].move_distance=_msg->robot_info.move_distance;
    //std::cout<< "==========================="<<std::endl;
    if(_msg->task_info.task_ID!=-1)
    {
        int _task_id=_msg->task_info.task_ID;
        terminal2robots_info.all_allocation_task_info[_task_id].task_ID=_msg->task_info.task_ID;
        terminal2robots_info.all_allocation_task_info[_task_id].current_distance=_msg->task_info.current_distance;
        terminal2robots_info.all_allocation_task_info[_task_id].isallocated=_msg->task_info.isallocated;
        terminal2robots_info.all_allocation_task_info[_task_id].task_power=0;

        if(_msg->task_info.iscomplete)
            terminal2robots_info.all_allocation_task_info[_task_id].iscomplete=_msg->task_info.iscomplete;
        if(_msg->task_info.isexplored)
            terminal2robots_info.all_allocation_task_info[_task_id].isexplored=_msg->task_info.isexplored;
        if(_msg->task_info.istarget)
            terminal2robots_info.all_allocation_task_info[_task_id].istarget=_msg->task_info.istarget;
        if(terminal2robots_info.all_allocation_task_info[_task_id].known_power<_msg->task_info.known_power)
            terminal2robots_info.all_allocation_task_info[_task_id].known_power=_msg->task_info.known_power;
    }
    //std::cout<< "-------==========================="<<std::endl;
    //update for pub to robot
    allocation_common::allocation_robot_info _tmp_robot_info;
    allocation_common::allocation_task_info  _tmp_task_info;

    _tmp_robot_info.isvalid=_msg->robot_info.isvalid;
    _tmp_robot_info.robot_ID=_msg->robot_info.robot_ID;
    _tmp_robot_info.robot_mode=_msg->robot_info.robot_mode;
    _tmp_robot_info.which_target=_msg->robot_info.which_target;
    _tmp_robot_info.which_task=_msg->robot_info.which_task;
    _tmp_robot_info.expect_pos.position.x=_msg->robot_info.expect_pos.position.x;
    _tmp_robot_info.expect_pos.position.y=_msg->robot_info.expect_pos.position.y;
    _tmp_robot_info.isupdate=true;
    timeforupdaterobot_[_tmp_robot_info.robot_ID]=0;

    //the robot_power is certained by control_terminal, not task_allocation
    _tmp_robot_info.robot_power=terminal2robots_info.all_allocation_robot_info[_tmp_robot_info.robot_ID].robot_power;
    terminal2robot_pub_info_.all_allocation_robot_info[topic_id]=_tmp_robot_info;
//    std::cout<<_tmp_robot_info.robot_ID<<" "<<topic_id<<std::endl;

    if(_msg->task_info.task_ID!=-1)
    {
        _tmp_task_info=terminal2robot_pub_info_.all_allocation_task_info[_msg->task_info.task_ID];

        _tmp_task_info.task_ID=_msg->task_info.task_ID;
        _tmp_task_info.isupdate=true;
        _tmp_task_info.current_distance=_msg->task_info.current_distance;
        _tmp_task_info.isallocated=_msg->task_info.isallocated;

        if(_msg->task_info.iscomplete)
            _tmp_task_info.iscomplete=_msg->task_info.iscomplete;
        if(_msg->task_info.isexplored)
            _tmp_task_info.isexplored=_msg->task_info.isexplored;
        if(_msg->task_info.istarget)
            _tmp_task_info.istarget=_msg->task_info.istarget;
        if(_tmp_task_info.known_power<_msg->task_info.known_power)
            _tmp_task_info.known_power=_msg->task_info.known_power;

        //the task_power is certained by control_terminal, not task_allocation
        _tmp_task_info.task_power=terminal2robots_info.all_allocation_task_info[_tmp_task_info.task_ID].task_power;
        terminal2robot_pub_info_.all_allocation_task_info[_tmp_task_info.task_ID]=_tmp_task_info;
        timeforupdatetask_[_tmp_task_info.task_ID]=0;
    }     
}

void Topic_Info_talker::startmsg_cb(const std_msgs::Char::ConstPtr &msg)
{
    unsigned char state = msg->data;
    terminal2robot_pub_info_.allocation_mode = state;
}

void Topic_Info_talker::timerCb(){
    for(unsigned i=0;i<terminal2robot_pub_info_.all_allocation_robot_info.size();i++){
        if(terminal2robot_pub_info_.all_allocation_robot_info[i].isupdate==true)
        {
            if(timeforupdaterobot_[i]==2)
                terminal2robot_pub_info_.all_allocation_robot_info[i].isupdate=false;
            else
                timeforupdaterobot_[i]++;
        }
    }
    for(unsigned i=0;i<terminal2robot_pub_info_.all_allocation_task_info.size();i++){
        if(terminal2robot_pub_info_.all_allocation_task_info[i].isupdate==true)
        {
            if(timeforupdatetask_[i]==2)
                terminal2robot_pub_info_.all_allocation_task_info[i].isupdate=false;
            else
                timeforupdatetask_[i]++;
        }
    }
    terminal2robot_pub_.publish(terminal2robot_pub_info_);
    if(terminal2robots_info.allocation_mode==ALLOCATION_STOP&&terminal2robots_info.all_allocation_robot_info.size()!=0&&terminal2robots_info.all_allocation_robot_info[0].move_distance!=0)
        {
    terminal2robot_pub_info_.all_allocation_robot_info.clear();
    terminal2robot_pub_info_.all_allocation_task_info.clear();
    terminal2robots_info.all_allocation_robot_info.clear();
    terminal2robots_info.all_allocation_task_info.clear();
    terminal2robot_pub_info_.all_allocation_robot_info.resize(MAXNUM_AGENT);
    terminal2robot_pub_info_.all_allocation_task_info.resize(MAXNUM_TASK);
    terminal2robots_info.all_allocation_robot_info.resize(MAXNUM_AGENT);
    terminal2robots_info.all_allocation_task_info.resize(MAXNUM_TASK);


    for(unsigned int i=0;i<terminal2robots_info.all_allocation_robot_info.size();i++)
        terminal2robots_info.all_allocation_robot_info[i].robot_reset();
    for(unsigned int j=0;j<terminal2robots_info.all_allocation_task_info.size();j++)
        terminal2robots_info.all_allocation_task_info[j].task_reset();
        }
    }

void Topic_Info_talker::init(){
    //ros::Time::init();
      terminal2robot_pub_info_.allocation_mode = 1;
    nh_= boost::make_shared<ros::NodeHandle>();
    //terminal2robots_info.allocation_mode = ALLOCATION_START;
    terminal2robots_info.greedorprobability = 1; //greed 0; probability 1;
    terminal2robots_info.allocation_method = Market;
    terminal2robot_pub_info_.all_allocation_robot_info.resize(MAXNUM_AGENT);
    terminal2robot_pub_info_.all_allocation_task_info.resize(MAXNUM_TASK);
    terminal2robots_info.all_allocation_robot_info.resize(MAXNUM_AGENT);
    terminal2robots_info.all_allocation_task_info.resize(MAXNUM_TASK);
    timeforupdaterobot_.resize(MAXNUM_AGENT,0);
    timeforupdatetask_.resize(MAXNUM_TASK,0);
    /*-----------------------initialize-------------------*/
    
    /*-----------------------initialize-------------------*/
   
    //terminalinfo_publish_timer_ = nh_->createTimer(ros::Duration(0.05),&Topic_Info_talker::publish,this);
	for(int i=0;i<REAL_AGENT;i++){
        //std::cout << "size "<<terminal2robot_pub_info_.all_allocation_robot_info.size()<<" "<<terminal2robot_pub_info_.all_allocation_task_info.size()<<std::endl;
        allocation2terminal_sub_[i]=nh_->subscribe <allocation_common::allocation2terminal_info>
            ("Robot"+std::to_string(i)+"/task_allocation/allocation2terminal_info_fromudp",MAXNUM_AGENT,boost::bind(&Topic_Info_talker::update_allocation_info,this,_1,i));
    }
    for(int i=6;i<MAXNUM_AGENT;i++){
        //std::cout << "size "<<terminal2robot_pub_info_.all_allocation_robot_info.size()<<" "<<terminal2robot_pub_info_.all_allocation_task_info.size()<<std::endl;
        allocation2terminal_sub_[i]=nh_->subscribe <allocation_common::allocation2terminal_info>
            ("Robot"+std::to_string(i)+"/task_allocation/allocation2terminal_info_from_plan",MAXNUM_AGENT,boost::bind(&Topic_Info_talker::update_allocation_info,this,_1,i));
    }
    startmsg_sub_ = nh_->subscribe<std_msgs::Char>("start_msgs",1,boost::bind(&Topic_Info_talker::startmsg_cb,this,_1));
    terminal2robot_pub_  = nh_->advertise<allocation_common::terminal2robot_info>("/topic_info_talker/terminal2robot_info",1);
    loop_timer_ = nh_->createTimer(ros::Duration(0.05), boost::bind(&Topic_Info_talker::timerCb, this));
}    

int main(int argc, char **argv)
{
	ros::init(argc,argv,"topic_info_talker");
	Topic_Info_talker topic_info_talker;
    topic_info_talker.init();
	//world_gazebo.poses_sub = subscribe("robot_location_all",10,&World_Gazebo::robot_dymatic_listener_Callback,this);

	ros::Rate loop_rate(20.0);
	while(ros::ok()){

		ros::spinOnce();
    
	loop_rate.sleep();
	 }	
}
