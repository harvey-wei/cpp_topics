cmake_minimum_required(VERSION 3.1)
project(project_name)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

link_directories("/opt/homebrew/Cellar/boost/1.80.0/lib")
include_directories("/opt/homebrew/Cellar/boost/1.80.0/include")

add_executable(a.out demo.cc)

