# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/moons/chat_server/test/test_muduo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/moons/chat_server/test/test_muduo/build

# Include any dependencies generated for this target.
include CMakeFiles/server_cmake.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/server_cmake.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/server_cmake.dir/flags.make

CMakeFiles/server_cmake.dir/muduo_server.cpp.o: CMakeFiles/server_cmake.dir/flags.make
CMakeFiles/server_cmake.dir/muduo_server.cpp.o: ../muduo_server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/moons/chat_server/test/test_muduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/server_cmake.dir/muduo_server.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server_cmake.dir/muduo_server.cpp.o -c /home/moons/chat_server/test/test_muduo/muduo_server.cpp

CMakeFiles/server_cmake.dir/muduo_server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server_cmake.dir/muduo_server.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/moons/chat_server/test/test_muduo/muduo_server.cpp > CMakeFiles/server_cmake.dir/muduo_server.cpp.i

CMakeFiles/server_cmake.dir/muduo_server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server_cmake.dir/muduo_server.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/moons/chat_server/test/test_muduo/muduo_server.cpp -o CMakeFiles/server_cmake.dir/muduo_server.cpp.s

# Object files for target server_cmake
server_cmake_OBJECTS = \
"CMakeFiles/server_cmake.dir/muduo_server.cpp.o"

# External object files for target server_cmake
server_cmake_EXTERNAL_OBJECTS =

../bin/server_cmake: CMakeFiles/server_cmake.dir/muduo_server.cpp.o
../bin/server_cmake: CMakeFiles/server_cmake.dir/build.make
../bin/server_cmake: CMakeFiles/server_cmake.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/moons/chat_server/test/test_muduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/server_cmake"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/server_cmake.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/server_cmake.dir/build: ../bin/server_cmake

.PHONY : CMakeFiles/server_cmake.dir/build

CMakeFiles/server_cmake.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/server_cmake.dir/cmake_clean.cmake
.PHONY : CMakeFiles/server_cmake.dir/clean

CMakeFiles/server_cmake.dir/depend:
	cd /home/moons/chat_server/test/test_muduo/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/moons/chat_server/test/test_muduo /home/moons/chat_server/test/test_muduo /home/moons/chat_server/test/test_muduo/build /home/moons/chat_server/test/test_muduo/build /home/moons/chat_server/test/test_muduo/build/CMakeFiles/server_cmake.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/server_cmake.dir/depend

