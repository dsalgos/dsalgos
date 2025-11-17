cmake_minimum_required(VERSION 3.10)
project(dsalgos CXX)

# Require C++17 or later
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

##################################
#   PACKAGE THAT I AM BUILDING   #
##################################

# DSAlgo Library
add_library(dsalgos STATIC)
target_include_directories(dsalgos PUBLIC include)
target_sources(dsalgos PRIVATE src/dsalgos/Record.cpp src/dsalgos/graph/Graph.cpp src/dsalgos/graph/Node.cpp src/dsalgos/graph/Path.cpp)

add_executable(test tests/graph/testGraph.cpp)
target_include_directories(test PRIVATE include)
target_link_libraries(test PRIVATE dsalgos)