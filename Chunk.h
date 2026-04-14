#ifndef SS26_CHUNK_H
#define SS26_CHUNK_H

#include <array>
#include "BlockType.h"

constexpr int chunkWidth = 8;
constexpr int chunkDepth = 8;
constexpr int chunkHeight = 16;

class Chunk {
public:
    Chunk();

    BlockType getBlock(int x, int y, int z) const;
    void setBlock(int x, int y, int z, BlockType block);

private:
    // BlockType chunkData[chunkDepth][chunkWidth][chunkHeight];
    std::array<std::array<std::array<BlockType, chunkHeight>, chunkWidth>, chunkDepth> chunkData;
};


#endif //SS26_CHUNK_H
