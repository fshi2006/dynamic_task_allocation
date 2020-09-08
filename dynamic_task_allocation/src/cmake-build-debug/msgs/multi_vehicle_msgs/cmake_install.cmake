# Install script for directory: /home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/msgs/multi_vehicle_msgs

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
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/multi_vehicle_msgs/msg" TYPE FILE FILES "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/msgs/multi_vehicle_msgs/msg/Lo_Location.msg")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/multi_vehicle_msgs/cmake" TYPE FILE FILES "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/cmake-build-debug/msgs/multi_vehicle_msgs/catkin_generated/installspace/multi_vehicle_msgs-msg-paths.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/cmake-build-debug/devel/include/multi_vehicle_msgs")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/cmake-build-debug/devel/share/roseus/ros/multi_vehicle_msgs")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/cmake-build-debug/devel/share/common-lisp/ros/multi_vehicle_msgs")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/cmake-build-debug/devel/share/gennodejs/ros/multi_vehicle_msgs")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  execute_process(COMMAND "/usr/bin/python" -m compileall "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/cmake-build-debug/devel/lib/python2.7/dist-packages/multi_vehicle_msgs")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages" TYPE DIRECTORY FILES "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/cmake-build-debug/devel/lib/python2.7/dist-packages/multi_vehicle_msgs")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/cmake-build-debug/msgs/multi_vehicle_msgs/catkin_generated/installspace/multi_vehicle_msgs.pc")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/multi_vehicle_msgs/cmake" TYPE FILE FILES "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/cmake-build-debug/msgs/multi_vehicle_msgs/catkin_generated/installspace/multi_vehicle_msgs-msg-extras.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/multi_vehicle_msgs/cmake" TYPE FILE FILES
    "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/cmake-build-debug/msgs/multi_vehicle_msgs/catkin_generated/installspace/multi_vehicle_msgsConfig.cmake"
    "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/cmake-build-debug/msgs/multi_vehicle_msgs/catkin_generated/installspace/multi_vehicle_msgsConfig-version.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/multi_vehicle_msgs" TYPE FILE FILES "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/msgs/multi_vehicle_msgs/package.xml")
endif()

