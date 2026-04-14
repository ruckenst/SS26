#ifndef SS26_CONSOLECHUNKRENDERER_H
#define SS26_CONSOLECHUNKRENDERER_H

#include "ChunkRenderer.h"

class ConsoleChunkRenderer : public ChunkRenderer {
public:
    void render(Chunk chunk) const override;

private:
    void printBlock(BlockType blockType) const;
};

#endif //SS26_CONSOLECHUNKRENDERER_H
