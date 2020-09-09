cmake_minimum_required(VERSION 3.16)
project(arbiter)

set(CMAKE_CXX_STANDARD 14)

add_executable(arbiter main.cpp game.cpp game.h server.cpp server.h robot.cpp robot.h)