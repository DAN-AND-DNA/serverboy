# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/local/cmake-3.10.0-Linux-x86_64/bin/cmake

# The command to remove a file.
RM = /usr/local/cmake-3.10.0-Linux-x86_64/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dan/ServerBoy

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dan/ServerBoy/build

# Include any dependencies generated for this target.
include CMakeFiles/serverboy.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/serverboy.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/serverboy.dir/flags.make

CMakeFiles/serverboy.dir/main.cpp.o: CMakeFiles/serverboy.dir/flags.make
CMakeFiles/serverboy.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dan/ServerBoy/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/serverboy.dir/main.cpp.o"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/serverboy.dir/main.cpp.o -c /home/dan/ServerBoy/main.cpp

CMakeFiles/serverboy.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/serverboy.dir/main.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dan/ServerBoy/main.cpp > CMakeFiles/serverboy.dir/main.cpp.i

CMakeFiles/serverboy.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/serverboy.dir/main.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dan/ServerBoy/main.cpp -o CMakeFiles/serverboy.dir/main.cpp.s

CMakeFiles/serverboy.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/serverboy.dir/main.cpp.o.requires

CMakeFiles/serverboy.dir/main.cpp.o.provides: CMakeFiles/serverboy.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/serverboy.dir/build.make CMakeFiles/serverboy.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/serverboy.dir/main.cpp.o.provides

CMakeFiles/serverboy.dir/main.cpp.o.provides.build: CMakeFiles/serverboy.dir/main.cpp.o


CMakeFiles/serverboy.dir/ServerBoy.cpp.o: CMakeFiles/serverboy.dir/flags.make
CMakeFiles/serverboy.dir/ServerBoy.cpp.o: ../ServerBoy.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dan/ServerBoy/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/serverboy.dir/ServerBoy.cpp.o"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/serverboy.dir/ServerBoy.cpp.o -c /home/dan/ServerBoy/ServerBoy.cpp

CMakeFiles/serverboy.dir/ServerBoy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/serverboy.dir/ServerBoy.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dan/ServerBoy/ServerBoy.cpp > CMakeFiles/serverboy.dir/ServerBoy.cpp.i

CMakeFiles/serverboy.dir/ServerBoy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/serverboy.dir/ServerBoy.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dan/ServerBoy/ServerBoy.cpp -o CMakeFiles/serverboy.dir/ServerBoy.cpp.s

CMakeFiles/serverboy.dir/ServerBoy.cpp.o.requires:

.PHONY : CMakeFiles/serverboy.dir/ServerBoy.cpp.o.requires

CMakeFiles/serverboy.dir/ServerBoy.cpp.o.provides: CMakeFiles/serverboy.dir/ServerBoy.cpp.o.requires
	$(MAKE) -f CMakeFiles/serverboy.dir/build.make CMakeFiles/serverboy.dir/ServerBoy.cpp.o.provides.build
.PHONY : CMakeFiles/serverboy.dir/ServerBoy.cpp.o.provides

CMakeFiles/serverboy.dir/ServerBoy.cpp.o.provides.build: CMakeFiles/serverboy.dir/ServerBoy.cpp.o


CMakeFiles/serverboy.dir/lib/uWS/Epoll.cpp.o: CMakeFiles/serverboy.dir/flags.make
CMakeFiles/serverboy.dir/lib/uWS/Epoll.cpp.o: ../lib/uWS/Epoll.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dan/ServerBoy/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/serverboy.dir/lib/uWS/Epoll.cpp.o"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/serverboy.dir/lib/uWS/Epoll.cpp.o -c /home/dan/ServerBoy/lib/uWS/Epoll.cpp

CMakeFiles/serverboy.dir/lib/uWS/Epoll.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/serverboy.dir/lib/uWS/Epoll.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dan/ServerBoy/lib/uWS/Epoll.cpp > CMakeFiles/serverboy.dir/lib/uWS/Epoll.cpp.i

CMakeFiles/serverboy.dir/lib/uWS/Epoll.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/serverboy.dir/lib/uWS/Epoll.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dan/ServerBoy/lib/uWS/Epoll.cpp -o CMakeFiles/serverboy.dir/lib/uWS/Epoll.cpp.s

CMakeFiles/serverboy.dir/lib/uWS/Epoll.cpp.o.requires:

.PHONY : CMakeFiles/serverboy.dir/lib/uWS/Epoll.cpp.o.requires

CMakeFiles/serverboy.dir/lib/uWS/Epoll.cpp.o.provides: CMakeFiles/serverboy.dir/lib/uWS/Epoll.cpp.o.requires
	$(MAKE) -f CMakeFiles/serverboy.dir/build.make CMakeFiles/serverboy.dir/lib/uWS/Epoll.cpp.o.provides.build
.PHONY : CMakeFiles/serverboy.dir/lib/uWS/Epoll.cpp.o.provides

CMakeFiles/serverboy.dir/lib/uWS/Epoll.cpp.o.provides.build: CMakeFiles/serverboy.dir/lib/uWS/Epoll.cpp.o


CMakeFiles/serverboy.dir/lib/uWS/Extensions.cpp.o: CMakeFiles/serverboy.dir/flags.make
CMakeFiles/serverboy.dir/lib/uWS/Extensions.cpp.o: ../lib/uWS/Extensions.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dan/ServerBoy/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/serverboy.dir/lib/uWS/Extensions.cpp.o"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/serverboy.dir/lib/uWS/Extensions.cpp.o -c /home/dan/ServerBoy/lib/uWS/Extensions.cpp

CMakeFiles/serverboy.dir/lib/uWS/Extensions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/serverboy.dir/lib/uWS/Extensions.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dan/ServerBoy/lib/uWS/Extensions.cpp > CMakeFiles/serverboy.dir/lib/uWS/Extensions.cpp.i

CMakeFiles/serverboy.dir/lib/uWS/Extensions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/serverboy.dir/lib/uWS/Extensions.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dan/ServerBoy/lib/uWS/Extensions.cpp -o CMakeFiles/serverboy.dir/lib/uWS/Extensions.cpp.s

CMakeFiles/serverboy.dir/lib/uWS/Extensions.cpp.o.requires:

.PHONY : CMakeFiles/serverboy.dir/lib/uWS/Extensions.cpp.o.requires

CMakeFiles/serverboy.dir/lib/uWS/Extensions.cpp.o.provides: CMakeFiles/serverboy.dir/lib/uWS/Extensions.cpp.o.requires
	$(MAKE) -f CMakeFiles/serverboy.dir/build.make CMakeFiles/serverboy.dir/lib/uWS/Extensions.cpp.o.provides.build
.PHONY : CMakeFiles/serverboy.dir/lib/uWS/Extensions.cpp.o.provides

CMakeFiles/serverboy.dir/lib/uWS/Extensions.cpp.o.provides.build: CMakeFiles/serverboy.dir/lib/uWS/Extensions.cpp.o


CMakeFiles/serverboy.dir/lib/uWS/Group.cpp.o: CMakeFiles/serverboy.dir/flags.make
CMakeFiles/serverboy.dir/lib/uWS/Group.cpp.o: ../lib/uWS/Group.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dan/ServerBoy/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/serverboy.dir/lib/uWS/Group.cpp.o"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/serverboy.dir/lib/uWS/Group.cpp.o -c /home/dan/ServerBoy/lib/uWS/Group.cpp

CMakeFiles/serverboy.dir/lib/uWS/Group.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/serverboy.dir/lib/uWS/Group.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dan/ServerBoy/lib/uWS/Group.cpp > CMakeFiles/serverboy.dir/lib/uWS/Group.cpp.i

CMakeFiles/serverboy.dir/lib/uWS/Group.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/serverboy.dir/lib/uWS/Group.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dan/ServerBoy/lib/uWS/Group.cpp -o CMakeFiles/serverboy.dir/lib/uWS/Group.cpp.s

CMakeFiles/serverboy.dir/lib/uWS/Group.cpp.o.requires:

.PHONY : CMakeFiles/serverboy.dir/lib/uWS/Group.cpp.o.requires

CMakeFiles/serverboy.dir/lib/uWS/Group.cpp.o.provides: CMakeFiles/serverboy.dir/lib/uWS/Group.cpp.o.requires
	$(MAKE) -f CMakeFiles/serverboy.dir/build.make CMakeFiles/serverboy.dir/lib/uWS/Group.cpp.o.provides.build
.PHONY : CMakeFiles/serverboy.dir/lib/uWS/Group.cpp.o.provides

CMakeFiles/serverboy.dir/lib/uWS/Group.cpp.o.provides.build: CMakeFiles/serverboy.dir/lib/uWS/Group.cpp.o


CMakeFiles/serverboy.dir/lib/uWS/HTTPSocket.cpp.o: CMakeFiles/serverboy.dir/flags.make
CMakeFiles/serverboy.dir/lib/uWS/HTTPSocket.cpp.o: ../lib/uWS/HTTPSocket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dan/ServerBoy/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/serverboy.dir/lib/uWS/HTTPSocket.cpp.o"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/serverboy.dir/lib/uWS/HTTPSocket.cpp.o -c /home/dan/ServerBoy/lib/uWS/HTTPSocket.cpp

CMakeFiles/serverboy.dir/lib/uWS/HTTPSocket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/serverboy.dir/lib/uWS/HTTPSocket.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dan/ServerBoy/lib/uWS/HTTPSocket.cpp > CMakeFiles/serverboy.dir/lib/uWS/HTTPSocket.cpp.i

CMakeFiles/serverboy.dir/lib/uWS/HTTPSocket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/serverboy.dir/lib/uWS/HTTPSocket.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dan/ServerBoy/lib/uWS/HTTPSocket.cpp -o CMakeFiles/serverboy.dir/lib/uWS/HTTPSocket.cpp.s

CMakeFiles/serverboy.dir/lib/uWS/HTTPSocket.cpp.o.requires:

.PHONY : CMakeFiles/serverboy.dir/lib/uWS/HTTPSocket.cpp.o.requires

CMakeFiles/serverboy.dir/lib/uWS/HTTPSocket.cpp.o.provides: CMakeFiles/serverboy.dir/lib/uWS/HTTPSocket.cpp.o.requires
	$(MAKE) -f CMakeFiles/serverboy.dir/build.make CMakeFiles/serverboy.dir/lib/uWS/HTTPSocket.cpp.o.provides.build
.PHONY : CMakeFiles/serverboy.dir/lib/uWS/HTTPSocket.cpp.o.provides

CMakeFiles/serverboy.dir/lib/uWS/HTTPSocket.cpp.o.provides.build: CMakeFiles/serverboy.dir/lib/uWS/HTTPSocket.cpp.o


CMakeFiles/serverboy.dir/lib/uWS/Hub.cpp.o: CMakeFiles/serverboy.dir/flags.make
CMakeFiles/serverboy.dir/lib/uWS/Hub.cpp.o: ../lib/uWS/Hub.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dan/ServerBoy/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/serverboy.dir/lib/uWS/Hub.cpp.o"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/serverboy.dir/lib/uWS/Hub.cpp.o -c /home/dan/ServerBoy/lib/uWS/Hub.cpp

CMakeFiles/serverboy.dir/lib/uWS/Hub.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/serverboy.dir/lib/uWS/Hub.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dan/ServerBoy/lib/uWS/Hub.cpp > CMakeFiles/serverboy.dir/lib/uWS/Hub.cpp.i

CMakeFiles/serverboy.dir/lib/uWS/Hub.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/serverboy.dir/lib/uWS/Hub.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dan/ServerBoy/lib/uWS/Hub.cpp -o CMakeFiles/serverboy.dir/lib/uWS/Hub.cpp.s

CMakeFiles/serverboy.dir/lib/uWS/Hub.cpp.o.requires:

.PHONY : CMakeFiles/serverboy.dir/lib/uWS/Hub.cpp.o.requires

CMakeFiles/serverboy.dir/lib/uWS/Hub.cpp.o.provides: CMakeFiles/serverboy.dir/lib/uWS/Hub.cpp.o.requires
	$(MAKE) -f CMakeFiles/serverboy.dir/build.make CMakeFiles/serverboy.dir/lib/uWS/Hub.cpp.o.provides.build
.PHONY : CMakeFiles/serverboy.dir/lib/uWS/Hub.cpp.o.provides

CMakeFiles/serverboy.dir/lib/uWS/Hub.cpp.o.provides.build: CMakeFiles/serverboy.dir/lib/uWS/Hub.cpp.o


CMakeFiles/serverboy.dir/lib/uWS/Networking.cpp.o: CMakeFiles/serverboy.dir/flags.make
CMakeFiles/serverboy.dir/lib/uWS/Networking.cpp.o: ../lib/uWS/Networking.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dan/ServerBoy/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/serverboy.dir/lib/uWS/Networking.cpp.o"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/serverboy.dir/lib/uWS/Networking.cpp.o -c /home/dan/ServerBoy/lib/uWS/Networking.cpp

CMakeFiles/serverboy.dir/lib/uWS/Networking.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/serverboy.dir/lib/uWS/Networking.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dan/ServerBoy/lib/uWS/Networking.cpp > CMakeFiles/serverboy.dir/lib/uWS/Networking.cpp.i

CMakeFiles/serverboy.dir/lib/uWS/Networking.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/serverboy.dir/lib/uWS/Networking.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dan/ServerBoy/lib/uWS/Networking.cpp -o CMakeFiles/serverboy.dir/lib/uWS/Networking.cpp.s

CMakeFiles/serverboy.dir/lib/uWS/Networking.cpp.o.requires:

.PHONY : CMakeFiles/serverboy.dir/lib/uWS/Networking.cpp.o.requires

CMakeFiles/serverboy.dir/lib/uWS/Networking.cpp.o.provides: CMakeFiles/serverboy.dir/lib/uWS/Networking.cpp.o.requires
	$(MAKE) -f CMakeFiles/serverboy.dir/build.make CMakeFiles/serverboy.dir/lib/uWS/Networking.cpp.o.provides.build
.PHONY : CMakeFiles/serverboy.dir/lib/uWS/Networking.cpp.o.provides

CMakeFiles/serverboy.dir/lib/uWS/Networking.cpp.o.provides.build: CMakeFiles/serverboy.dir/lib/uWS/Networking.cpp.o


CMakeFiles/serverboy.dir/lib/uWS/Node.cpp.o: CMakeFiles/serverboy.dir/flags.make
CMakeFiles/serverboy.dir/lib/uWS/Node.cpp.o: ../lib/uWS/Node.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dan/ServerBoy/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/serverboy.dir/lib/uWS/Node.cpp.o"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/serverboy.dir/lib/uWS/Node.cpp.o -c /home/dan/ServerBoy/lib/uWS/Node.cpp

CMakeFiles/serverboy.dir/lib/uWS/Node.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/serverboy.dir/lib/uWS/Node.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dan/ServerBoy/lib/uWS/Node.cpp > CMakeFiles/serverboy.dir/lib/uWS/Node.cpp.i

CMakeFiles/serverboy.dir/lib/uWS/Node.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/serverboy.dir/lib/uWS/Node.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dan/ServerBoy/lib/uWS/Node.cpp -o CMakeFiles/serverboy.dir/lib/uWS/Node.cpp.s

CMakeFiles/serverboy.dir/lib/uWS/Node.cpp.o.requires:

.PHONY : CMakeFiles/serverboy.dir/lib/uWS/Node.cpp.o.requires

CMakeFiles/serverboy.dir/lib/uWS/Node.cpp.o.provides: CMakeFiles/serverboy.dir/lib/uWS/Node.cpp.o.requires
	$(MAKE) -f CMakeFiles/serverboy.dir/build.make CMakeFiles/serverboy.dir/lib/uWS/Node.cpp.o.provides.build
.PHONY : CMakeFiles/serverboy.dir/lib/uWS/Node.cpp.o.provides

CMakeFiles/serverboy.dir/lib/uWS/Node.cpp.o.provides.build: CMakeFiles/serverboy.dir/lib/uWS/Node.cpp.o


CMakeFiles/serverboy.dir/lib/uWS/Socket.cpp.o: CMakeFiles/serverboy.dir/flags.make
CMakeFiles/serverboy.dir/lib/uWS/Socket.cpp.o: ../lib/uWS/Socket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dan/ServerBoy/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/serverboy.dir/lib/uWS/Socket.cpp.o"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/serverboy.dir/lib/uWS/Socket.cpp.o -c /home/dan/ServerBoy/lib/uWS/Socket.cpp

CMakeFiles/serverboy.dir/lib/uWS/Socket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/serverboy.dir/lib/uWS/Socket.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dan/ServerBoy/lib/uWS/Socket.cpp > CMakeFiles/serverboy.dir/lib/uWS/Socket.cpp.i

CMakeFiles/serverboy.dir/lib/uWS/Socket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/serverboy.dir/lib/uWS/Socket.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dan/ServerBoy/lib/uWS/Socket.cpp -o CMakeFiles/serverboy.dir/lib/uWS/Socket.cpp.s

CMakeFiles/serverboy.dir/lib/uWS/Socket.cpp.o.requires:

.PHONY : CMakeFiles/serverboy.dir/lib/uWS/Socket.cpp.o.requires

CMakeFiles/serverboy.dir/lib/uWS/Socket.cpp.o.provides: CMakeFiles/serverboy.dir/lib/uWS/Socket.cpp.o.requires
	$(MAKE) -f CMakeFiles/serverboy.dir/build.make CMakeFiles/serverboy.dir/lib/uWS/Socket.cpp.o.provides.build
.PHONY : CMakeFiles/serverboy.dir/lib/uWS/Socket.cpp.o.provides

CMakeFiles/serverboy.dir/lib/uWS/Socket.cpp.o.provides.build: CMakeFiles/serverboy.dir/lib/uWS/Socket.cpp.o


CMakeFiles/serverboy.dir/lib/uWS/WebSocket.cpp.o: CMakeFiles/serverboy.dir/flags.make
CMakeFiles/serverboy.dir/lib/uWS/WebSocket.cpp.o: ../lib/uWS/WebSocket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dan/ServerBoy/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/serverboy.dir/lib/uWS/WebSocket.cpp.o"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/serverboy.dir/lib/uWS/WebSocket.cpp.o -c /home/dan/ServerBoy/lib/uWS/WebSocket.cpp

CMakeFiles/serverboy.dir/lib/uWS/WebSocket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/serverboy.dir/lib/uWS/WebSocket.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dan/ServerBoy/lib/uWS/WebSocket.cpp > CMakeFiles/serverboy.dir/lib/uWS/WebSocket.cpp.i

CMakeFiles/serverboy.dir/lib/uWS/WebSocket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/serverboy.dir/lib/uWS/WebSocket.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dan/ServerBoy/lib/uWS/WebSocket.cpp -o CMakeFiles/serverboy.dir/lib/uWS/WebSocket.cpp.s

CMakeFiles/serverboy.dir/lib/uWS/WebSocket.cpp.o.requires:

.PHONY : CMakeFiles/serverboy.dir/lib/uWS/WebSocket.cpp.o.requires

CMakeFiles/serverboy.dir/lib/uWS/WebSocket.cpp.o.provides: CMakeFiles/serverboy.dir/lib/uWS/WebSocket.cpp.o.requires
	$(MAKE) -f CMakeFiles/serverboy.dir/build.make CMakeFiles/serverboy.dir/lib/uWS/WebSocket.cpp.o.provides.build
.PHONY : CMakeFiles/serverboy.dir/lib/uWS/WebSocket.cpp.o.provides

CMakeFiles/serverboy.dir/lib/uWS/WebSocket.cpp.o.provides.build: CMakeFiles/serverboy.dir/lib/uWS/WebSocket.cpp.o


CMakeFiles/serverboy.dir/lib/log/Exception.cpp.o: CMakeFiles/serverboy.dir/flags.make
CMakeFiles/serverboy.dir/lib/log/Exception.cpp.o: ../lib/log/Exception.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dan/ServerBoy/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/serverboy.dir/lib/log/Exception.cpp.o"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/serverboy.dir/lib/log/Exception.cpp.o -c /home/dan/ServerBoy/lib/log/Exception.cpp

CMakeFiles/serverboy.dir/lib/log/Exception.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/serverboy.dir/lib/log/Exception.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dan/ServerBoy/lib/log/Exception.cpp > CMakeFiles/serverboy.dir/lib/log/Exception.cpp.i

CMakeFiles/serverboy.dir/lib/log/Exception.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/serverboy.dir/lib/log/Exception.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dan/ServerBoy/lib/log/Exception.cpp -o CMakeFiles/serverboy.dir/lib/log/Exception.cpp.s

CMakeFiles/serverboy.dir/lib/log/Exception.cpp.o.requires:

.PHONY : CMakeFiles/serverboy.dir/lib/log/Exception.cpp.o.requires

CMakeFiles/serverboy.dir/lib/log/Exception.cpp.o.provides: CMakeFiles/serverboy.dir/lib/log/Exception.cpp.o.requires
	$(MAKE) -f CMakeFiles/serverboy.dir/build.make CMakeFiles/serverboy.dir/lib/log/Exception.cpp.o.provides.build
.PHONY : CMakeFiles/serverboy.dir/lib/log/Exception.cpp.o.provides

CMakeFiles/serverboy.dir/lib/log/Exception.cpp.o.provides.build: CMakeFiles/serverboy.dir/lib/log/Exception.cpp.o


# Object files for target serverboy
serverboy_OBJECTS = \
"CMakeFiles/serverboy.dir/main.cpp.o" \
"CMakeFiles/serverboy.dir/ServerBoy.cpp.o" \
"CMakeFiles/serverboy.dir/lib/uWS/Epoll.cpp.o" \
"CMakeFiles/serverboy.dir/lib/uWS/Extensions.cpp.o" \
"CMakeFiles/serverboy.dir/lib/uWS/Group.cpp.o" \
"CMakeFiles/serverboy.dir/lib/uWS/HTTPSocket.cpp.o" \
"CMakeFiles/serverboy.dir/lib/uWS/Hub.cpp.o" \
"CMakeFiles/serverboy.dir/lib/uWS/Networking.cpp.o" \
"CMakeFiles/serverboy.dir/lib/uWS/Node.cpp.o" \
"CMakeFiles/serverboy.dir/lib/uWS/Socket.cpp.o" \
"CMakeFiles/serverboy.dir/lib/uWS/WebSocket.cpp.o" \
"CMakeFiles/serverboy.dir/lib/log/Exception.cpp.o"

# External object files for target serverboy
serverboy_EXTERNAL_OBJECTS =

bin/serverboy: CMakeFiles/serverboy.dir/main.cpp.o
bin/serverboy: CMakeFiles/serverboy.dir/ServerBoy.cpp.o
bin/serverboy: CMakeFiles/serverboy.dir/lib/uWS/Epoll.cpp.o
bin/serverboy: CMakeFiles/serverboy.dir/lib/uWS/Extensions.cpp.o
bin/serverboy: CMakeFiles/serverboy.dir/lib/uWS/Group.cpp.o
bin/serverboy: CMakeFiles/serverboy.dir/lib/uWS/HTTPSocket.cpp.o
bin/serverboy: CMakeFiles/serverboy.dir/lib/uWS/Hub.cpp.o
bin/serverboy: CMakeFiles/serverboy.dir/lib/uWS/Networking.cpp.o
bin/serverboy: CMakeFiles/serverboy.dir/lib/uWS/Node.cpp.o
bin/serverboy: CMakeFiles/serverboy.dir/lib/uWS/Socket.cpp.o
bin/serverboy: CMakeFiles/serverboy.dir/lib/uWS/WebSocket.cpp.o
bin/serverboy: CMakeFiles/serverboy.dir/lib/log/Exception.cpp.o
bin/serverboy: CMakeFiles/serverboy.dir/build.make
bin/serverboy: CMakeFiles/serverboy.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dan/ServerBoy/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX executable bin/serverboy"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/serverboy.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/serverboy.dir/build: bin/serverboy

.PHONY : CMakeFiles/serverboy.dir/build

CMakeFiles/serverboy.dir/requires: CMakeFiles/serverboy.dir/main.cpp.o.requires
CMakeFiles/serverboy.dir/requires: CMakeFiles/serverboy.dir/ServerBoy.cpp.o.requires
CMakeFiles/serverboy.dir/requires: CMakeFiles/serverboy.dir/lib/uWS/Epoll.cpp.o.requires
CMakeFiles/serverboy.dir/requires: CMakeFiles/serverboy.dir/lib/uWS/Extensions.cpp.o.requires
CMakeFiles/serverboy.dir/requires: CMakeFiles/serverboy.dir/lib/uWS/Group.cpp.o.requires
CMakeFiles/serverboy.dir/requires: CMakeFiles/serverboy.dir/lib/uWS/HTTPSocket.cpp.o.requires
CMakeFiles/serverboy.dir/requires: CMakeFiles/serverboy.dir/lib/uWS/Hub.cpp.o.requires
CMakeFiles/serverboy.dir/requires: CMakeFiles/serverboy.dir/lib/uWS/Networking.cpp.o.requires
CMakeFiles/serverboy.dir/requires: CMakeFiles/serverboy.dir/lib/uWS/Node.cpp.o.requires
CMakeFiles/serverboy.dir/requires: CMakeFiles/serverboy.dir/lib/uWS/Socket.cpp.o.requires
CMakeFiles/serverboy.dir/requires: CMakeFiles/serverboy.dir/lib/uWS/WebSocket.cpp.o.requires
CMakeFiles/serverboy.dir/requires: CMakeFiles/serverboy.dir/lib/log/Exception.cpp.o.requires

.PHONY : CMakeFiles/serverboy.dir/requires

CMakeFiles/serverboy.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/serverboy.dir/cmake_clean.cmake
.PHONY : CMakeFiles/serverboy.dir/clean

CMakeFiles/serverboy.dir/depend:
	cd /home/dan/ServerBoy/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dan/ServerBoy /home/dan/ServerBoy /home/dan/ServerBoy/build /home/dan/ServerBoy/build /home/dan/ServerBoy/build/CMakeFiles/serverboy.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/serverboy.dir/depend

