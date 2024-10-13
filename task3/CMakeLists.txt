cmake_minimum_required(VERSION 3.30)
project(task3)

set(CMAKE_CXX_STANDARD 20)

add_executable(task3
        src/main.cpp
        src/serializer.h
        src/serializer.cpp
        src/stringtools.cpp
        src/stringtools.h)
