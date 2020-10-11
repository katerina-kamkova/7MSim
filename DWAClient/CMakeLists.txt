cmake_minimum_required(VERSION 3.17)
project(DWAClient)

find_package(Protobuf REQUIRED)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_COMPILER g++)

add_executable(DWAClient main.cpp ObstacleAvoidance.h ObstacleAvoidance.cpp world_data.pb.h world_data.pb.cc)

target_include_directories(${PROJECT_NAME}
        PUBLIC ${CMAKE_CURRENT_BINARY_DIR}
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
        PUBLIC ${PROTOBUF_INCLUDE_DIRS}
        )
target_link_libraries(${PROJECT_NAME} ${PROTOBUF_LIBRARIES})
