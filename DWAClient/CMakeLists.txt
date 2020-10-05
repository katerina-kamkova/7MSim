cmake_minimum_required(VERSION 3.17)
project(DWAClient)

set(CMAKE_CXX_STANDARD 14)

add_executable(DWAClient main.cpp SafeQueue.h ObstacleAvoidance.cpp ObstacleAvoidance.h WorldStructures.h)