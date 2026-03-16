cmake_minimum_required(VERSION 3.30)
project(SS26)

set(CMAKE_CXX_STANDARD 20)

add_executable(SS26
        main.cpp
        MyStaticClass.cpp
        MyStaticClass.h
        WorldGenerator.cpp
        WorldGenerator.h
        IRandomNumberGenerator.h
        MersenneTwisterRandomNumberGenerator.cpp
        MersenneTwisterRandomNumberGenerator.h
        FixedRandomNumberGenerator.cpp
        FixedRandomNumberGenerator.h
)