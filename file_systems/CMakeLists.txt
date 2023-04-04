cmake_minimum_required(VERSION 3.1)
project(project_name)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Don't forget to add filesystem as COMPONENT of Boost
find_package(Boost REQUIRED COMPONENTS filesystem)

if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    # add_executable(a.out ./create_file.cc)
    # add_executable(a.out ./extract_filename_ext.cc)
    # add_executable(a.out ./current_relative_path.cc)
    add_executable(a.out ./create_dir.cc)
    target_link_libraries(a.out ${Boost_LIBRARIES} )
endif()

