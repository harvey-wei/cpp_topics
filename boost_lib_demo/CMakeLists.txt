cmake_minimum_required(VERSION 3.1)
project(project_name)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


# https://www.jianshu.com/p/1827cd86d576
set(BOOST_ROOT /opt/homebrew/Cellar/boost/1.80.0)

find_package(Boost COMPONENTS thread regex REQUIRED)

if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})

    message(STATUS "Boost_INCLUDE_DIRS = ${Boost_INCLUDE_DIRS}.")
    message(STATUS "Boost_LIBRARIES = ${Boost_LIBRARIES}.")
    message(STATUS "Boost_LIB_VERSION = ${Boost_LIB_VERSION}.")

endif()

add_executable(a.out demo.cc)
target_link_libraries(a.out ${Boost_LIBRARIES})

