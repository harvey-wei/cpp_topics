cmake_minimum_required(VERSION 3.1)
project(proj)

set(CMAKE_CXX_STANDARD 11)

# To make language server clangd  work properly.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Use LLDB
set(CMAKE_BUILD_TYPE Debug)

set(Qt5_DIR /opt/homebrew/Cellar/qt@5/5.15.7/lib/cmake/Qt5)
find_package(VTK)

# Load PCL library (brew install pcl)
find_package(PCL 1.1 REQUIRED)
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

# Install opencv from source (build locally)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

# # Install by brew install boost
link_directories("/opt/homebrew/Cellar/boost/1.80.0/lib")
include_directories("/opt/homebrew/Cellar/boost/1.80.0/include")

add_executable(a.out demo.cc)
# target_link_libraries(a.out ${PCL_LIBRARIES} ${OpenCV_LIBS})
target_link_libraries(a.out ${PCL_LIBRARIES} ${OpenCV_LIBS} ${Boost_LIBRARIES})
