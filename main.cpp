#include "Chunk.h"
#include "ConsoleChunkRenderer.h"
#include "FlatChunkGenerator.h"

int main() {
    Chunk myChunk;

    ChunkGenerator* myChunkGenerator = new FlatChunkGenerator();
    myChunkGenerator->generate(myChunk);

    delete myChunkGenerator;

    ChunkRenderer* myChunkRenderer = new ConsoleChunkRenderer();

    myChunkRenderer->render(myChunk);

    delete myChunkRenderer;

    return 0;
}