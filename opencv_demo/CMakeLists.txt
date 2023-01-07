cmake_minimum_required(VERSION 3.1)
project(proj)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# https://blog.csdn.net/zhanghm1995/article/details/105466372

# This where <PackageName>Config.cmake or Find<PackageName>.cmake are.
set(OpenCV_DIR "/opt/homebrew/lib/cmake/opencv4")

find_package(OpenCV REQUIRED)
if (OpenCV_FOUND)
message(STATUS "OpenCV_DIR" = ${OpenCV_DIR})
message(STATUS "OpenCV_ROOT" = ${OpenCV_ROOT})
message(STATUS "OpenCV_INCLUDE_DIRS" = ${OpenCV_INCLUDE_DIRS})
message(STATUS "OpenCV_LIBRARIES" = ${OpenCV_LIBRARIES})

include_directories(${OpenCV_INCLUDE_DIRS})

# http://wiki.ros.org/vision_opencv#Using_OpenCV_in_your_ROS_code
add_executable(a.out demo.cc)

# Don't forget to link your target to opencv lib
target_link_libraries(a.out ${OpenCV_LIBRARIES})
endif()

