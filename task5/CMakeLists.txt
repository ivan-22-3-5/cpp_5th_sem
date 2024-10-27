cmake_minimum_required(VERSION 3.30)
project(task5)

set(CMAKE_CXX_STANDARD 23)

add_executable(task5 src/main.cpp
        src/Image.cpp
        src/Image.h
        src/loaders/ImageLoader.h
        src/loaders/PGMImageLoader.cpp
        src/loaders/PGMImageLoader.h
        src/loaders/PPMImageLoader.cpp
        src/loaders/PPMImageLoader.h
        src/Pixel.h)
