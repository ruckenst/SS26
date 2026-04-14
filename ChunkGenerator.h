#ifndef SS26_CHUNKGENERATOR_H
#define SS26_CHUNKGENERATOR_H

#include "Chunk.h"

class ChunkGenerator {
public:
    virtual ~ChunkGenerator() = default;
    virtual void generate(Chunk& chunk) const = 0;
};

#endif //SS26_CHUNKGENERATOR_H
