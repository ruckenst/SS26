#include "Chunk.h"
#include "ConsoleChunkRenderer.h"
#include "FlatWorldChunkGenerator.h"

int main() {
    Chunk myChunk;

    ChunkGenerator* myGenerator = new FlatWorldChunkGenerator();
    myGenerator->generate(myChunk);
    delete myGenerator;

    ChunkRenderer* myRenderer = new ConsoleChunkRenderer();
    myRenderer->render(myChunk);

    delete myRenderer;

    return 0;
}