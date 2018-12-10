cmake_minimum_required(VERSION 2.8)
project(OpticalFlow)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake-modules)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)


find_package(OpenCV REQUIRED)

message(${CMAKE_MODULE_PATH})
message(${OpenCV_INCLUDE_DIRS})
#message(${OpenCV_LIBRARIES_DIRS})
message(${OpenCV_LIBS})

include_directories(${OpenCV_INCLUDE_DIRS})


set(SOURCE_FILES main.cpp)


add_executable(decode_ip_camera ${SOURCE_FILES})


target_link_libraries(decode_ip_camera ${OpenCV_LIBS})
