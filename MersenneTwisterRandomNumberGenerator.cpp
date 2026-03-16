#include "MersenneTwisterRandomNumberGenerator.h"

MersenneTwisterRandomNumberGenerator::MersenneTwisterRandomNumberGenerator() {
    // Initialize RNG Generator
    engine = std::mt19937(std::random_device{}());
}

int MersenneTwisterRandomNumberGenerator::getRandomNumber(int min, int max) {
    // Define distribution
    std::uniform_int_distribution<int> dist(min, max);

    return dist(engine);
}
