#include "Chunk.h"

Chunk::Chunk() {
    /*
    for(int x = 0; x < chunkLength; x++) {
        for(int y = 0; y < chunkWidth; y++) {
            for(int z = 0; z < chunkHeight; z++) {
                chunkData[x][y][z] = BlockType::Air;
            }
        }
    }
    */

    // Oder kürzer:
    for(auto& xSlice : chunkData)
        for(auto& ySlice : xSlice)
            ySlice.fill(BlockType::Air);
}

BlockType Chunk::getBlock(int x, int y, int z) const {
    return chunkData[x][y][z];
}

void Chunk::setBlock(int x, int y, int z, BlockType blockType) {
    chunkData[x][y][z] = blockType;
}
