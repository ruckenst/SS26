#include "ConsoleChunkRenderer.h"
#include <iostream>

void ConsoleChunkRenderer::render(Chunk chunk) const {
    for (int x = 0; x < chunkLength; x++) {
        for (int z = 0; z < chunkHeight; z++) {
            for (int y = 0; y < chunkWidth; y++) {
                printBlock(chunk.getBlock(x, y, z));
            }

            std::cout << std::endl;
        }

        std::cout << std::endl;
    }
}

void ConsoleChunkRenderer::printBlock(BlockType blockType) const {
    switch (blockType) {
        case BlockType::Air:
            std::cout << "\033[104m" << " ";
            break;
        case BlockType::Cobble:
            std::cout << "\033[47m" << " ";
            break;
        case BlockType::Dirt:
            std::cout << "\033[43m" << " ";
            break;
        case BlockType::Wood:
            std::cout << "\033[102m" << " ";
            break;
    }

    std::cout << "\033[0m";
}
