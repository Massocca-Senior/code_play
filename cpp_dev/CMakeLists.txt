cmake_minimum_required(VERSION 2.8)
project(cpp_dev)

aux_source_directory(. SRCS)
add_executable(main ${SRCS})