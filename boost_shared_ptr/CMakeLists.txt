cmake_minimum_required(VERSION 3.1)
project(project_name)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(BOOST_LIB_PATH "$ENV{HOME}/Desktop/Files/research/code/cpp_basic_topics/boost_includes")
# set(BOOST_LIB_PATH "$ENV{HOME}/Desktop/Files/research/code/cpp_basic_topics/boost_lib/")
message("The path to boost library is ${BOOST_LIB_PATH}")
include_directories(${BOOST_LIB_PATH})

add_executable(a.out demo.cc)

