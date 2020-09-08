#include "task_allocation_plan.h"
#include <boost/thread.hpp>

Task_Allocation_Plan::Task_Allocation_Plan()
{
    //robot_name="Robot i"
    // allocation_common/spawn_robots.sh中传递的第一个参数
    //std::string robot_name=argv[1];
    std::string robot_name= "Robot4";
    // std::cout << "argv" << argv[1] << std::endl;
    std::cout<<"robot_name" << robot_name<<std::endl;
    const char * robot_ID;
all_robots_.resize(10);

    // 处理robot1和robot11区别,把最后两个字符串变成数字
    if(robot_name.size()==6)
        robot_ID = robot_name.substr(robot_name.size() - 1).c_str();
    else if(robot_name.size()==7)
        robot_ID = robot_name.substr(robot_name.size() - 2).c_str();

    my_robot_.allocation_robot_info.robot_ID=atoi(robot_ID);
    my_robot_.gazebo_robot_info.robot_ID=atoi(robot_ID);
    ROS_INFO("start %s task_allocation_process",robot_name.c_str());

    nh_ = new ros::NodeHandle();
    robot2gazebo_pub_       =nh_->advertise<allocation_common::robot2gazebo_info>(robot_name+"/task_allocation/robot2gazebo_info",MAXNUM_AGENT);
    allocation2terminal_pub_=nh_->advertise<allocation_common::allocation2terminal_info>(robot_name+"/task_allocation/allocation2terminal_info_from_plan",MAXNUM_AGENT);
    drawing_pub_            =nh_->advertise<geometry_msgs::Point>(robot_name+"/task_allocation/drawing_info",MAXNUM_AGENT);
    which_task_pub = nh_->advertise<nav_msgs::Path>("/bigrobot5/aco_planner_pub_single",MAXNUM_AGENT);
    terminal2robot_sub_     =nh_->subscribe("/topic_info_talker/terminal2robot_info111",MAXNUM_AGENT,&Task_Allocation_Plan::update_terminal_info,this);
    gazebo2world_sub_       =nh_->subscribe("/allocation_gazebo/gazebo2world_info",MAXNUM_AGENT,&Task_Allocation_Plan::update_gazebo_world,this);
    // terminal2robot_sub_     =nh_->subscribe("/control_terminal/terminal2robot_info",MAXNUM_AGENT,&Task_Allocation_Plan::update_terminal_info,this);

    allocation_timer       =nh_->createTimer(ros::Duration(0.5),&Task_Allocation_Plan::loopControl,this);

   // my_behaviour_=new Behaviour(obstacles_); // 变量的定义在头文件中, 返回的值是内存地址,my_behaviour_是Behaviour类的指针

    num_task_valid_=1;
    num_target_valid_=0;
    num_task_unallocated_=1;
    num_target_unallocated_=0;
    bid_new_task_=false;
    bid_new_target_=false;
    is_target_completed=false;
    is_task_explored=false;
    is_world_update_=false;
    is_all_completed=false;
    all_tasks_.clear();
    all_robots_.clear();

    my_robot_.allocation_robot_info.isvalid=true;
}

Task_Allocation_Plan::~Task_Allocation_Plan()
{
    num_task_valid_=1;
    num_target_valid_=0;
    num_task_unallocated_=1;
    num_target_unallocated_=0;
    bid_new_task_=false;
    bid_new_target_=false;
    is_target_completed=false;
    is_task_explored=false;
    is_world_update_=false;
    is_all_completed=false;
}

void Task_Allocation_Plan::update_gazebo_world(const allocation_common::gazebo2world_info::ConstPtr &_msg)
{
    std::cout << "update_gazebo_world start" << std::endl;
    //because the robots' pos is change,clear the obstacles and re-push the pos of robots
    obstacles_.clear(); // 只是把数据清除了,变成NULL,但是内存空间没有释放

    //first callback, if all_robots is a null vector, resize its size according to the _msg from gazebo
    // all_robots_是一个vector,成员变量的类型是结构体Robot_info,其含两个结构体变量,这些变量的类型仍然是结构体,分别是Gazebo_robot_info和Allocation_robot_info
    if(all_robots_.size()==0) //设置机器人的数量
        all_robots_.resize(_msg->gazebo_robots_info.size());

    // Gazebo_robot_info结构体,这些信息从gazebo中获取,在gazebo中机器人的信息
    Gazebo_robot_info _robot_info_tmp;

    //update the gazebo robots states for allocation
    // for循环实际上是借助_robot_info_tmp把_msg的信息有选择的放到了all_robots_这个vector中,不同的if就是选择不同
    for(unsigned int i=0;i<_msg->gazebo_robots_info.size();i++)
    {
        _robot_info_tmp.robot_ID=_msg->gazebo_robots_info[i].robot_ID;
        _robot_info_tmp.robot_pos.x_=_msg->gazebo_robots_info[i].robot_pose.position.x;
        _robot_info_tmp.robot_pos.y_=_msg->gazebo_robots_info[i].robot_pose.position.y;
        _robot_info_tmp.robot_ori=_msg->gazebo_robots_info[i].robot_pose.theta;
        _robot_info_tmp.robot_vel.x_=_msg->gazebo_robots_info[i].robot_twist.linear.x;
        _robot_info_tmp.robot_vel.y_=_msg->gazebo_robots_info[i].robot_twist.linear.y;
        _robot_info_tmp.robot_w=_msg->gazebo_robots_info[i].robot_twist.angular;

        //update the robot model when it is valid
        // 机器人如果power>0,则更新在gazebo中的机器人信息
        if(all_robots_[_robot_info_tmp.robot_ID].allocation_robot_info.isvalid)
            all_robots_[_robot_info_tmp.robot_ID].gazebo_robot_info=_robot_info_tmp;

        //the robot is placed on the init position, the expect_pos is robot_pos and update robot_ID
        // 这个-100与Core.hpp中105和116行的-100对应,后续就会被更改,只有在第一次的时候会是-100
        // 所以这个if是为了对all_robots_这个vector中的robot_ID进行赋值,此if只会在开始的时候执行一次
        if(all_robots_[_robot_info_tmp.robot_ID].allocation_robot_info.expect_pos.x_==-100)
        {
            all_robots_[_robot_info_tmp.robot_ID].allocation_robot_info.robot_ID=_robot_info_tmp.robot_ID;
            all_robots_[_robot_info_tmp.robot_ID].allocation_robot_info.expect_pos=_robot_info_tmp.robot_pos;
        }

        //if the robot_ID is me
        if(_robot_info_tmp.robot_ID==my_robot_.gazebo_robot_info.robot_ID)
        {
            my_robot_.allocation_robot_info.move_distance=my_robot_.allocation_robot_info.move_distance+_robot_info_tmp.robot_pos.distance(my_robot_.gazebo_robot_info.robot_pos);
            my_robot_.gazebo_robot_info=_robot_info_tmp;

            // 在初始化后,修改expect_pos,进入正常的任务模式中,-100专门为了初始化设计的
            if(my_robot_.allocation_robot_info.expect_pos.x_==-100)
                my_robot_.allocation_robot_info.expect_pos=_robot_info_tmp.robot_pos;
        }

        //if the robot_ID is not me, it is a obstacle
        else
            obstacles_.push_back(DPoint(_robot_info_tmp.robot_pos.x_,_robot_info_tmp.robot_pos.y_));
    }


    //first callback, if all_tasks is a null vector, resize its size according to the _msg from gazebo, and because the position of task will not change, the callback only be executed one time
    // 因为任务位置不会更新,所以只会初始化一次!
    if(all_tasks_.size()==0)
    {
        std::string full_path = ros::package::getPath("task_allocation") + "/src/Nodes.txt";
        std::ifstream loadData(full_path);
	    double tempX, tempY, tempT;
	    int tempF;                   //结束标志
        //all_tasks_.resize(_msg->gazebo_tasks_info.size());
        all_tasks_.resize(MAXNUM_TASK);
        Gazebo_task_info  _task_info_tmp;
        //update the gazebo tasks states for allocation
        // for循环实际上是借助_task_info_tmp变量把_msg的信息有选择的放到了all_tasks_这个vector中,不同的if就是选择不同
        //for(unsigned int j=0;j<_msg->gazebo_tasks_info.size();j++)
        for(unsigned int j=0;j<MAXNUM_TASK;j++)
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
           // _task_info_tmp.task_ID=_msg->gazebo_tasks_info[j].task_ID;
            _task_info_tmp.task_ID=tempF;
            // _task_info_tmp.task_pos.x_=_msg->gazebo_tasks_info[j].task_pose.x;
            // _task_info_tmp.task_pos.y_=_msg->gazebo_tasks_info[j].task_pose.y;
	   tempX= (tempX - origin_x) * singleGridSize;
           tempY=(origin_y - tempY) * singleGridSize;
            _task_info_tmp.task_pos.x_=tempX;
            _task_info_tmp.task_pos.y_=tempY;
            //update the task model when it is uncomplete
            if(!all_tasks_[_task_info_tmp.task_ID].allocation_task_info.iscomplete||!all_tasks_[_task_info_tmp.task_ID].allocation_task_info.isexplored)
                all_tasks_[_task_info_tmp.task_ID].gazebo_task_info=_task_info_tmp;

            all_tasks_[_task_info_tmp.task_ID].allocation_task_info.task_ID=_task_info_tmp.task_ID;
        }
    }
    std::cout << "update_gazebo_world finished" << std::endl;
	ros::Rate loop_rate(5);
	loop_rate.sleep();
}


void Task_Allocation_Plan::update_terminal_info(const allocation_common::terminal2robot_info::ConstPtr &_msg)
{
    std::cout << "update_terminal_info start" << std::endl;
all_robots_.resize(10);
    //first callback, if all_robots is a null vector, wait the gazebo_msg to initilize the vector
    if(all_robots_.size()==0){
    std::cout << "update_terminal all_robots_.size()==0" << std::endl;
        return;}
     std::cout << "update_terminal go on" << std::endl;
    // terminal_info_是Terminal2Robots_info类型,其是一个结构体,包含allocation_method和两个vector,vector成员的类型分别是Allocation_robot_info和Allocation_task_info
     terminal_info_.allocation_mode=_msg->allocation_mode;
    //terminal_info_.allocation_mode=0;
    // terminal_info_.greedorprobability=_msg->greedorprobability;
    terminal_info_.greedorprobability = 1; 
    // terminal_info_.allocation_method=_msg->allocation_method;
    terminal_info_.allocation_method=METHOD_CHOOSE;

    Allocation_robot_info _robot_info_tmp;
    int _num_task=0;
    int _num_target=0;

    //update the allocation_info of robots, exceput my_robot
    // for循环实际上是借助_robot_info_tmp把_msg的信息有选择的放到了all_robots_这个vector中,不同的if就是选择不同
    // 与update_gazebo_world()函数中的作用是不同的,前者的_robot_info_tmp变量是Gazebo_robot_info类型,后者_robot_info_tmp是Allocation_robot_info类型
    for(unsigned int i=0;i<_msg->all_allocation_robot_info.size();i++)
    {
        // if(_msg->all_allocation_robot_info[i].isupdate)
        // {
            if(_msg->all_allocation_robot_info[i].robot_ID!=my_robot_.allocation_robot_info.robot_ID)
            {
                _robot_info_tmp.robot_ID=_msg->all_allocation_robot_info[i].robot_ID;
                _robot_info_tmp.isvalid=_msg->all_allocation_robot_info[i].isvalid;
                _robot_info_tmp.robot_mode=_msg->all_allocation_robot_info[i].robot_mode;
                _robot_info_tmp.robot_power=_msg->all_allocation_robot_info[i].robot_power;
                _robot_info_tmp.which_target=_msg->all_allocation_robot_info[i].which_target;
                _robot_info_tmp.which_task=_msg->all_allocation_robot_info[i].which_task;
                _robot_info_tmp.expect_pos.x_=_msg->all_allocation_robot_info[i].expect_pos.position.x;
                _robot_info_tmp.expect_pos.y_=_msg->all_allocation_robot_info[i].expect_pos.position.y;

                all_robots_[_robot_info_tmp.robot_ID].allocation_robot_info=_robot_info_tmp;
            }
            else
            {
                //the robot_power is obtained from terminal, although the id is same, need to be update
                my_robot_.allocation_robot_info.robot_power=_msg->all_allocation_robot_info[i].robot_power;
                all_robots_[my_robot_.allocation_robot_info.robot_ID].allocation_robot_info=my_robot_.allocation_robot_info;
            }
        // }
    }
     std::cout << "update_terminal robot info " << std::endl;
    //first callback, if all_tasks is a null vector, wait the gazebo_msg to initilize the vector
    if(all_tasks_.size()==0)
        return;

    Allocation_task_info _task_info_tmp;

    //update the allocation_info of tasks
    // for循环实际上是借助_task_info_tmp把_msg的信息有选择的放到了all_tasks_这个vector中,不同的if就是选择不同,此时的if对应的是分配的方法
    // 与update_gazebo_world()函数中的作用是不同的,前者的_task_info_tmp变量是Gazebo_task_info类型,后者_task_info_tmp是Allocation_task_info类型
    for(unsigned int j=0;j<_msg->all_allocation_task_info.size();j++)
    {
        // if(_msg->all_allocation_task_info[j].isupdate)
        // {
            //obtain the current allocation_task_info, then the information will part update
            _task_info_tmp=all_tasks_[_msg->all_allocation_task_info[j].task_ID].allocation_task_info;
             if(terminal_info_.allocation_method==Prediction)
            {
                //the task/target has been allocated to me will not update these information
                if(_msg->all_allocation_task_info[j].task_ID!=my_robot_.allocation_robot_info.which_target&&
                   _msg->all_allocation_task_info[j].task_ID!=my_robot_.allocation_robot_info.which_task)
                {
                    _task_info_tmp.task_ID=_msg->all_allocation_task_info[j].task_ID;
                    _task_info_tmp.current_distance=_msg->all_allocation_task_info[j].current_distance;
                    _task_info_tmp.iscomplete=_msg->all_allocation_task_info[j].iscomplete;
                    _task_info_tmp.isexplored=_msg->all_allocation_task_info[j].isexplored;
                    _task_info_tmp.istarget=_msg->all_allocation_task_info[j].istarget;
                    _task_info_tmp.known_power=_msg->all_allocation_task_info[j].known_power;

                    //std::cout<<_task_info_tmp.isexplored<<std::endl;
                    all_tasks_[_task_info_tmp.task_ID].allocation_task_info=_task_info_tmp;
                }
                //the task/target has been allocated to me will update task_power
                else
                {
                    _task_info_tmp.task_ID=_msg->all_allocation_task_info[j].task_ID;
                   // _task_info_tmp.task_power=_msg->all_allocation_task_info[j].task_power;
                    _task_info_tmp.task_power=0;
                    all_tasks_[_task_info_tmp.task_ID].allocation_task_info=_task_info_tmp;
                }
            }
            else if(terminal_info_.allocation_method==Market)
            {
                bool _isMytask=false;
                bool _isMytarget=false;

                for(unsigned int m=0;m<my_robot_.allocation_robot_info.task_list.size();m++)
                    if(_msg->all_allocation_task_info[j].task_ID==my_robot_.allocation_robot_info.task_list[m])
                    {
                        _isMytask=true;
                        break;
                    }
                for(unsigned int n=0;n<my_robot_.allocation_robot_info.target_list.size();n++)
                    if(_msg->all_allocation_task_info[j].task_ID==my_robot_.allocation_robot_info.target_list[n])
                    {
                        _isMytarget=true;
                        break;
                    }
                //the task/target has been allocated to me will update task_power
                if(_isMytarget||_isMytask)
                {
                    _task_info_tmp.task_ID=_msg->all_allocation_task_info[j].task_ID;
                    _task_info_tmp.task_power=_msg->all_allocation_task_info[j].task_power;
                    all_tasks_[_task_info_tmp.task_ID].allocation_task_info=_task_info_tmp;
                }
                //the tasks/targets have been allocated to me will not update these information
                else
                {
                    _task_info_tmp.task_ID=_msg->all_allocation_task_info[j].task_ID;
                    _task_info_tmp.iscomplete=_msg->all_allocation_task_info[j].iscomplete;
                    _task_info_tmp.isexplored=_msg->all_allocation_task_info[j].isexplored;
                    _task_info_tmp.isallocated=_msg->all_allocation_task_info[j].isallocated;
                    _task_info_tmp.istarget=_msg->all_allocation_task_info[j].istarget;
                    _task_info_tmp.known_power=_msg->all_allocation_task_info[j].known_power;

                    all_tasks_[_task_info_tmp.task_ID].allocation_task_info=_task_info_tmp;
                }
            }
        // }
    }
    std::cout << "update_terminal task info " << std::endl;
        //record the uncomplete task and target
    // task和target的区别在后面有详细讲解
    for(unsigned int i=0;i<all_tasks_.size();i++)
    {
        if(!all_tasks_[i].allocation_task_info.iscomplete&&all_tasks_[i].allocation_task_info.istarget)
            _num_target++;
        else if(!all_tasks_[i].allocation_task_info.isexplored)
            _num_task++;
    }
    num_task_valid_=_num_task;
    num_target_valid_=_num_target;

    //for market_base method, the number of unallocated tasks/targets will also be recorded
    if(terminal_info_.allocation_method==Market)
    {
        _num_task=0;
        _num_target=0;
        for(unsigned int i=0;i<all_tasks_.size();i++)
            if(!all_tasks_[i].allocation_task_info.isallocated)
            {
                if(all_tasks_[i].allocation_task_info.istarget)
                    _num_target++;
                else
                    _num_task++;
            }
        num_task_unallocated_=_num_task;
        num_target_unallocated_=_num_target;
    }
    std::cout << "update_terminal_info finished" << std::endl;
	ros::Rate loop_rate(5);
	loop_rate.sleep();
}

void Task_Allocation_Plan::loopControl(const ros::TimerEvent &event)
{
    std::cout << "loopControl start" << std::endl;
    if(terminal_info_.allocation_mode==ALLOCATION_STOP)
        stopAllocation();
    else if(terminal_info_.allocation_mode==ALLOCATION_PAUSE)
        pauseAllocation();

    bid_new_task_=false;
    bid_new_target_=false;
    is_target_completed=false;
    is_task_explored=false;
    terminal_info_.allocation_method = METHOD_CHOOSE; 
    //terminal_info_.allocation_mode = 0;
    terminal_info_.greedorprobability = 1; 
    std::cout << terminal_info_.allocation_method << "method"<<std::endl;
    std::cout << my_robot_.allocation_robot_info.isvalid << "isvalid"<<std::endl;
    std::cout << terminal_info_.allocation_mode << "mode"<<std::endl;

    if(is_all_completed){
        // std::cout <<"------------______"<<std::endl;
        return;}
     
    else if(!my_robot_.allocation_robot_info.isvalid)
    {
        // std::cout <<"isvalid!!!!______"<<std::endl;
        if(terminal_info_.allocation_method==Market)
        {
            if(my_robot_.allocation_robot_info.target_list.size())
            {
                int _which_target=my_robot_.allocation_robot_info.target_list.back();
                all_tasks_[_which_target].allocation_task_info.isallocated=false;
                bid_new_target_=true;
                pubAllocation_info();
                my_robot_.allocation_robot_info.target_list.pop_back();
            }
            else if(my_robot_.allocation_robot_info.task_list.size())
            {
                int _which_task=my_robot_.allocation_robot_info.task_list.back();
                all_tasks_[_which_task].allocation_task_info.isallocated=false;
                bid_new_task_=true;
                pubAllocation_info();
                my_robot_.allocation_robot_info.task_list.pop_back();
            }
        }
        return;
    }
    // 用预测方法去完成任务分配
    else if(terminal_info_.allocation_mode==ALLOCATION_START&&terminal_info_.allocation_method==Prediction)
    {
        //  std::cout << "Prediction________________" << std::endl;
        //robot has complete the all task which allocated to it
        if(my_robot_.allocation_robot_info.which_target==-1&&my_robot_.allocation_robot_info.which_task==-1)
        {
            //all tasks have been completed
            if(!choose2hitOrexplore_())
            {
#ifdef debug
                std::cout<<"All tasks have been completed!"<<std::endl;
#endif
                is_all_completed=true;
                return;
                //allocation_timer_.stop();
            }
        }
        //the allocated target is not completed, then try to hit.
        else if(my_robot_.allocation_robot_info.which_target!=-1)
        {
            is_target_completed=try2hit_();
#ifdef debug
            if(is_target_completed)
                std::cout<<"Robot"<<my_robot_.allocation_robot_info.robot_ID<<" destroy the target "<<my_robot_.allocation_robot_info.which_target<<std::endl;
#endif
        }
        //the allocated task is not explored
        else if(my_robot_.allocation_robot_info.which_task!=-1)
        {
            is_task_explored=try2explore_();
#ifdef debug
            if(is_task_explored)
                std::cout<<"Robot"<<my_robot_.allocation_robot_info.robot_ID<<" explore the task "<<my_robot_.allocation_robot_info.which_task<<std::endl;
#endif
        }
        pubAllocation_info();

        //if the task or target is done or dropped, clear the task or target
        if((my_robot_.allocation_robot_info.robot_mode==EXPLORE&&is_task_explored)||my_robot_.allocation_robot_info.robot_mode==IDLE)
        {
            if(my_robot_.allocation_robot_info.robot_mode==EXPLORE&&is_task_explored)
                my_robot_.allocation_robot_info.robot_mode=IDLE;
            my_robot_.allocation_robot_info.which_task=-1;
        }
        if((my_robot_.allocation_robot_info.robot_mode==HIT&&is_target_completed)||my_robot_.allocation_robot_info.robot_mode==DAMAGE||my_robot_.allocation_robot_info.robot_mode==IDLE)
        {
            if(my_robot_.allocation_robot_info.robot_mode==HIT&&is_target_completed)
                my_robot_.allocation_robot_info.robot_mode=IDLE;
            my_robot_.allocation_robot_info.which_target=-1;
        }
        // setVelCommond();
        pubDrawing_info();
    }
    // 用基于市场的方法完成任务分配
    else if(terminal_info_.allocation_mode==ALLOCATION_START&&terminal_info_.allocation_method==Market)
    {
        // std::cout<<my_robot_.allocation_robot_info.target_list.size()<<"my_robot_.allocation_robot_info.target_list.size()"<<std::endl;
       // std::cout <<"market______"<<std::endl;
        //there are residual task/target that unallocated
        if(num_target_unallocated_!=0)
        {
            my_robot_.allocation_robot_info.robot_mode=PLAN;
            bid_new_target_=which2hit_();
            if(bid_new_target_)
            {
               // std::cout<<"bid_new_target_"<<std::endl;
                pubAllocation_info();
#ifdef debug
                std::cout<<"Robot"<<my_robot_.allocation_robot_info.robot_ID<<" bid a new target "<<my_robot_.allocation_robot_info.target_list.back()<<std::endl;
#endif
            }
        }
        else if(num_task_unallocated_!=0)
        {
            my_robot_.allocation_robot_info.robot_mode=PLAN;
            bid_new_task_=which2explore_();
            if(bid_new_task_)
            {
                // std::cout<<"bid_new_target_explore"<<std::endl;
                pubAllocation_info();
#ifdef debug
                std::cout<<"Robot"<<my_robot_.allocation_robot_info.robot_ID<<" bid a new task "<<my_robot_.allocation_robot_info.task_list.back()<<std::endl;
#endif
            }
        }
         else if(!num_target_valid_&&!num_task_valid_)
        {
#ifdef debug
            std::cout<<"All tasks have been completed!"<<std::endl;
#endif

            is_all_completed=true;
            return;
        }
        
        //the allocated target is not complete
        if(my_robot_.allocation_robot_info.target_list.size()!=0)
        {
            // std::cout<<"try2hit_"<<std::endl;
            is_target_completed=try2hit_();
            pubAllocation_info();
            if(is_target_completed)
            {
                //the target has been completed, delete it from the target_list
#ifdef debug
                std::cout<<"Robot"<<my_robot_.allocation_robot_info.robot_ID<<" destroy the target "<<my_robot_.allocation_robot_info.target_list.front()<<std::endl;
#endif
                my_robot_.allocation_robot_info.target_list.erase(my_robot_.allocation_robot_info.target_list.begin());
            }
        }

        else if(my_robot_.allocation_robot_info.task_list.size()!=0)
        {
           // std::cout<<"try2explore_"<<std::endl;
            my_robot_.allocation_robot_info.expect_pos=my_robot_.gazebo_robot_info.robot_pos;
            is_task_explored=try2explore_();
            pubAllocation_info();
            if(is_task_explored)
            {
                //the task has been explored, delete it from the task_list
#ifdef debug
                std::cout<<"Robot"<<my_robot_.allocation_robot_info.robot_ID<<" explore the task "<<my_robot_.allocation_robot_info.task_list.front()<<std::endl;
#endif
                my_robot_.allocation_robot_info.task_list.erase(my_robot_.allocation_robot_info.task_list.begin());
            }
        }
        else if(!num_target_valid_&&!num_task_valid_)
        {
#ifdef debug
            std::cout<<"All tasks have been completed!"<<std::endl;
#endif

            is_all_completed=true;
            return;
        }
        // setVelCommond();
        pubDrawing_info();
    }
    std::cout << "loopControl finished" << std::endl;
}


void Task_Allocation_Plan::pubAllocation_info()
{
    allocation_common::allocation2terminal_info _allocation_info;
    nav_msgs::Path which_task_pub_info;
    which_task_pub_info.poses.clear();
    which_task_pub_info.poses.resize(1);
    int _which_target=-1;
    int _which_task=-1;

    _allocation_info.robot_info.robot_ID=my_robot_.allocation_robot_info.robot_ID;
    _allocation_info.robot_info.robot_mode=my_robot_.allocation_robot_info.robot_mode;
    _allocation_info.robot_info.isvalid=my_robot_.allocation_robot_info.isvalid;
    _allocation_info.robot_info.move_distance=my_robot_.allocation_robot_info.move_distance;

    // 不同方法分配的_which_target和_which_task不同
    // 基于市场的方法
    if(terminal_info_.allocation_method==Prediction)
    {
        _allocation_info.robot_info.which_task=my_robot_.allocation_robot_info.which_task;
        _allocation_info.robot_info.which_target=my_robot_.allocation_robot_info.which_target;
        _which_target=my_robot_.allocation_robot_info.which_target;
        _which_task=my_robot_.allocation_robot_info.which_task;
    }
    else{
    _allocation_info.robot_info.expect_pos.position.x=my_robot_.allocation_robot_info.expect_pos.x_;
    _allocation_info.robot_info.expect_pos.position.y=my_robot_.allocation_robot_info.expect_pos.y_;
    if(bid_new_target_)
        _which_target=my_robot_.allocation_robot_info.target_list.back();
    else if(is_target_completed)
        _which_target=my_robot_.allocation_robot_info.target_list.front();
    else if(bid_new_task_)
        _which_task=my_robot_.allocation_robot_info.task_list.back();
    else if(is_task_explored)
        _which_task=my_robot_.allocation_robot_info.task_list.front();
    }
    // 当my_robot_的_which_target与_which_task不为-1时情况
    if(_which_target!=-1)
    {
        Allocation_task_info _target_info=all_tasks_[_which_target].allocation_task_info;

        _allocation_info.task_info.task_ID=_target_info.task_ID;
        _allocation_info.task_info.current_distance=_target_info.current_distance;
        _allocation_info.task_info.isallocated=_target_info.isallocated;
        if(my_robot_.allocation_robot_info.robot_mode==HIT||my_robot_.allocation_robot_info.robot_mode==DAMAGE)
        {
            _allocation_info.task_info.known_power=_target_info.known_power;
            _allocation_info.task_info.iscomplete=_target_info.iscomplete;
        }
    }
    else if(_which_task!=-1)
    {
        Allocation_task_info _task_info=all_tasks_[_which_task].allocation_task_info;

        _allocation_info.task_info.task_ID=_task_info.task_ID;
        _allocation_info.task_info.current_distance=_task_info.current_distance;
        _allocation_info.task_info.isallocated=_task_info.isallocated;
        if(my_robot_.allocation_robot_info.robot_mode==EXPLORE)
        {
            _allocation_info.task_info.known_power=_task_info.known_power;
            _allocation_info.task_info.istarget=_task_info.istarget;
            _allocation_info.task_info.iscomplete=_task_info.iscomplete;
            _allocation_info.task_info.isexplored=_task_info.isexplored;
        }
         std::cout << ".task_pos.x_" <<all_tasks_[_which_task].gazebo_task_info.task_pos.x_<<
   "  " <<all_tasks_[_which_task].gazebo_task_info.task_pos.y_ <<std::endl;
        which_task_pub_info.poses[0].pose.position.x = all_tasks_[_which_task].gazebo_task_info.task_pos.x_;
        which_task_pub_info.poses[0].pose.position.y = all_tasks_[_which_task].gazebo_task_info.task_pos.y_;
        which_task_pub_info.poses[0].pose.position.z = 0;
        if( terminal_info_.allocation_mode == ALLOCATION_START){
        which_task_pub.publish(which_task_pub_info);}
    }
    else
        _allocation_info.task_info.task_ID=-1;

    allocation2terminal_pub_.publish(_allocation_info);  
    
}


bool Task_Allocation_Plan::which2hit_()
{
    // std::cout <<"which2hit_()"<<std::endl;
    // 若未被分配的目标数目是0,则返回false
    if(!num_target_unallocated_)
        return false;

    // less_distance是my_robot_计算的距离
    // distance是其它机器人计算的距离
    float less_distance,distance;
    for(unsigned int i=0;i<all_tasks_.size();i++)
        if(all_tasks_[i].allocation_task_info.istarget==true &&
           all_tasks_[i].allocation_task_info.iscomplete==false &&
           all_tasks_[i].allocation_task_info.isallocated==false &&
           all_tasks_[i].allocation_task_info.task_power<my_robot_.allocation_robot_info.robot_power)
        {
            // 计算my_robot_距离task的距离
            less_distance=my_robot_.allocation_robot_info.expect_pos.distance(all_tasks_[i].gazebo_task_info.task_pos);
            for(unsigned int j=0;j<all_robots_.size();j++)
            {
                if(all_robots_[j].allocation_robot_info.isvalid &&
                   all_robots_[j].allocation_robot_info.robot_ID!=my_robot_.allocation_robot_info.robot_ID&&
                   all_tasks_[i].allocation_task_info.task_power<all_robots_[j].allocation_robot_info.robot_power)
                {
                    //计算其它机器人距离同一个task的距离
                    distance=all_robots_[j].allocation_robot_info.expect_pos.distance(all_tasks_[i].gazebo_task_info.task_pos);

                    //如果有机器人到task的距离比my_robot_小,则任务不会分配给my_robot_
                    if(distance<less_distance||(distance==less_distance&&my_robot_.allocation_robot_info.robot_ID>all_robots_[j].allocation_robot_info.robot_ID))
                        return false;
                }
                //遍历了所有机器人,到最后一个了,仍然未执行上面那句return false,则说明没有机器人的距离比my_robot_还小,则任务分配给my_robot_
                if(j==all_robots_.size()-1)
                {
                    my_robot_.allocation_robot_info.target_list.push_back(all_tasks_[i].allocation_task_info.task_ID);
                    my_robot_.allocation_robot_info.expect_pos=all_tasks_[i].gazebo_task_info.task_pos;
                    all_tasks_[i].allocation_task_info.isallocated=true;
                    return true;
                }
            }
        }
    //no target has been added to the list
    return false;
}

bool Task_Allocation_Plan::which2explore_()
{
   
    // 若未被分配的task数目是0,则返回false
    if(!num_task_unallocated_)
    {
       //std::cout<<"未被分配的task数目是0"<<std::endl;
        return false;
    }
        

    // less_distance是my_robot_计算的距离
    // distance是其它机器人计算的距离
    float less_distance,distance;
    vector<int> task_list;
    //std::cout<<"all_tasks_.size()"<<all_tasks_.size()<<std::endl;
    for(unsigned int i=0;i<all_tasks_.size();i++)
        task_list.push_back(i);
    

    for(unsigned int i=0;i<all_tasks_.size()-1;i++)
    {
        for(unsigned int j=0;j<all_tasks_.size()-(i+1);j++)
        {
            double tmp_dis1=my_robot_.allocation_robot_info.expect_pos.distance(all_tasks_[task_list[j]].gazebo_task_info.task_pos);
            double tmp_dis2=my_robot_.allocation_robot_info.expect_pos.distance(all_tasks_[task_list[j+1]].gazebo_task_info.task_pos);
            if(tmp_dis1>tmp_dis2)
            {
                int tmp_list=task_list[j];
                task_list[j]=task_list[j+1];
                task_list[j+1]=tmp_list;
            }
        }
    }

    //choose the nearest robot for every unallocated task
    // 三个for循环嵌套, i:all_tasks_, j:all_robots_, p:my_robot_
    for(unsigned int i=0;i<all_tasks_.size();i++)
        if(all_tasks_[task_list[i]].allocation_task_info.istarget==false &&
           all_tasks_[task_list[i]].allocation_task_info.isexplored==false &&
           all_tasks_[task_list[i]].allocation_task_info.isallocated==false)
        {
            // 计算my_robot_距离task的距离
            less_distance=my_robot_.allocation_robot_info.expect_pos.distance(all_tasks_[task_list[i]].gazebo_task_info.task_pos);
            for(unsigned int j=0;j<all_robots_.size();j++)
            {
                if(all_robots_[j].allocation_robot_info.isvalid && all_robots_[j].allocation_robot_info.robot_ID!=my_robot_.allocation_robot_info.robot_ID)
                {
                    //计算其它机器人距离同一个task的距离
                    distance=all_robots_[j].allocation_robot_info.expect_pos.distance(all_tasks_[task_list[i]].gazebo_task_info.task_pos);

                    //如果有机器人到task的距离比my_robot_小,则任务不会分配给my_robot_
                    if(distance<less_distance||(distance==less_distance&&my_robot_.allocation_robot_info.robot_ID>all_robots_[j].allocation_robot_info.robot_ID))
                        return false;
                }
                //只有一个机器人即all_robots_.size()==1(j只有一次循环),直接用Dijstra算法对task进行排序
                if(j==all_robots_.size()-1 && all_robots_.size()==1)
                {
                    std::vector<int>::iterator it;
                    it = my_robot_.allocation_robot_info.task_list.begin();
                    float add_distance;
                    float min_add_distance=1000;
                    int insert_label=my_robot_.allocation_robot_info.task_list.size();
                    // Dijstra算法,计算task到task的距离
                    // task的index从(p-1 -> i) + (i -> p) - (p-1 -> p)的距离,没有启发值所以不是A*
                    // 寻找在my_robot_的task_list中,my_robot_距离哪个task最近,找到后赋值给min_add_distance,并且把index传给insert_label
                    for(unsigned int p=1;p<my_robot_.allocation_robot_info.task_list.size()+1;p++)
                    {
                        // 因为是my_robot_的最后一个task,所以直接计算与第i个task的距离
                        if(p==my_robot_.allocation_robot_info.task_list.size())
                            add_distance=all_tasks_[my_robot_.allocation_robot_info.task_list[p-1]].gazebo_task_info.task_pos.distance(all_tasks_[task_list[i]].gazebo_task_info.task_pos);
                        else // 如果p-1经过i到p的距离 比 p-1直接到p距离小,则p-1到p的最短路径不是p-1 -> p而是p-1 -> i -> p, Dijstra算法的核心
                            add_distance=all_tasks_[my_robot_.allocation_robot_info.task_list[p-1]].gazebo_task_info.task_pos.distance(all_tasks_[task_list[i]].gazebo_task_info.task_pos)
                                        +all_tasks_[task_list[i]].gazebo_task_info.task_pos.distance(all_tasks_[my_robot_.allocation_robot_info.task_list[p]].gazebo_task_info.task_pos)
                                        -all_tasks_[my_robot_.allocation_robot_info.task_list[p-1]].gazebo_task_info.task_pos.distance(all_tasks_[my_robot_.allocation_robot_info.task_list[p]].gazebo_task_info.task_pos);

                        if(add_distance<min_add_distance)
                        {
                            min_add_distance=add_distance;
                            insert_label=p;
                        }
                    }
                    // 更新my_robot_的task_list,最短路径遍历这些点
                    if(insert_label==my_robot_.allocation_robot_info.task_list.size())
                    {
                        my_robot_.allocation_robot_info.task_list.push_back(all_tasks_[task_list[i]].allocation_task_info.task_ID);
                        my_robot_.allocation_robot_info.expect_pos=all_tasks_[task_list[i]].gazebo_task_info.task_pos;
                    }
                    else
                        my_robot_.allocation_robot_info.task_list.insert(it+insert_label,all_tasks_[task_list[i]].allocation_task_info.task_ID);

                    all_tasks_[task_list[i]].allocation_task_info.isallocated=true;
                    return true;
                }
                // 遍历了所有机器人,到最后一个了,则说明没有机器人的距离比my_robot_还小,则任务分配给了my_robot_
                else if(j==all_robots_.size()-1)
                {
                    my_robot_.allocation_robot_info.task_list.push_back(all_tasks_[task_list[i]].allocation_task_info.task_ID);
                    my_robot_.allocation_robot_info.expect_pos=all_tasks_[task_list[i]].gazebo_task_info.task_pos;
                    all_tasks_[task_list[i]].allocation_task_info.isallocated=true;
                    return true;
                }
            }
        }
    //no task has been added to the list
    return false;
}

bool Task_Allocation_Plan::choose2hitOrexplore_()
{
    //initialization the variable
    std::vector<double> distance_vec;
    std::vector<int> possible_vec;
    std::vector<int> power_vec;
    std::vector<int> lab_vec;
    float distance=0;
    int sum_possible=0;
    int _which_target=-1;
    int _which_task=-1;

    // 所有tatget和task都的valid都是无效的
    // num_target_valid_:target有效的数目
    // num_task_valid_:task有效的数目
    if(!num_target_valid_&&!num_task_valid_)
        return false;

    //there are targets which uncomplete
    if(num_target_valid_>0)
    {
        //make choice base on greed or probability
        if(!terminal_info_.greedorprobability)
        {
            float less_distance=1000;

            //calculate the distance between my_robot and each uncomplete target
            // greed or probability方法中,计算所有的uncomplete target距离my_robot的距离,如果这个距离小于less_distance=1000则把这个task_ID分配给my_robot_的which_target
            for(unsigned int i=0;i<all_tasks_.size();i++)
                if(all_tasks_[i].allocation_task_info.istarget==true&&all_tasks_[i].allocation_task_info.iscomplete==false
                   &&my_robot_.allocation_robot_info.robot_power>=all_tasks_[i].allocation_task_info.known_power
                   &&my_robot_.gazebo_robot_info.robot_pos.distance(all_tasks_[i].gazebo_task_info.task_pos)<all_tasks_[i].allocation_task_info.current_distance)
                {
                    distance=my_robot_.gazebo_robot_info.robot_pos.distance(all_tasks_[i].gazebo_task_info.task_pos);
                    if(distance<less_distance)
                    {
                        less_distance=distance;
                        my_robot_.allocation_robot_info.which_target=all_tasks_[i].allocation_task_info.task_ID;
                    }
                }

            // 分配了task给机器人,将机器人的mode修改为PLAN,同时更新这个task的current_distance
            if(my_robot_.allocation_robot_info.which_target!=-1)
            {
                my_robot_.allocation_robot_info.robot_mode=PLAN;
                _which_target=my_robot_.allocation_robot_info.which_target;
                all_tasks_[_which_target].allocation_task_info.current_distance=my_robot_.gazebo_robot_info.robot_pos.distance(all_tasks_[_which_target].gazebo_task_info.task_pos);
#ifdef debug
                std::cout<<"robot"<<my_robot_.allocation_robot_info.robot_ID<<" selects target "<<_which_target<<std::endl;
#endif
                return true;
            }
        }
        else // greed or probability method
        {
            for(unsigned int i=0;i<all_tasks_.size();i++)
                // 计算my_robot和所有的uncomplete target的距离
                // 这个if与上面的greed or probability方法中的if(539行)不同,最后多个"-3*LOCATION_ERROR"
                if(all_tasks_[i].allocation_task_info.istarget==true&&all_tasks_[i].allocation_task_info.iscomplete==false
                   &&my_robot_.allocation_robot_info.robot_power>=all_tasks_[i].allocation_task_info.known_power
                   &&my_robot_.gazebo_robot_info.robot_pos.distance(all_tasks_[i].gazebo_task_info.task_pos)<all_tasks_[i].allocation_task_info.current_distance-3*LOCATION_ERROR)
                {
                    //cout<<all_tasks_[i].allocation_task_info.task_ID<<" "<<all_tasks_[i].allocation_task_info.current_distance<<endl;
                    distance=my_robot_.gazebo_robot_info.robot_pos.distance(all_tasks_[i].gazebo_task_info.task_pos);
                    distance_vec.push_back(distance);
                    lab_vec.push_back(i);
                }
            //choose the target based on the probability
            if(distance_vec.size()!=0)
                for(unsigned int i=0;i<distance_vec.size();i++)
                {
                    if(distance_vec[i]!=0)
                        sum_possible=sum_possible+1000/distance_vec[i];
                    else
                    {
                        my_robot_.allocation_robot_info.which_target=all_tasks_[lab_vec[i]].allocation_task_info.task_ID;
                        my_robot_.allocation_robot_info.robot_mode=PLAN;
                        return true;
                    }
                    possible_vec.push_back(sum_possible);
                }
#ifdef debug
            else
                std::cout<<"There is not applicable target for Robot"<<my_robot_.allocation_robot_info.robot_ID<<std::endl;
#endif
            if(possible_vec.size()>0)
            {
                srand(clock());
                int tmp=rand()%(sum_possible);
                for(unsigned int i=0;i<possible_vec.size();i++)
                    if(tmp<possible_vec[i])
                    {
                        my_robot_.allocation_robot_info.which_target=all_tasks_[lab_vec[i]].allocation_task_info.task_ID;
                        my_robot_.allocation_robot_info.robot_mode=PLAN;
                        _which_target=my_robot_.allocation_robot_info.which_target;
                        all_tasks_[_which_target].allocation_task_info.current_distance=my_robot_.gazebo_robot_info.robot_pos.distance(all_tasks_[_which_target].gazebo_task_info.task_pos);
#ifdef debug
                        std::cout<<"robot"<<my_robot_.allocation_robot_info.robot_ID<<" selects target "<<_which_target<<std::endl;
#endif
                        return true;
                    }
            }
        }
    }

    //if do not find the target, reset the reliable for task selecting
    distance_vec.clear();
    possible_vec.clear();
    power_vec.clear();
    lab_vec.clear();
    distance=0;
    sum_possible=0;
    //there is no available target, but there are tasks uncomplete
    if(num_task_valid_>0)
    {
        if(!terminal_info_.greedorprobability)
        {
            float less_distance2=1000;

            //choose the nearest region for exploration
            for(unsigned int i=0;i<all_tasks_.size();i++)
                if(all_tasks_[i].allocation_task_info.istarget==false&&all_tasks_[i].allocation_task_info.isexplored==false
                   &&my_robot_.gazebo_robot_info.robot_pos.distance(all_tasks_[i].gazebo_task_info.task_pos)<all_tasks_[i].allocation_task_info.current_distance)
                {
                    distance=my_robot_.gazebo_robot_info.robot_pos.distance(all_tasks_[i].gazebo_task_info.task_pos);
                    if(distance<less_distance2)
                    {
                        less_distance2=distance;
                        my_robot_.allocation_robot_info.which_task=all_tasks_[i].allocation_task_info.task_ID;
                    }
                }
            if(my_robot_.allocation_robot_info.which_task!=-1)
            {
                my_robot_.allocation_robot_info.robot_mode=PLAN;
                _which_task=my_robot_.allocation_robot_info.which_task;
                all_tasks_[_which_task].allocation_task_info.current_distance=my_robot_.gazebo_robot_info.robot_pos.distance(all_tasks_[_which_task].gazebo_task_info.task_pos);
#ifdef debug
                std::cout<<"robot"<<my_robot_.allocation_robot_info.robot_ID<<" selects task "<<_which_task<<std::endl;
#endif
                return true;
            }
        }
        else // greed or probability method
        {
            for(unsigned int i=0;i<all_tasks_.size();i++)
                if(all_tasks_[i].allocation_task_info.istarget==false&&all_tasks_[i].allocation_task_info.isexplored==false
                   &&my_robot_.gazebo_robot_info.robot_pos.distance(all_tasks_[i].gazebo_task_info.task_pos)<all_tasks_[i].allocation_task_info.current_distance-3*LOCATION_ERROR)
                {
                    distance=my_robot_.gazebo_robot_info.robot_pos.distance(all_tasks_[i].gazebo_task_info.task_pos);
                    distance_vec.push_back(distance);
                    lab_vec.push_back(i);
                }
            //choose the task base on the probability
            if(distance_vec.size()!=0)
                for(unsigned int i=0;i<distance_vec.size();i++)
                {
                    if(distance_vec[i]!=0)
                        sum_possible=sum_possible+1000/distance_vec[i];
                    else
                    {
                        my_robot_.allocation_robot_info.which_task=all_tasks_[lab_vec[i]].allocation_task_info.task_ID;
                        my_robot_.allocation_robot_info.robot_mode=PLAN;
                        return true;
                    }
                    possible_vec.push_back(sum_possible);
                }
#ifdef debug
            else
                std::cout<<"There is not applicable task for Robot"<<my_robot_.allocation_robot_info.robot_ID<<std::endl;
#endif
            if(possible_vec.size()>0)
            {
                srand(clock());
                int tmp=rand()%(sum_possible);
                for(unsigned int i=0;i<possible_vec.size();i++)
                    if(tmp<possible_vec[i])
                    {
//                        std::cout<<lab_vec[i]<<": "<<all_tasks_[lab_vec[i]].allocation_task_info.task_ID<<std::endl;
                        my_robot_.allocation_robot_info.which_task=all_tasks_[lab_vec[i]].allocation_task_info.task_ID;
                        my_robot_.allocation_robot_info.robot_mode=PLAN;
                        _which_task=my_robot_.allocation_robot_info.which_task;
                        all_tasks_[_which_task].allocation_task_info.current_distance=my_robot_.gazebo_robot_info.robot_pos.distance(all_tasks_[_which_task].gazebo_task_info.task_pos);
#ifdef debug
                        std::cout<<"robot"<<my_robot_.allocation_robot_info.robot_ID<<" selects task "<<_which_task<<std::endl;
#endif
                        return true;
                    }
            }
        }
    }
    return true;
}

bool Task_Allocation_Plan::try2hit_()
{
    static int _hit_time=0;
    Task_info _my_target; // Task_info是一个结构体类型,包含两个结构体变量,变量的类型分别是Gazebo_task_info和Allocation_task_info
    int _which_target; // target的index
    if(terminal_info_.allocation_method==Prediction)
        _which_target=my_robot_.allocation_robot_info.which_target;
    else
        _which_target=my_robot_.allocation_robot_info.target_list.front();
    _my_target=all_tasks_[_which_target];

    // 在Prediction或DQN方法中,需要比较不同机器人到同一个task的距离
    if(terminal_info_.allocation_method==Prediction)
        for(unsigned int i=0;i<all_robots_.size();i++)
            //there is an other robot ready for this target except me
            if(all_robots_[i].allocation_robot_info.robot_ID!=my_robot_.allocation_robot_info.robot_ID
                    &&all_robots_[i].allocation_robot_info.which_target==my_robot_.allocation_robot_info.which_target
                    &&all_robots_[i].allocation_robot_info.isvalid)
            {
                int distance_1=my_robot_.gazebo_robot_info.robot_pos.distance(_my_target.gazebo_task_info.task_pos);
                int distance_2=all_robots_[i].gazebo_robot_info.robot_pos.distance(_my_target.gazebo_task_info.task_pos);
                //other robot's distance is littler
                if(distance_1>distance_2)
                {
                    //drop this target
                    my_robot_.allocation_robot_info.robot_mode=IDLE;
#ifdef debug
                    std::cout<<"robot"<<my_robot_.allocation_robot_info.robot_ID<<" drops target "<<my_robot_.allocation_robot_info.which_target<<" because of robot "<<i<<std::endl;
#endif
                    return false;
                }
            }

    my_robot_.allocation_robot_info.robot_mode=EXECUTE;
     //there is no conflict, continue to carry out this target
    //距task的距离大于0.2
    if(my_robot_.gazebo_robot_info.robot_pos.distance(_my_target.gazebo_task_info.task_pos)>LOCATION_ERROR)
    {
        //my_behaviour_->move2Positionwithobs(3,6,_my_target.gazebo_task_info.task_pos,4,my_robot_.gazebo_robot_info.robot_pos,my_robot_.gazebo_robot_info.robot_ori);
        all_tasks_[_which_target].allocation_task_info.current_distance=my_robot_.gazebo_robot_info.robot_pos.distance(_my_target.gazebo_task_info.task_pos);
        return false;
    }
    else
    {
        //if the target power bigger than the robot power, the robot will be destroyed
        // target的power大于机器人的power,则机器人被摧毁
        if(_my_target.allocation_task_info.task_power>my_robot_.allocation_robot_info.robot_power)
        {
            my_robot_.allocation_robot_info.robot_mode=DAMAGE;
            my_robot_.allocation_robot_info.isvalid=false;
            all_tasks_[_which_target].allocation_task_info.known_power=my_robot_.allocation_robot_info.robot_power+1;
            if(terminal_info_.allocation_method==Prediction)
                all_tasks_[_which_target].allocation_task_info.current_distance=1000;
            else
                all_tasks_[_which_target].allocation_task_info.isallocated=false;
            return false;
        }
        else
        {
            //the target is complete
            my_robot_.allocation_robot_info.robot_mode=HIT;
            if(_hit_time<HIT_TIME)
            {
                _hit_time++;
                return false;
            }
            else
            {
                _hit_time=0;
                all_tasks_[_which_target].allocation_task_info.iscomplete=true;
                return true;
            }
        }
    }
}

bool Task_Allocation_Plan::try2explore_()
{
    //  std::cout<<"try2explore_ininini"<<std::endl;
    static int _explore_time=0;
    Task_info _my_task; // Task_info是一个结构体类型,包含两个结构体变量,变量的类型分别是Gazebo_task_info和Allocation_task_info
    int _which_task;
    if(terminal_info_.allocation_method==Prediction)
        _which_task=my_robot_.allocation_robot_info.which_task;
    else
        _which_task=my_robot_.allocation_robot_info.task_list.front();
    _my_task=all_tasks_[_which_task];

    if(terminal_info_.allocation_method==Prediction)
        for(unsigned int i=0;i<all_robots_.size();i++)
            //there is an other robot ready for this task except me
            if(all_robots_[i].allocation_robot_info.robot_ID!=my_robot_.allocation_robot_info.robot_ID
                    &&all_robots_[i].allocation_robot_info.which_task==my_robot_.allocation_robot_info.which_task
                    &&all_robots_[i].allocation_robot_info.isvalid)
            {
                int distance_1=my_robot_.gazebo_robot_info.robot_pos.distance(_my_task.gazebo_task_info.task_pos);
                int distance_2=all_robots_[i].gazebo_robot_info.robot_pos.distance(_my_task.gazebo_task_info.task_pos);
                //other robot's distance is littler
                if(distance_1>distance_2)
                {
                    //drop this task
                    my_robot_.allocation_robot_info.robot_mode=IDLE;
#ifdef debug
                    std::cout<<"robot"<<my_robot_.allocation_robot_info.robot_ID<<" drops task "<<my_robot_.allocation_robot_info.which_task<<" because of robot "<<i<<std::endl;
#endif
                    return false;
                }
            }

    my_robot_.allocation_robot_info.robot_mode=EXECUTE;
    if(my_robot_.gazebo_robot_info.robot_pos.distance(_my_task.gazebo_task_info.task_pos)>LOCATION_ERROR)
    {
       // my_behaviour_->move2Positionwithobs(3,6,_my_task.gazebo_task_info.task_pos,4,my_robot_.gazebo_robot_info.robot_pos,my_robot_.gazebo_robot_info.robot_ori);
        all_tasks_[_which_task].allocation_task_info.current_distance=my_robot_.gazebo_robot_info.robot_pos.distance(_my_task.gazebo_task_info.task_pos);
        return false;
    }
    //if reach the task pos
    else
    {
        //explore the task
        my_robot_.allocation_robot_info.robot_mode=EXPLORE;
        // if(_explore_time<EXPLORE_TIME)
        // {
        //     _explore_time++;
        //     return false;
        // }
        // else
        // {
            _explore_time=0;
            all_tasks_[_which_task].allocation_task_info.isexplored=true;
            //this is a target
            if(_my_task.allocation_task_info.task_power>0)
            {
                all_tasks_[_which_task].allocation_task_info.known_power=1;
                all_tasks_[_which_task].allocation_task_info.istarget=true;
                if(_my_task.allocation_task_info.task_power>my_robot_.allocation_robot_info.robot_power)
                {
#ifdef debug
                    std::cout<<"Robot"<<my_robot_.allocation_robot_info.robot_ID<<" is destroyed!"<<std::endl;
#endif
                    my_robot_.allocation_robot_info.robot_mode=DAMAGE;
                    my_robot_.allocation_robot_info.isvalid=false;
                    all_tasks_[_which_task].allocation_task_info.known_power=my_robot_.allocation_robot_info.robot_power+1;
                    if(terminal_info_.allocation_method==Prediction)
                        all_tasks_[_which_task].allocation_task_info.current_distance=1000;
                    else
                        all_tasks_[_which_task].allocation_task_info.isallocated=false;
            }
            else
                {
                    all_tasks_[_which_task].allocation_task_info.iscomplete=true;
                }
            }
            else
            {
                all_tasks_[_which_task].allocation_task_info.iscomplete=true;
            }
            return true;
        // }            
    }
}

void Task_Allocation_Plan::setVelCommond()
{
    allocation_common::robot2gazebo_info _robot2gazebo_info;

   // _robot2gazebo_info.robot_twist.linear.x=my_behaviour_->app_vx_;
   // _robot2gazebo_info.robot_twist.linear.y=my_behaviour_->app_vy_;
   // _robot2gazebo_info.robot_twist.angular=my_behaviour_->app_w_;
    _robot2gazebo_info.current_mode=my_robot_.allocation_robot_info.robot_mode;

    //clear velocity
 //   my_behaviour_->app_vx_=0;
 //   my_behaviour_->app_vy_=0;
  //  my_behaviour_->app_w_=0;

    //robot2gazebo_pub_.publish(_robot2gazebo_info);
}

void Task_Allocation_Plan::pubDrawing_info()
{
    geometry_msgs::Point _drawing_info;

    _drawing_info.z=my_robot_.allocation_robot_info.robot_mode;
    _drawing_info.x=my_robot_.gazebo_robot_info.robot_pos.x_;
    _drawing_info.y=my_robot_.gazebo_robot_info.robot_pos.y_;

    drawing_pub_.publish(_drawing_info);
}

void Task_Allocation_Plan::pauseAllocation()
{
    //clear velocity
   // my_behaviour_->app_vx_=0;
   // my_behaviour_->app_vy_=0;
  //  my_behaviour_->app_w_=0;
    // setVelCommond();
}

/// \brief when the controlterminal click "STOP", reset all robots and tasks
void Task_Allocation_Plan::stopAllocation()
{
    //if these allocation info have reset yet
    if(all_robots_.size()==0)
        return;
    //clear velocity
  //  my_behaviour_->app_vx_=0;
  //  my_behaviour_->app_vy_=0;
  //  my_behaviour_->app_w_=0;

    //reset
    num_task_valid_=1;
    num_target_valid_=0;
    num_task_unallocated_=1;
    num_target_unallocated_=0;
    is_world_update_=false;
    bid_new_task_=false;
    bid_new_target_=false;
    is_target_completed=false;
    is_task_explored=false;
    is_all_completed=false;
    all_tasks_.clear();
    all_robots_.clear();

    my_robot_.allocation_robot_info.robot_reset();
    // setVelCommond();
}


int main(int argc, char **argv)
{
    ros::init(argc,argv,"realworld_task_allocation_node4");
    ros::Time::init();
    Task_Allocation_Plan Task_Allocation_Plan;
  ros::MultiThreadedSpinner s(3);
    ros::spin(s);
    return 0;
}
