cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_STANDARD 23)
set (CMAKE_C_COMPILER icx)
set(CMAKE_BUILD_TYPE "Release")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Ofast")

project(WebServer)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SRC_LIST)

add_executable(WebServer ${SRC_LIST})