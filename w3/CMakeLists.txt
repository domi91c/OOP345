cmake_minimum_required(VERSION 3.8)
project(w3)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES w3.cpp Text.cpp Text.h)
add_executable(w3 ${SOURCE_FILES})