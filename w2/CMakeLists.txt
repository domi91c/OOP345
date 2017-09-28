cmake_minimum_required(VERSION 3.8)
project(w2)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp Stations.cpp Stations.h Station.cpp Station.h)
add_executable(w2 ${SOURCE_FILES})