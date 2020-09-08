# Install script for directory: /home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/allocation_common/msgs" TYPE FILE FILES
    "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/gazebo_robot_info.msg"
    "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/gazebo_task_info.msg"
    "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/allocation_robot_info.msg"
    "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/allocation_task_info.msg"
    "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/terminal2gazebo_info.msg"
    "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/terminal2robot_info.msg"
    "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/terminal2DQN_info.msg"
    "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/gazebo2world_info.msg"
    "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/robot2gazebo_info.msg"
    "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/allocation2terminal_info.msg"
    "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg"
    "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Pose.msg"
    "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Twist.msg"
    "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Observation.msg"
    "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Teammateinfo.msg"
    "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Taskinfo.msg"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/allocation_common/srv" TYPE FILE FILES
    "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/srv/GetAction.srv"
    "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/srv/ReturnReward.srv"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/allocation_common/cmake" TYPE FILE FILES "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/cmake-build-debug/allocation_common/catkin_generated/installspace/allocation_common-msg-paths.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/cmake-build-debug/devel/include/allocation_common")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/cmake-build-debug/devel/share/roseus/ros/allocation_common")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/cmake-build-debug/devel/share/common-lisp/ros/allocation_common")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/cmake-build-debug/devel/share/gennodejs/ros/allocation_common")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  execute_process(COMMAND "/usr/bin/python" -m compileall "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/cmake-build-debug/devel/lib/python2.7/dist-packages/allocation_common")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages" TYPE DIRECTORY FILES "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/cmake-build-debug/devel/lib/python2.7/dist-packages/allocation_common")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/cmake-build-debug/allocation_common/catkin_generated/installspace/allocation_common.pc")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/allocation_common/cmake" TYPE FILE FILES "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/cmake-build-debug/allocation_common/catkin_generated/installspace/allocation_common-msg-extras.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/allocation_common/cmake" TYPE FILE FILES
    "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/cmake-build-debug/allocation_common/catkin_generated/installspace/allocation_commonConfig.cmake"
    "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/cmake-build-debug/allocation_common/catkin_generated/installspace/allocation_commonConfig-version.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/allocation_common" TYPE FILE FILES "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/package.xml")
endif()

