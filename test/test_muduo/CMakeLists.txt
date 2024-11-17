cmake_minimum_required(VERSION 3.0) 
project(main)

# 配置编译选项
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -g)   #在原来基础上加一个-g  为了可调式

#配置头文件搜索路径
#include_directories()


#配置库文件搜索路径
#link_directories()


# 把.指定路径下的所有源文件名字放在变量名SRC_LIST中
# aux_source_directory(. SRC_LIST)

#设置可执行文件最终存储的路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)


#通过muduo_server.cpp生成可执行文件server
#也可以用set指定一个变量名
add_executable(server_cmake muduo_server.cpp)

#server这个目标程序需要链接什么库文件
target_link_libraries(server_cmake muduo_net muduo_base pthread)
