cmake_minimum_required(VERSION 3.1)
project(proj)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# https://stackoverflow.com/questions/14231292/cmake-and-compiler-warnings

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "/opt/homebrew/Cellar/qt@5/5.15.6/lib/cmake/Qt5")
find_package(PCL 1.12 REQUIRED COMPONENTS common io)
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

get_target_property(JSON_INC_PATH jsoncpp_lib INTERFACE_INCLUDE_DIRECTORIES)
include_directories(${JSON_INC_PATH})


add_executable(a.out demo.cc)
target_link_libraries(a.out jsoncpp_lib)
# target_link_libraries(a.out ${PCL_LIBRARIES} ${OpenCV_LIBS})
target_link_libraries(a.out ${PCL_LIBRARIES})
target_link_libraries(a.out ${OpenCV_LIBS})
