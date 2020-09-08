# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "task_allocation: 1 messages, 0 services")

set(MSG_I_FLAGS "-Itask_allocation:/home/luyaomin/catkin_planning/1dynamic_task_allocation/src/task_allocation/msg;-Istd_msgs:/opt/ros/kinetic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(task_allocation_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/luyaomin/catkin_planning/1dynamic_task_allocation/src/task_allocation/msg/DebugInfo.msg" NAME_WE)
add_custom_target(_task_allocation_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "task_allocation" "/home/luyaomin/catkin_planning/1dynamic_task_allocation/src/task_allocation/msg/DebugInfo.msg" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(task_allocation
  "/home/luyaomin/catkin_planning/1dynamic_task_allocation/src/task_allocation/msg/DebugInfo.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/task_allocation
)

### Generating Services

### Generating Module File
_generate_module_cpp(task_allocation
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/task_allocation
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(task_allocation_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(task_allocation_generate_messages task_allocation_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/luyaomin/catkin_planning/1dynamic_task_allocation/src/task_allocation/msg/DebugInfo.msg" NAME_WE)
add_dependencies(task_allocation_generate_messages_cpp _task_allocation_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(task_allocation_gencpp)
add_dependencies(task_allocation_gencpp task_allocation_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS task_allocation_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(task_allocation
  "/home/luyaomin/catkin_planning/1dynamic_task_allocation/src/task_allocation/msg/DebugInfo.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/task_allocation
)

### Generating Services

### Generating Module File
_generate_module_eus(task_allocation
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/task_allocation
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(task_allocation_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(task_allocation_generate_messages task_allocation_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/luyaomin/catkin_planning/1dynamic_task_allocation/src/task_allocation/msg/DebugInfo.msg" NAME_WE)
add_dependencies(task_allocation_generate_messages_eus _task_allocation_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(task_allocation_geneus)
add_dependencies(task_allocation_geneus task_allocation_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS task_allocation_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(task_allocation
  "/home/luyaomin/catkin_planning/1dynamic_task_allocation/src/task_allocation/msg/DebugInfo.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/task_allocation
)

### Generating Services

### Generating Module File
_generate_module_lisp(task_allocation
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/task_allocation
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(task_allocation_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(task_allocation_generate_messages task_allocation_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/luyaomin/catkin_planning/1dynamic_task_allocation/src/task_allocation/msg/DebugInfo.msg" NAME_WE)
add_dependencies(task_allocation_generate_messages_lisp _task_allocation_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(task_allocation_genlisp)
add_dependencies(task_allocation_genlisp task_allocation_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS task_allocation_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(task_allocation
  "/home/luyaomin/catkin_planning/1dynamic_task_allocation/src/task_allocation/msg/DebugInfo.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/task_allocation
)

### Generating Services

### Generating Module File
_generate_module_nodejs(task_allocation
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/task_allocation
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(task_allocation_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(task_allocation_generate_messages task_allocation_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/luyaomin/catkin_planning/1dynamic_task_allocation/src/task_allocation/msg/DebugInfo.msg" NAME_WE)
add_dependencies(task_allocation_generate_messages_nodejs _task_allocation_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(task_allocation_gennodejs)
add_dependencies(task_allocation_gennodejs task_allocation_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS task_allocation_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(task_allocation
  "/home/luyaomin/catkin_planning/1dynamic_task_allocation/src/task_allocation/msg/DebugInfo.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/task_allocation
)

### Generating Services

### Generating Module File
_generate_module_py(task_allocation
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/task_allocation
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(task_allocation_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(task_allocation_generate_messages task_allocation_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/luyaomin/catkin_planning/1dynamic_task_allocation/src/task_allocation/msg/DebugInfo.msg" NAME_WE)
add_dependencies(task_allocation_generate_messages_py _task_allocation_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(task_allocation_genpy)
add_dependencies(task_allocation_genpy task_allocation_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS task_allocation_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/task_allocation)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/task_allocation
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(task_allocation_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/task_allocation)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/task_allocation
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(task_allocation_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/task_allocation)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/task_allocation
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(task_allocation_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/task_allocation)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/task_allocation
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(task_allocation_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/task_allocation)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/task_allocation\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/task_allocation
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(task_allocation_generate_messages_py std_msgs_generate_messages_py)
endif()
