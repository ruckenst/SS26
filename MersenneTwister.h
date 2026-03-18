#ifndef SS26_MERSENNETWISTER_H
#define SS26_MERSENNETWISTER_H

#include "RandomNumberGenerator.h"

#include <random>

class MersenneTwister : public RandomNumberGenerator {
public:
    MersenneTwister();

    int getRandomNumber(int min, int max) override;

private:
    std::mt19937 engine;
};


#endif //SS26_MERSENNETWISTER_H
