cmake_minimum_required(VERSION 2.8.3)
project(task_allocation)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x")
set(CMAKE_BUILD_TYPE "Release")

find_package(catkin REQUIRED COMPONENTS
  cmake_modules
  message_generation
  dynamic_reconfigure
  roscpp
  rospy
  std_msgs
  std_srvs
  allocation_common
  roslib
  nav_msgs
)

add_message_files(FILES
   DebugInfo.msg
 )

generate_messages(DEPENDENCIES std_msgs)

catkin_package(
  INCLUDE_DIRS include
  CATKIN_DEPENDS message_generation
                 dynamic_reconfigure
	         roscpp 
	         rospy  
		 std_msgs 
		 std_srvs 
		 DEPENDS
)

set(task_allocation_includes
               ${catkin_INCLUDE_DIRS}
               ${PROJECT_SOURCE_DIR}/include
)

include_directories(${task_allocation_includes})



add_executable(realworld_task_allocation_node4 
  src/task_allocation_plan.cpp
  src/behaviour.cpp
  src/subtargets.cpp
)

target_link_libraries(realworld_task_allocation_node4
   ${catkin_LIBRARIES}
   ${Boost_LIBRARIES}
 )




