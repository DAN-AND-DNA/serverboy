cmake_minimum_required(VERSION 3.5)

project (echo)

enable_testing()

if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE "Release")
endif()

set(CXX_FLAGS
	-std=c++11
	-g
	-DCHECK_PTHREAD_RETURN_VALUE
	-D_FILE_OFFSET_BITS=64
	-Wall
	-Wextra
        #-Werror
	-Wno-conversion
	-Wno-unused-parameter
	-Woverloaded-virtual
	-Wpointer-arith
	-Wwrite-strings
	-march=native
	-rdynamic
	# add all symbol to table
	)
string(REPLACE ";" " " CMAKE_CXX_FLAGS "${CXX_FLAGS}")

set(CMAKE_CXX_FLAGS_DEBUG "-Og")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -finline-limit=1000 -DNDEBUG")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
include_directories(/home/dan/serverboy/lib/eventloop/easy_test/)
add_executable(client echo-client.cpp client.cpp)


#TARGET_LINK_LIBRARIES(client /home/dan/Server/src/qb/dan_server/src/proto/deps/protobuf/lib/libprotobuf.a)
