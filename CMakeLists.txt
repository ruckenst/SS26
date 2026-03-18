cmake_minimum_required(VERSION 3.30)
project(SS26)

set(CMAKE_CXX_STANDARD 20)

add_executable(SS26
        main.cpp
        WorldGenerator.cpp
        WorldGenerator.h
        MyClass.cpp
        MyClass.h
        RandomNumberGenerator.h
        MersenneTwister.cpp
        MersenneTwister.h
        FixedNumberGenerator.cpp
        FixedNumberGenerator.h
)