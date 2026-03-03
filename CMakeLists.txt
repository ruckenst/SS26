cmake_minimum_required(VERSION 3.30)
project(SS26)

set(CMAKE_CXX_STANDARD 20)

add_executable(SS26
        main.cpp
        Shape.cpp
        Circle.cpp
        Triangle.cpp
        Triangle.h
        Rectangle.cpp
        Rectangle.h
        Coordinate.h
)