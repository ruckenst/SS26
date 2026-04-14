#ifndef SS26_FLATWORLDCHUNKGENERATOR_H
#define SS26_FLATWORLDCHUNKGENERATOR_H


#include "ChunkGenerator.h"

class FlatWorldChunkGenerator : public ChunkGenerator {
public:
    void generate(Chunk& chunk) const override;
};


#endif //SS26_FLATWORLDCHUNKGENERATOR_H
