cmake_minimum_required(VERSION 3.30)
project(SS26)

set(CMAKE_CXX_STANDARD 20)

add_library(fibonacci_lib src/fibonacci.cpp)
target_include_directories(fibonacci_lib PUBLIC src/)

add_executable(SS26 src/main.cpp)
target_link_libraries(SS26 PRIVATE fibonacci_lib)

add_subdirectory(libs/Catch2)
add_executable(tests tests/fibonacciTests.cpp)
target_link_libraries(tests PRIVATE fibonacci_lib Catch2::Catch2WithMain)