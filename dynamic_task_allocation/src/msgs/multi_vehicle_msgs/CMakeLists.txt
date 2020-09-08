cmake_minimum_required(VERSION 2.8.3)
project(multi_vehicle_msgs)

set(PACKAGE_DEPENDENCIES
  geometry_msgs
  std_msgs
)

find_package(catkin REQUIRED COMPONENTS
    	roscpp
	message_generation
	${PACKAGE_DEPENDENCIES}
)
add_message_files(
  FILES
	Lo_Location.msg
)

generate_messages(
DEPENDENCIES
${PACKAGE_DEPENDENCIES}
)
catkin_package(
  CATKIN_DEPENDS
	message_runtime
    ${PACKAGE_DEPENDENCIES}
)






