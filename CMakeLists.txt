cmake_minimum_required(VERSION 3.2)

project(DijkstraDHeap)

include_directories(include)

add_subdirectory(Read_from_a_file)
add_subdirectory(Console_input_of_parameters)

# REPORT
message( STATUS "")
message( STATUS "General configuration for ${PROJECT_NAME}")
message( STATUS "======================================")
message( STATUS "")
message( STATUS "   Configuration: ${CMAKE_BUILD_TYPE}")
message( STATUS "")