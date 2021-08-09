cmake_minimum_required(VERSION 2.8)
project(cpp_dev)
#if (${CMAKE_BUILD_TYPE} ste)
#set(CMAKE_CXX_FLAGS "-std=c++11 -O0 ${CMAKE_CXX_FLAGS}")
set(CPP_SRCS cpp_pthread_test.cpp)

add_executable(cpp_test ${CPP_SRCS})

target_link_libraries(cpp_test pthread)
