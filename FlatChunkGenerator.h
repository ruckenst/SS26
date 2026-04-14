#ifndef SS26_FLATCHUNKGENERATOR_H
#define SS26_FLATCHUNKGENERATOR_H


#include "ChunkGenerator.h"

class FlatChunkGenerator : public ChunkGenerator {
public:
    void generate(Chunk& chunk) const override;
};


#endif //SS26_FLATCHUNKGENERATOR_H
