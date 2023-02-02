cmake_minimum_required(VERSION 3.1)
project(project_name)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# add_executable(a.out demo.cc)
add_executable(unix_time_dec ./unix_time_decimal_sec.cc)

