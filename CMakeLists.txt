cmake_minimum_required(VERSION 3.30)
project(SS26)

set(CMAKE_CXX_STANDARD 20)

add_executable(SS26
        main.cpp
        BlockType.h
        Chunk.cpp
        Chunk.h
        ChunkRenderer.h
        ConsoleChunkRenderer.cpp
        ConsoleChunkRenderer.h
        ChunkGenerator.h
        FlatWorldChunkGenerator.cpp
        FlatWorldChunkGenerator.h
)