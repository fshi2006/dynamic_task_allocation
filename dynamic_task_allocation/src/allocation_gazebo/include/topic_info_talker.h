#ifndef TOPIC_INFO_TALKER_H
#define TOPIC_INFO_TALKER_H

#include <Core.hpp>
//#include <QThread>
#include <std_msgs/Header.h>
#include <std_msgs/String.h>
#include <std_msgs/Char.h>
#include <allocation_common/terminal2robot_info.h>
#include <allocation_common/allocation2terminal_info.h>

class Topic_Info_talker
{
public:
    /**ros items**/
    boost::shared_ptr<ros::NodeHandle> nh_;
    ros::Subscriber  allocation2terminal_sub_[MAXNUM_AGENT];
    ros::Subscriber  startmsg_sub_;
    ros::Publisher   terminal2robot_pub_;
    ros::Timer       terminalinfo_publish_timer_;

    allocation_common::terminal2robot_info  terminal2robot_pub_info_;
  
    Terminal2Robots_info terminal2robots_info;

    //record the time that the flag of update will hold
    vector<int> timeforupdatetask_;
    vector<int> timeforupdaterobot_;
    ros::Timer loop_timer_;
    void timerCb();
    void startmsg_cb(const std_msgs::Char::ConstPtr &msg);
public:
    //Topic_Info_talker();
    void update_allocation_info(const allocation_common::allocation2terminal_info::ConstPtr & _msg, int topic_id);
    void publish(const ros::TimerEvent &);
    //~Topic_Info_talker();
    void init();
};

#endif // TOPIC_INFO_TALKER_H
