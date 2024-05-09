cmake_minimum_required(VERSION 3.5)

project(7 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(7 main.cpp myarray.h myarray.cpp list.h list.cpp)

install(TARGETS 7
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
