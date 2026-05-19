cmake_minimum_required(VERSION 3.30)
project(SS26)

set(CMAKE_CXX_STANDARD 20)

add_executable(SS26 main.cpp
        Animal.cpp
        Animal.h
        Elephant.cpp
        Elephant.h
        Lion.cpp
        Lion.h
        Penguin.cpp
        Penguin.h
        Zoo.cpp
        Zoo.h
)