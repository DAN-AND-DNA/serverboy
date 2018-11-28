cmake_minimum_required(VERSION 3.2)

project(serverboy)
set (CMAKE_BUILD_TYPE "release")
set(PIPE_PATH "/home/$ENV{USER}/serverboy/lib/pipe/testpipe/")
set(CXX_FLAGS
 -std=c++0x                     # c+11
 -g                             # 为了gdb
 -Wall                          # 显示全部的警告
 -Wextra                        # 打印一些额外的警告
 -Werror                        # 警告当作错误
 -Wconversion                   # 当隐式类型转换可能改变值时给出警告
 -Wno-unused-parameter          # 未使用参数会被警告
 -Wold-style-cast               # 程序使用 C风格的类型转换时给出警告
 -Woverloaded-virtual           # 重载虚函数名时给出警告
 -Wpointer-arith                # 当在算术表达式中使用函数指针时给出警告
 # -Wshadow                       #TODO 当一个局部变量掩盖了另一个局部变量时给出警告
 -Wwrite-strings                # 在 C++中，非零值表示将字面字符串转换为‘char*’时给出警告。在 C中，给出相似的警告，但这种类型转换是符合ISO C 标准的
 -march=native                  # gcc会自动检测你的CPU支持的指令集
 -rdynamic                      # 给backtrace_symbols使用 指示连接器把所有符号（而不仅仅只是程序已使用到的外部符号）都添加到动态符号表（即.dynsym表）里，
                                #     以便那些通过 dlopen() 或 backtrace() （这一系列函数使用.dynsym表内符号）这样的函数使用
)

string (REPLACE ";" " " CMAKE_CXX_FLAGS "${CXX_FLAGS}")
set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_FLAGS_DEBUG "-o0")                                        # 不做优化
set(CMAKE_CXX_FLAGS_RELEASE "-o2 -finline-limit=1000 -DNDEBUG")         # 做优化 最大内联函数的长度被设置 关闭断言
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)                   # 可执行的位置
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)                      # 库输出的位置

include_directories(${PIPE_PATH})
#include_directories(${PIPE_PATH}/../../pipe)
include_directories(${PIPE_PATH}/../../)


#file(GLOB PIPE "${PIPE_PATH}../../pipe/*.cpp")

add_executable(testpipe main.cpp) #${PIPE})
#add_executable(serverboy main.cpp ServerBoy.cpp ${UWS} ${BOY_PATH}/lib/log/Exception.cpp)
#add_executable(demo demo.cpp)
#add_executable(learnboost learnboost.cpp)

#target_link_libraries(serverboy pthread dl m ssl crypto z)
#target_link_libraries(demo pthread)
#target_link_libraries(learnboost pthread boost_system)
