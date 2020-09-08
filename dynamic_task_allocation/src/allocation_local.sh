#!/bin/bash
# Set the number of robots
declare -i j

robots_num=$(rosparam get /control_terminal/robots_num)
		                                   
# spawn robots
for ((i=0; i<1; i++))
do
    j=$i            
  
    rosrun dta_terminal_udp dta_local_udp_server Robot${j}  __name:=Robot${j}_local_server &
               
#    rosrun gazebo_ros spawn_model -file $(rospack find gazebo_description)/models/Robot/model.sdf -sdf \
#                                  -model Robot${j} \
#                                  -x 0.0 -y 0.0 -z 0.0 &
done 
