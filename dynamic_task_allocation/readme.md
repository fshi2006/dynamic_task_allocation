# multirobots
此repo主要记录团队成员工作进度汇报和多机器人协同相关学习资料等
# 多机器人项目时间节点

**2019年11月30日**,交付多机器人路径规划软件代码(**协同搜索,搜救部分**),软件设计说明书,代码注释；

**2020年3月30日**,交付多机器人路径规划软件代码(**协同围捕**部分),软件设计说明书,代码注释；

**2020年5月30日**,交付多机器人**协同定位**软件代码,软件设计说明书,代码注释；

**2020年6月30日**,交付多机器人路径规划与协同定位技术研究报告(**理论模型**说明),随系统完成**调试**,配合完成项目验收；

## Runtime environment

1. Ubuntu 16.04
2. ROS Kinetic
3. Python 3.5
4. Gazebo version 7.0 or 7.15 (the full ROS Kinetic includes the Gazebo 7.0)

## Build

Place the package in your workspace content,the folder structure is like this:
`~/catkin_ws/src/dynamic_allocation`

 then

`$ cd ~/catkin_ws`

use single core to build to avoid confilcts.

`$ catkin_make -j1`

## Note

* You have to change the modify the path of script. In line 94, change the absolute path to your own absolute path.

`/home/wanghuohuo/catkin_ws/src/dynamic_task_allocation/src/control_terminal/src/maindialog.cpp`



* you may give the executable permission to the scripts, like

`$ chomd +x dynamic_allocation//src/allocation_common/spwan_robots.sh`

`$ chomd +x dynamic_allocation/src/allocation_gazebo/config/allocation_gazebo.cfg`

## Run


### source
`$ source devel/setup.sh`

### roscore

We need to initiate a **roscore** in any path with the following command:

`$ roscore`

### dpn_ros (optional)
**If you do not need the approach with DQN, you can skip this step.**

The Deep Q-learning network is built with **tensorflow** (Python), and we need to launch it separately:

`$ export PYTHONPATH="Your_path"+/dynamic_allocation/devel/lib/python2.7/dist-packages:$PYTHONPATH`

`$ cd dynamic_allocation/src/DQN/srcipts/`

`$ python3 train.py`


### other nodes

We can launch the other nodes by using a single launch file:

`$ roslaunch allocation_common dynamic_allocation.launch`

Now, you can see a QT Gui for control terminal and the simulation environment in Gazebo:

![](image/control_terminal&Gazebo.png)

## Framework of simulation system

There are six components included in the simulation system:

1. **allocation common:**  including the core definitions, ROS messages and ROS services that the simulation system used;
2. **allocation gazebo:** including the model plug-ins and world plug-in which implement the model control and state feedback in Gazebo;
3. **control terminal:** the QT GUI with control buttons and information browsers, it is convenient for user operation and state visualization;
4. **DQN:** Deep Q-learning network built with tensorflow;
5. **gazebo description:** describing the robot model, task model and world of allocation with sdf;
6. **task allocation:** the core program that contains the auction-based, vacancy chain and deep Q-learning approach.

The rosgraph of the simulation system with two robots:

![](image/rosgraph.png)

## How to use

The nodes in this system exchange information using topics and services. Each simulated robot is associated with a *task_allocation* node, and the communication becomes more complicated with more robots. The simulation system is a simplified environment for exploration and destruction problem, where the blue areas are the suspicious locations that need to be explored. A robotic team collaborates to complete the exploration and destruction tasks. Before the mission starts, we need to set some parameters in advance:

- **Height and width:**  the map size for this exploration;
- **Number of tasks and robots:** the number of the suspicious locations in the map and the number of robots in the team;
- **Strike ability:** the strike ability Pi of each robot;
- **Noise:** whether to add Gaussian noise to the localization of robots;
- **Starting point:** whether to start at a random position, and if not, all robots start from the lower left point of the map;
- **Approach:** which approach is used in task allocation: auction-based, vacancy chain, deep Q-learning);
- **Probability or Greed:** if using vacancy chain approach, the strategy for destruction task selection can be chosen from greedy and non-greedy;
- **Train and times:** if using deep Q-learning approach, it is divided into two modes: training and testing. And the times of trainings can be set.

With this specially designed simulation system, it is very convenient to complete the simulation experiment of dynamic task allocation for the MRS. It can also be extended for other multi-robot scenarios.

### video example

<div align=center><img src="image/video.gif"></div>
