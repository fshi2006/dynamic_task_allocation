cmake_minimum_required(VERSION 2.8.3)
project(dta_terminal_udp)


find_package(catkin REQUIRED)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -std=c++11 ${CMAKE_CXX_FLAGS}")

## find ros packages and combine them with catkin
set(catkin_deps
        roscpp
        nav_msgs
        
        )
find_package(catkin REQUIRED COMPONENTS
        ${catkin_deps}
	allocation_common
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
add_executable(dta_terminal_udp_server
        src/dta_terminal_server.cpp
        )
target_link_libraries(dta_terminal_udp_server
        ${catkin_LIBRARIES}
        ${IPOPT_LIBRARIES}
        ${LINKER_LIBS}
        )

add_executable(dta_local_udp_client
        src/dta_local_client.cpp
        )
target_link_libraries(dta_local_udp_client
        ${catkin_LIBRARIES}
        ${IPOPT_LIBRARIES}
        ${LINKER_LIBS}
        )

add_executable(dta_local_udp_server
        src/dta_local_server.cpp
        )
target_link_libraries(dta_local_udp_server
        ${catkin_LIBRARIES}
        ${IPOPT_LIBRARIES}
        ${LINKER_LIBS}
        )

add_executable(dta_terminal_udp_client
        src/dta_terminal_client.cpp
        )
target_link_libraries(dta_terminal_udp_client
        ${catkin_LIBRARIES}
        ${IPOPT_LIBRARIES}
        ${LINKER_LIBS}
        )

add_executable(all_dta_local_udp_server
        src/dta_local_server_all.cpp
        )
target_link_libraries(all_dta_local_udp_server
        ${catkin_LIBRARIES}
        ${IPOPT_LIBRARIES}
        ${LINKER_LIBS}
        )
