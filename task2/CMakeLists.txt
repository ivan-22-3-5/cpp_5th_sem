cmake_minimum_required(VERSION 3.30)
project(task2)

set(CMAKE_CXX_STANDARD 20)

add_executable(task2 src/main.cpp
        src/stringtools.cpp
        src/stringtools.h
        src/filenames_parser.cpp
        src/filenames_parser.h)

add_executable(test src/test.cpp
        src/filenames_parser.cpp
        src/filenames_parser.h
        src/stringtools.cpp
        src/stringtools.h)
