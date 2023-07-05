cmake_minimum_required(VERSION 3.1)
project(project_name)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Boost COMPONENTS thread chrono REQUIRED)

add_executable(${PROJECT_NAME} demo.cc)
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})

    message(STATUS "Boost_INCLUDE_DIRS = ${Boost_INCLUDE_DIRS}.")
    message(STATUS "Boost_LIBRARIES = ${Boost_LIBRARIES}.")
    message(STATUS "Boost_LIB_VERSION = ${Boost_LIB_VERSION}.")
endif()

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/install)
message("Source tree: ${PROJECT_SOURCE_DIR}")
message("Install tree: " ${CMAKE_INSTALL_PREFIX})

# lib will be created under directory install
install(TARGETS ${PROJECT_NAME} DESTINATION lib)

