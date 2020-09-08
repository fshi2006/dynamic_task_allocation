# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "allocation_common: 16 messages, 2 services")

set(MSG_I_FLAGS "-Iallocation_common:/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs;-Istd_msgs:/opt/ros/kinetic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(allocation_common_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Pose.msg" NAME_WE)
add_custom_target(_allocation_common_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "allocation_common" "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Pose.msg" "allocation_common/Point2d"
)

get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg" NAME_WE)
add_custom_target(_allocation_common_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "allocation_common" "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg" ""
)

get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/gazebo_task_info.msg" NAME_WE)
add_custom_target(_allocation_common_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "allocation_common" "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/gazebo_task_info.msg" "allocation_common/Point2d"
)

get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/srv/ReturnReward.srv" NAME_WE)
add_custom_target(_allocation_common_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "allocation_common" "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/srv/ReturnReward.srv" "allocation_common/Observation:allocation_common/Taskinfo:allocation_common/Teammateinfo:allocation_common/Point2d"
)

get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Twist.msg" NAME_WE)
add_custom_target(_allocation_common_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "allocation_common" "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Twist.msg" "allocation_common/Point2d"
)

get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/terminal2robot_info.msg" NAME_WE)
add_custom_target(_allocation_common_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "allocation_common" "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/terminal2robot_info.msg" "allocation_common/Point2d:allocation_common/allocation_task_info:allocation_common/allocation_robot_info:allocation_common/Pose"
)

get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/gazebo2world_info.msg" NAME_WE)
add_custom_target(_allocation_common_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "allocation_common" "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/gazebo2world_info.msg" "allocation_common/gazebo_task_info:allocation_common/gazebo_robot_info:allocation_common/Twist:allocation_common/Point2d:allocation_common/Pose"
)

get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Teammateinfo.msg" NAME_WE)
add_custom_target(_allocation_common_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "allocation_common" "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Teammateinfo.msg" "allocation_common/Point2d"
)

get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/terminal2DQN_info.msg" NAME_WE)
add_custom_target(_allocation_common_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "allocation_common" "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/terminal2DQN_info.msg" ""
)

get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/terminal2gazebo_info.msg" NAME_WE)
add_custom_target(_allocation_common_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "allocation_common" "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/terminal2gazebo_info.msg" ""
)

get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Observation.msg" NAME_WE)
add_custom_target(_allocation_common_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "allocation_common" "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Observation.msg" "allocation_common/Point2d:allocation_common/Taskinfo:allocation_common/Teammateinfo"
)

get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/robot2gazebo_info.msg" NAME_WE)
add_custom_target(_allocation_common_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "allocation_common" "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/robot2gazebo_info.msg" "allocation_common/Point2d:allocation_common/Twist"
)

get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/allocation2terminal_info.msg" NAME_WE)
add_custom_target(_allocation_common_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "allocation_common" "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/allocation2terminal_info.msg" "allocation_common/Point2d:allocation_common/Pose:allocation_common/allocation_robot_info:allocation_common/allocation_task_info"
)

get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/allocation_task_info.msg" NAME_WE)
add_custom_target(_allocation_common_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "allocation_common" "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/allocation_task_info.msg" ""
)

get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/allocation_robot_info.msg" NAME_WE)
add_custom_target(_allocation_common_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "allocation_common" "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/allocation_robot_info.msg" "allocation_common/Point2d:allocation_common/Pose"
)

get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Taskinfo.msg" NAME_WE)
add_custom_target(_allocation_common_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "allocation_common" "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Taskinfo.msg" "allocation_common/Point2d"
)

get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/gazebo_robot_info.msg" NAME_WE)
add_custom_target(_allocation_common_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "allocation_common" "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/gazebo_robot_info.msg" "allocation_common/Point2d:allocation_common/Twist:allocation_common/Pose"
)

get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/srv/GetAction.srv" NAME_WE)
add_custom_target(_allocation_common_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "allocation_common" "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/srv/GetAction.srv" "allocation_common/Observation:allocation_common/Taskinfo:allocation_common/Teammateinfo:allocation_common/Point2d"
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Pose.msg"
  "${MSG_I_FLAGS}"
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/allocation_common
)
_generate_msg_cpp(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/terminal2DQN_info.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/allocation_common
)
_generate_msg_cpp(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Observation.msg"
  "${MSG_I_FLAGS}"
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Taskinfo.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Teammateinfo.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/allocation_common
)
_generate_msg_cpp(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Twist.msg"
  "${MSG_I_FLAGS}"
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/allocation_common
)
_generate_msg_cpp(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/allocation_common
)
_generate_msg_cpp(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/terminal2robot_info.msg"
  "${MSG_I_FLAGS}"
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/allocation_task_info.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/allocation_robot_info.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/allocation_common
)
_generate_msg_cpp(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/gazebo2world_info.msg"
  "${MSG_I_FLAGS}"
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/gazebo_task_info.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/gazebo_robot_info.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Twist.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/allocation_common
)
_generate_msg_cpp(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Teammateinfo.msg"
  "${MSG_I_FLAGS}"
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/allocation_common
)
_generate_msg_cpp(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/gazebo_robot_info.msg"
  "${MSG_I_FLAGS}"
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Twist.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/allocation_common
)
_generate_msg_cpp(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/terminal2gazebo_info.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/allocation_common
)
_generate_msg_cpp(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/gazebo_task_info.msg"
  "${MSG_I_FLAGS}"
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/allocation_common
)
_generate_msg_cpp(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/robot2gazebo_info.msg"
  "${MSG_I_FLAGS}"
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Twist.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/allocation_common
)
_generate_msg_cpp(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/allocation2terminal_info.msg"
  "${MSG_I_FLAGS}"
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Pose.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/allocation_robot_info.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/allocation_task_info.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/allocation_common
)
_generate_msg_cpp(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/allocation_task_info.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/allocation_common
)
_generate_msg_cpp(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Taskinfo.msg"
  "${MSG_I_FLAGS}"
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/allocation_common
)
_generate_msg_cpp(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/allocation_robot_info.msg"
  "${MSG_I_FLAGS}"
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/allocation_common
)

### Generating Services
_generate_srv_cpp(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/srv/ReturnReward.srv"
  "${MSG_I_FLAGS}"
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Observation.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Taskinfo.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Teammateinfo.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/allocation_common
)
_generate_srv_cpp(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/srv/GetAction.srv"
  "${MSG_I_FLAGS}"
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Observation.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Taskinfo.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Teammateinfo.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/allocation_common
)

### Generating Module File
_generate_module_cpp(allocation_common
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/allocation_common
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(allocation_common_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(allocation_common_generate_messages allocation_common_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Pose.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_cpp _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_cpp _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/gazebo_task_info.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_cpp _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/srv/ReturnReward.srv" NAME_WE)
add_dependencies(allocation_common_generate_messages_cpp _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Twist.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_cpp _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/terminal2robot_info.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_cpp _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/gazebo2world_info.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_cpp _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Teammateinfo.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_cpp _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/terminal2DQN_info.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_cpp _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/terminal2gazebo_info.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_cpp _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Observation.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_cpp _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/robot2gazebo_info.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_cpp _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/allocation2terminal_info.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_cpp _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/allocation_task_info.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_cpp _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/allocation_robot_info.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_cpp _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Taskinfo.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_cpp _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/gazebo_robot_info.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_cpp _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/srv/GetAction.srv" NAME_WE)
add_dependencies(allocation_common_generate_messages_cpp _allocation_common_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(allocation_common_gencpp)
add_dependencies(allocation_common_gencpp allocation_common_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS allocation_common_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Pose.msg"
  "${MSG_I_FLAGS}"
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/allocation_common
)
_generate_msg_eus(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/terminal2DQN_info.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/allocation_common
)
_generate_msg_eus(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Observation.msg"
  "${MSG_I_FLAGS}"
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Taskinfo.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Teammateinfo.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/allocation_common
)
_generate_msg_eus(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Twist.msg"
  "${MSG_I_FLAGS}"
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/allocation_common
)
_generate_msg_eus(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/allocation_common
)
_generate_msg_eus(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/terminal2robot_info.msg"
  "${MSG_I_FLAGS}"
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/allocation_task_info.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/allocation_robot_info.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/allocation_common
)
_generate_msg_eus(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/gazebo2world_info.msg"
  "${MSG_I_FLAGS}"
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/gazebo_task_info.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/gazebo_robot_info.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Twist.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/allocation_common
)
_generate_msg_eus(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Teammateinfo.msg"
  "${MSG_I_FLAGS}"
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/allocation_common
)
_generate_msg_eus(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/gazebo_robot_info.msg"
  "${MSG_I_FLAGS}"
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Twist.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/allocation_common
)
_generate_msg_eus(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/terminal2gazebo_info.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/allocation_common
)
_generate_msg_eus(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/gazebo_task_info.msg"
  "${MSG_I_FLAGS}"
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/allocation_common
)
_generate_msg_eus(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/robot2gazebo_info.msg"
  "${MSG_I_FLAGS}"
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Twist.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/allocation_common
)
_generate_msg_eus(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/allocation2terminal_info.msg"
  "${MSG_I_FLAGS}"
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Pose.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/allocation_robot_info.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/allocation_task_info.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/allocation_common
)
_generate_msg_eus(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/allocation_task_info.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/allocation_common
)
_generate_msg_eus(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Taskinfo.msg"
  "${MSG_I_FLAGS}"
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/allocation_common
)
_generate_msg_eus(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/allocation_robot_info.msg"
  "${MSG_I_FLAGS}"
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/allocation_common
)

### Generating Services
_generate_srv_eus(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/srv/ReturnReward.srv"
  "${MSG_I_FLAGS}"
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Observation.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Taskinfo.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Teammateinfo.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/allocation_common
)
_generate_srv_eus(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/srv/GetAction.srv"
  "${MSG_I_FLAGS}"
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Observation.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Taskinfo.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Teammateinfo.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/allocation_common
)

### Generating Module File
_generate_module_eus(allocation_common
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/allocation_common
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(allocation_common_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(allocation_common_generate_messages allocation_common_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Pose.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_eus _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_eus _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/gazebo_task_info.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_eus _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/srv/ReturnReward.srv" NAME_WE)
add_dependencies(allocation_common_generate_messages_eus _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Twist.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_eus _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/terminal2robot_info.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_eus _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/gazebo2world_info.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_eus _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Teammateinfo.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_eus _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/terminal2DQN_info.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_eus _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/terminal2gazebo_info.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_eus _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Observation.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_eus _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/robot2gazebo_info.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_eus _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/allocation2terminal_info.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_eus _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/allocation_task_info.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_eus _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/allocation_robot_info.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_eus _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Taskinfo.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_eus _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/gazebo_robot_info.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_eus _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/srv/GetAction.srv" NAME_WE)
add_dependencies(allocation_common_generate_messages_eus _allocation_common_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(allocation_common_geneus)
add_dependencies(allocation_common_geneus allocation_common_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS allocation_common_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Pose.msg"
  "${MSG_I_FLAGS}"
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/allocation_common
)
_generate_msg_lisp(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/terminal2DQN_info.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/allocation_common
)
_generate_msg_lisp(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Observation.msg"
  "${MSG_I_FLAGS}"
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Taskinfo.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Teammateinfo.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/allocation_common
)
_generate_msg_lisp(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Twist.msg"
  "${MSG_I_FLAGS}"
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/allocation_common
)
_generate_msg_lisp(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/allocation_common
)
_generate_msg_lisp(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/terminal2robot_info.msg"
  "${MSG_I_FLAGS}"
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/allocation_task_info.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/allocation_robot_info.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/allocation_common
)
_generate_msg_lisp(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/gazebo2world_info.msg"
  "${MSG_I_FLAGS}"
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/gazebo_task_info.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/gazebo_robot_info.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Twist.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/allocation_common
)
_generate_msg_lisp(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Teammateinfo.msg"
  "${MSG_I_FLAGS}"
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/allocation_common
)
_generate_msg_lisp(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/gazebo_robot_info.msg"
  "${MSG_I_FLAGS}"
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Twist.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/allocation_common
)
_generate_msg_lisp(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/terminal2gazebo_info.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/allocation_common
)
_generate_msg_lisp(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/gazebo_task_info.msg"
  "${MSG_I_FLAGS}"
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/allocation_common
)
_generate_msg_lisp(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/robot2gazebo_info.msg"
  "${MSG_I_FLAGS}"
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Twist.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/allocation_common
)
_generate_msg_lisp(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/allocation2terminal_info.msg"
  "${MSG_I_FLAGS}"
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Pose.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/allocation_robot_info.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/allocation_task_info.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/allocation_common
)
_generate_msg_lisp(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/allocation_task_info.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/allocation_common
)
_generate_msg_lisp(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Taskinfo.msg"
  "${MSG_I_FLAGS}"
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/allocation_common
)
_generate_msg_lisp(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/allocation_robot_info.msg"
  "${MSG_I_FLAGS}"
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/allocation_common
)

### Generating Services
_generate_srv_lisp(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/srv/ReturnReward.srv"
  "${MSG_I_FLAGS}"
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Observation.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Taskinfo.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Teammateinfo.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/allocation_common
)
_generate_srv_lisp(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/srv/GetAction.srv"
  "${MSG_I_FLAGS}"
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Observation.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Taskinfo.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Teammateinfo.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/allocation_common
)

### Generating Module File
_generate_module_lisp(allocation_common
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/allocation_common
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(allocation_common_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(allocation_common_generate_messages allocation_common_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Pose.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_lisp _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_lisp _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/gazebo_task_info.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_lisp _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/srv/ReturnReward.srv" NAME_WE)
add_dependencies(allocation_common_generate_messages_lisp _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Twist.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_lisp _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/terminal2robot_info.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_lisp _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/gazebo2world_info.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_lisp _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Teammateinfo.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_lisp _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/terminal2DQN_info.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_lisp _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/terminal2gazebo_info.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_lisp _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Observation.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_lisp _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/robot2gazebo_info.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_lisp _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/allocation2terminal_info.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_lisp _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/allocation_task_info.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_lisp _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/allocation_robot_info.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_lisp _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Taskinfo.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_lisp _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/gazebo_robot_info.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_lisp _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/srv/GetAction.srv" NAME_WE)
add_dependencies(allocation_common_generate_messages_lisp _allocation_common_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(allocation_common_genlisp)
add_dependencies(allocation_common_genlisp allocation_common_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS allocation_common_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Pose.msg"
  "${MSG_I_FLAGS}"
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/allocation_common
)
_generate_msg_nodejs(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/terminal2DQN_info.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/allocation_common
)
_generate_msg_nodejs(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Observation.msg"
  "${MSG_I_FLAGS}"
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Taskinfo.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Teammateinfo.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/allocation_common
)
_generate_msg_nodejs(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Twist.msg"
  "${MSG_I_FLAGS}"
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/allocation_common
)
_generate_msg_nodejs(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/allocation_common
)
_generate_msg_nodejs(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/terminal2robot_info.msg"
  "${MSG_I_FLAGS}"
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/allocation_task_info.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/allocation_robot_info.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/allocation_common
)
_generate_msg_nodejs(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/gazebo2world_info.msg"
  "${MSG_I_FLAGS}"
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/gazebo_task_info.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/gazebo_robot_info.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Twist.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/allocation_common
)
_generate_msg_nodejs(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Teammateinfo.msg"
  "${MSG_I_FLAGS}"
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/allocation_common
)
_generate_msg_nodejs(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/gazebo_robot_info.msg"
  "${MSG_I_FLAGS}"
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Twist.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/allocation_common
)
_generate_msg_nodejs(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/terminal2gazebo_info.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/allocation_common
)
_generate_msg_nodejs(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/gazebo_task_info.msg"
  "${MSG_I_FLAGS}"
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/allocation_common
)
_generate_msg_nodejs(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/robot2gazebo_info.msg"
  "${MSG_I_FLAGS}"
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Twist.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/allocation_common
)
_generate_msg_nodejs(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/allocation2terminal_info.msg"
  "${MSG_I_FLAGS}"
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Pose.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/allocation_robot_info.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/allocation_task_info.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/allocation_common
)
_generate_msg_nodejs(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/allocation_task_info.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/allocation_common
)
_generate_msg_nodejs(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Taskinfo.msg"
  "${MSG_I_FLAGS}"
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/allocation_common
)
_generate_msg_nodejs(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/allocation_robot_info.msg"
  "${MSG_I_FLAGS}"
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/allocation_common
)

### Generating Services
_generate_srv_nodejs(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/srv/ReturnReward.srv"
  "${MSG_I_FLAGS}"
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Observation.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Taskinfo.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Teammateinfo.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/allocation_common
)
_generate_srv_nodejs(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/srv/GetAction.srv"
  "${MSG_I_FLAGS}"
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Observation.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Taskinfo.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Teammateinfo.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/allocation_common
)

### Generating Module File
_generate_module_nodejs(allocation_common
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/allocation_common
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(allocation_common_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(allocation_common_generate_messages allocation_common_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Pose.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_nodejs _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_nodejs _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/gazebo_task_info.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_nodejs _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/srv/ReturnReward.srv" NAME_WE)
add_dependencies(allocation_common_generate_messages_nodejs _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Twist.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_nodejs _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/terminal2robot_info.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_nodejs _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/gazebo2world_info.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_nodejs _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Teammateinfo.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_nodejs _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/terminal2DQN_info.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_nodejs _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/terminal2gazebo_info.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_nodejs _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Observation.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_nodejs _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/robot2gazebo_info.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_nodejs _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/allocation2terminal_info.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_nodejs _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/allocation_task_info.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_nodejs _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/allocation_robot_info.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_nodejs _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Taskinfo.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_nodejs _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/gazebo_robot_info.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_nodejs _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/srv/GetAction.srv" NAME_WE)
add_dependencies(allocation_common_generate_messages_nodejs _allocation_common_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(allocation_common_gennodejs)
add_dependencies(allocation_common_gennodejs allocation_common_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS allocation_common_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Pose.msg"
  "${MSG_I_FLAGS}"
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/allocation_common
)
_generate_msg_py(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/terminal2DQN_info.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/allocation_common
)
_generate_msg_py(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Observation.msg"
  "${MSG_I_FLAGS}"
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Taskinfo.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Teammateinfo.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/allocation_common
)
_generate_msg_py(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Twist.msg"
  "${MSG_I_FLAGS}"
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/allocation_common
)
_generate_msg_py(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/allocation_common
)
_generate_msg_py(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/terminal2robot_info.msg"
  "${MSG_I_FLAGS}"
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/allocation_task_info.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/allocation_robot_info.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/allocation_common
)
_generate_msg_py(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/gazebo2world_info.msg"
  "${MSG_I_FLAGS}"
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/gazebo_task_info.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/gazebo_robot_info.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Twist.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/allocation_common
)
_generate_msg_py(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Teammateinfo.msg"
  "${MSG_I_FLAGS}"
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/allocation_common
)
_generate_msg_py(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/gazebo_robot_info.msg"
  "${MSG_I_FLAGS}"
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Twist.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/allocation_common
)
_generate_msg_py(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/terminal2gazebo_info.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/allocation_common
)
_generate_msg_py(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/gazebo_task_info.msg"
  "${MSG_I_FLAGS}"
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/allocation_common
)
_generate_msg_py(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/robot2gazebo_info.msg"
  "${MSG_I_FLAGS}"
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Twist.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/allocation_common
)
_generate_msg_py(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/allocation2terminal_info.msg"
  "${MSG_I_FLAGS}"
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Pose.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/allocation_robot_info.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/allocation_task_info.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/allocation_common
)
_generate_msg_py(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/allocation_task_info.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/allocation_common
)
_generate_msg_py(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Taskinfo.msg"
  "${MSG_I_FLAGS}"
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/allocation_common
)
_generate_msg_py(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/allocation_robot_info.msg"
  "${MSG_I_FLAGS}"
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/allocation_common
)

### Generating Services
_generate_srv_py(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/srv/ReturnReward.srv"
  "${MSG_I_FLAGS}"
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Observation.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Taskinfo.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Teammateinfo.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/allocation_common
)
_generate_srv_py(allocation_common
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/srv/GetAction.srv"
  "${MSG_I_FLAGS}"
  "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Observation.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Taskinfo.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Teammateinfo.msg;/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/allocation_common
)

### Generating Module File
_generate_module_py(allocation_common
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/allocation_common
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(allocation_common_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(allocation_common_generate_messages allocation_common_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Pose.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_py _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Point2d.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_py _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/gazebo_task_info.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_py _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/srv/ReturnReward.srv" NAME_WE)
add_dependencies(allocation_common_generate_messages_py _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Twist.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_py _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/terminal2robot_info.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_py _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/gazebo2world_info.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_py _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Teammateinfo.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_py _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/terminal2DQN_info.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_py _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/terminal2gazebo_info.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_py _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Observation.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_py _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/robot2gazebo_info.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_py _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/allocation2terminal_info.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_py _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/allocation_task_info.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_py _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/allocation_robot_info.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_py _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/Taskinfo.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_py _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/msgs/gazebo_robot_info.msg" NAME_WE)
add_dependencies(allocation_common_generate_messages_py _allocation_common_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/allocation_common/srv/GetAction.srv" NAME_WE)
add_dependencies(allocation_common_generate_messages_py _allocation_common_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(allocation_common_genpy)
add_dependencies(allocation_common_genpy allocation_common_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS allocation_common_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/allocation_common)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/allocation_common
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(allocation_common_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/allocation_common)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/allocation_common
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(allocation_common_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/allocation_common)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/allocation_common
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(allocation_common_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/allocation_common)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/allocation_common
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(allocation_common_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/allocation_common)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/allocation_common\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/allocation_common
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(allocation_common_generate_messages_py std_msgs_generate_messages_py)
endif()
