#include "FlatChunkGenerator.h"

void FlatChunkGenerator::generate(Chunk &chunk) const {
    for (int x = 0; x < chunkLength; x++) {
        for (int y = 0; y < chunkWidth; y++) {
            for (int z = 0; z < chunkHeight; z++) {
                switch (z) {
                    case chunkHeight - 1:
                    case chunkHeight - 2:
                        chunk.setBlock(x, y, z, BlockType::Cobble);
                        break;
                    case chunkHeight - 3:
                    case chunkHeight - 4:
                    case chunkHeight - 5:
                        chunk.setBlock(x, y, z, BlockType::Dirt);
                        break;
                    default:
                        chunk.setBlock(x, y, z, BlockType::Air);
                }
            }
        }
    }
}
