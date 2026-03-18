#include "WorldGenerator.h"
#include <random>
#include <iostream>

WorldGenerator::WorldGenerator(RandomNumberGenerator* rng) {
    for(int i = 0; i < 10; i++) {
        int randomNumber = rng->getRandomNumber(0, 10);
        if(randomNumber == 0) {
            randomNumber = 99;
        }

        std::cout << randomNumber << std::endl;
    }
}