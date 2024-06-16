cmake_minimum_required(VERSION 3.1)
project(project_name)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
# add_compile_options(-pthread) fail

add_executable(a.out ./demo_three.cc)

