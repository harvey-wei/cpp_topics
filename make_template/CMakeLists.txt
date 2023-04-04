cmake_minimum_required(VERSION 3.1)
project(project_name)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(${PROJECT_NAME} demo.cc)


set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/install)
message("Source tree: ${PROJECT_SOURCE_DIR}")
message("Install tree: " ${CMAKE_INSTALL_PREFIX})

# lib will be created under directory install
install(TARGETS ${PROJECT_NAME} DESTINATION lib)

