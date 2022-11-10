cmake_minimum_required(VERSION 3.1)
project(grabDetection)

set(CMAKE_CXX_STANDARD 11)

# To make language server clangd  work properly.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Load PCL library (brew install pcl)
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "/opt/homebrew/Cellar/qt@5/5.15.6/lib/cmake/Qt5")
find_package(PCL 1.12 REQUIRED COMPONENTS common io)
include_directories(${PCL_INCLUDE_DIRS})
# link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

# Install from source (build locally)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})


# Install by brew install boost
link_directories("/opt/homebrew/Cellar/boost/1.80.0/lib")
include_directories("/opt/homebrew/Cellar/boost/1.80.0/include")

add_executable(a.out demo.cc)
target_link_libraries(a.out ${PCL_LIBRARIES} ${OpenCV_LIBS} ${PCL_LIBRARY_DIRS})
