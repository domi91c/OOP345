cmake_minimum_required(VERSION 3.8)
project(w1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp CString.cpp CString.h process.cpp process.h)
add_executable(w1 ${SOURCE_FILES})