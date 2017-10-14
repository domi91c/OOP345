cmake_minimum_required(VERSION 3.8)
project(w5)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES w5.cpp Message.cpp Message.h Notifications.cpp Notifications.h)
add_executable(w5 ${SOURCE_FILES})