#ifndef SS26_CHUNKRENDERER_H
#define SS26_CHUNKRENDERER_H

#include "Chunk.h"

class ChunkRenderer {
public:
    virtual ~ChunkRenderer() = default;
    virtual void render(Chunk chunk) const = 0;
};

#endif //SS26_CHUNKRENDERER_H
