cmake_minimum_required(VERSION 3.16)
set(PROJECT_NAME DWAClient)
project(${PROJECT_NAME})

find_package(Protobuf REQUIRED)

file (GLOB PROTO_FILES ../protobuf/ssl-vision/*.proto)
set(WORLD_DATA_PROTO_FILE ../protobuf/world_data.proto)

PROTOBUF_GENERATE_CPP(PROTO_SRC PROTO_HDR ${PROTO_FILES} ${WORLD_DATA_PROTO_FILE})

add_executable(DWAClient main.cpp ${PROTO_SRC} ${PROTO_HDR} ${PROTO_FILES} ${WORLD_DATA_PROTO_FILE} UDPServer.h UDPServer.cpp
        TCPServer.h TCPServer.cpp ObstacleAvoidance.h ObstacleAvoidance.cpp)

target_include_directories(${PROJECT_NAME}
        PUBLIC ${CMAKE_CURRENT_BINARY_DIR}
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
        PUBLIC ${PROTOBUF_INCLUDE_DIRS}
        )
target_link_libraries(${PROJECT_NAME} ${PROTOBUF_LIBRARIES})
