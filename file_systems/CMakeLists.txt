cmake_minimum_required(VERSION 3.1)
project(project_name)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Don't forget to add filesystem as COMPONENT of Boost
find_package(Boost REQUIRED COMPONENTS filesystem)

if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(a.out ./create_file.cc)
    target_link_libraries(a.out ${Boost_LIBRARIES} )
endif()

