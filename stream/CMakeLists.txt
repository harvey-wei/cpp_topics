cmake_minimum_required(VERSION 3.1)
project(project_name)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# add_executable(a.out demo_official.cc)
# add_executable(a.out ./demo_redirect.cc)
# add_executable(a.out demo_istream_get.cc)
add_executable(a.out ./demo.cc)

