# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/luyaomin/catkin_planning/2dta_local_real/src/dta/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/cmake-build-debug

# Include any dependencies generated for this target.
include task_allocation/CMakeFiles/task_allocation.dir/depend.make

# Include the progress variables for this target.
include task_allocation/CMakeFiles/task_allocation.dir/progress.make

# Include the compile flags for this target's objects.
include task_allocation/CMakeFiles/task_allocation.dir/flags.make

task_allocation/CMakeFiles/task_allocation.dir/main.cpp.o: task_allocation/CMakeFiles/task_allocation.dir/flags.make
task_allocation/CMakeFiles/task_allocation.dir/main.cpp.o: ../task_allocation/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object task_allocation/CMakeFiles/task_allocation.dir/main.cpp.o"
	cd /home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/cmake-build-debug/task_allocation && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/task_allocation.dir/main.cpp.o -c /home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/task_allocation/main.cpp

task_allocation/CMakeFiles/task_allocation.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task_allocation.dir/main.cpp.i"
	cd /home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/cmake-build-debug/task_allocation && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/task_allocation/main.cpp > CMakeFiles/task_allocation.dir/main.cpp.i

task_allocation/CMakeFiles/task_allocation.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task_allocation.dir/main.cpp.s"
	cd /home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/cmake-build-debug/task_allocation && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/task_allocation/main.cpp -o CMakeFiles/task_allocation.dir/main.cpp.s

task_allocation/CMakeFiles/task_allocation.dir/main.cpp.o.requires:

.PHONY : task_allocation/CMakeFiles/task_allocation.dir/main.cpp.o.requires

task_allocation/CMakeFiles/task_allocation.dir/main.cpp.o.provides: task_allocation/CMakeFiles/task_allocation.dir/main.cpp.o.requires
	$(MAKE) -f task_allocation/CMakeFiles/task_allocation.dir/build.make task_allocation/CMakeFiles/task_allocation.dir/main.cpp.o.provides.build
.PHONY : task_allocation/CMakeFiles/task_allocation.dir/main.cpp.o.provides

task_allocation/CMakeFiles/task_allocation.dir/main.cpp.o.provides.build: task_allocation/CMakeFiles/task_allocation.dir/main.cpp.o


# Object files for target task_allocation
task_allocation_OBJECTS = \
"CMakeFiles/task_allocation.dir/main.cpp.o"

# External object files for target task_allocation
task_allocation_EXTERNAL_OBJECTS =

task_allocation/task_allocation: task_allocation/CMakeFiles/task_allocation.dir/main.cpp.o
task_allocation/task_allocation: task_allocation/CMakeFiles/task_allocation.dir/build.make
task_allocation/task_allocation: task_allocation/CMakeFiles/task_allocation.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable task_allocation"
	cd /home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/cmake-build-debug/task_allocation && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/task_allocation.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
task_allocation/CMakeFiles/task_allocation.dir/build: task_allocation/task_allocation

.PHONY : task_allocation/CMakeFiles/task_allocation.dir/build

task_allocation/CMakeFiles/task_allocation.dir/requires: task_allocation/CMakeFiles/task_allocation.dir/main.cpp.o.requires

.PHONY : task_allocation/CMakeFiles/task_allocation.dir/requires

task_allocation/CMakeFiles/task_allocation.dir/clean:
	cd /home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/cmake-build-debug/task_allocation && $(CMAKE_COMMAND) -P CMakeFiles/task_allocation.dir/cmake_clean.cmake
.PHONY : task_allocation/CMakeFiles/task_allocation.dir/clean

task_allocation/CMakeFiles/task_allocation.dir/depend:
	cd /home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/luyaomin/catkin_planning/2dta_local_real/src/dta/src /home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/task_allocation /home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/cmake-build-debug /home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/cmake-build-debug/task_allocation /home/luyaomin/catkin_planning/2dta_local_real/src/dta/src/cmake-build-debug/task_allocation/CMakeFiles/task_allocation.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : task_allocation/CMakeFiles/task_allocation.dir/depend

