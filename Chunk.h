#ifndef SS26_CHUNK_H
#define SS26_CHUNK_H

#include <array>
#include "BlockType.h"

constexpr int chunkHeight = 16;
constexpr int chunkWidth = 8;
constexpr int chunkLength = 8;

class Chunk {
public:
    Chunk();
    BlockType getBlock(int x, int y, int z) const;
    void setBlock(int x, int y, int z, BlockType blockType);

private:
    std::array<std::array<std::array<BlockType, chunkHeight>, chunkWidth>, chunkLength> chunkData;
};


#endif //SS26_CHUNK_H
