cmake_minimum_required(VERSION 3.1)
project(grabDetection)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# https://stackoverflow.com/questions/14231292/cmake-and-compiler-warnings

set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "/opt/homebrew/Cellar/qt@5/5.15.6/lib/cmake/Qt5")

find_package(PCL 1.12 REQUIRED COMPONENTS common io)
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})
add_executable(a.out demo.cc)
target_link_libraries(a.out ${PCL_LIBRARIES})
