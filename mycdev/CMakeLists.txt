cmake_minimum_required(VERSION 2.8)
project(mydev)
#if (${CMAKE_BUILD_TYPE} ste)
set(CMAKE_C_FLAGS "-std=c11 -O0 -Werror ${CMAKE_C_FLAGS}")

set(TEST_SRC test.c data.pb-c.c protobuf-c.c)
set(OEM_TOOL_SRC oem_tools.c)

add_executable(cdemo ${TEST_SRC})
#target_link_libraries(cdemo protobuf-c)

add_executable(oem_tools ${OEM_TOOL_SRC})
