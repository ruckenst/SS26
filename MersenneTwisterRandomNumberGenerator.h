#ifndef SS26_MERSENNETWISTERRANDOMNUMBERGENERATOR_H
#define SS26_MERSENNETWISTERRANDOMNUMBERGENERATOR_H

#include "IRandomNumberGenerator.h"
#include <random>

class MersenneTwisterRandomNumberGenerator : public IRandomNumberGenerator {
public:
    MersenneTwisterRandomNumberGenerator();
    int getRandomNumber(int min, int max) override;

private:
    std::mt19937 engine;
};

#endif //SS26_MERSENNETWISTERRANDOMNUMBERGENERATOR_H
