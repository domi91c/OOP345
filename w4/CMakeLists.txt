cmake_minimum_required(VERSION 3.8)
project(w4)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES w4.cpp KVList.h)
add_executable(w4 ${SOURCE_FILES})