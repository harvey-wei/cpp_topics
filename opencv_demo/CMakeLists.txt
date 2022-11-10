cmake_minimum_required(VERSION 3.1)
project(proj)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(a.out demo.cc)
target_link_libraries(a.out ${OpenCV_LIBS})

