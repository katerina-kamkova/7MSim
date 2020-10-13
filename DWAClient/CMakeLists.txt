cmake_minimum_required(VERSION 3.17)
set(PROJECT_NAME DWAClient)
project(${PROJECT_NAME})

find_package(Protobuf REQUIRED)

set(PROTO_FILES ../protobuf/world_data.proto)

PROTOBUF_GENERATE_CPP(PROTO_SRC PROTO_HDR ${PROTO_FILES})

add_executable(DWAClient main.cpp ObstacleAvoidance.h ObstacleAvoidance.cpp ${PROTO_SRC} ${PROTO_HDR} ${PROTO_FILES} TCPServer.h  TCPServer.cpp )

target_include_directories(${PROJECT_NAME}
        PUBLIC ${CMAKE_CURRENT_BINARY_DIR}
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
        PUBLIC ${PROTOBUF_INCLUDE_DIRS}
        )
target_link_libraries(${PROJECT_NAME} ${PROTOBUF_LIBRARIES})
