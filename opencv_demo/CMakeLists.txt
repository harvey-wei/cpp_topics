cmake_minimum_required(VERSION 3.1)
project(proj)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# http://wiki.ros.org/vision_opencv#Using_OpenCV_in_your_ROS_code
add_executable(a.out demo.cc)
target_link_libraries(a.out ${OpenCV_LIBRARIES})

