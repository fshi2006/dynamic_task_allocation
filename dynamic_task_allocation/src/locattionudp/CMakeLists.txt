cmake_minimum_required(VERSION 2.8.3)
project(locattionudpall)


find_package(catkin REQUIRED)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -std=c++11 ${CMAKE_CXX_FLAGS}")

## find ros packages and combine them with catkin
set(catkin_deps
        roscpp
        nav_msgs
        sensor_driver_msgs
        )
find_package(catkin REQUIRED COMPONENTS
        ${catkin_deps}
        )

## ros specific cmake command
catkin_package(
        INCLUDE_DIRS
        CATKIN_DEPENDS ${catkin_deps}
)

include_directories(
        ${catkin_INCLUDE_DIRS}
)

#####################################################################
####   add a ros node executable file
#####################################################################
add_executable(locationudpserver_all
        src/locationudpserver.cpp
        )
target_link_libraries(locationudpserver_all
        ${catkin_LIBRARIES}
        ${IPOPT_LIBRARIES}
        ${LINKER_LIBS}
        )

add_executable(locationudpclient_all
        src/locationudpclient.cpp
        )
target_link_libraries(locationudpclient_all
        ${catkin_LIBRARIES}
        ${IPOPT_LIBRARIES}
        ${LINKER_LIBS}
        )

add_executable(gps_talker
        src/aco_talker.cpp
        )
target_link_libraries(gps_talker
        ${catkin_LIBRARIES}
        ${IPOPT_LIBRARIES}
        ${LINKER_LIBS}
        )