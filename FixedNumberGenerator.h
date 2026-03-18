#ifndef SS26_FIXEDNUMBERGENERATOR_H
#define SS26_FIXEDNUMBERGENERATOR_H

#include "RandomNumberGenerator.h"

class FixedNumberGenerator : public RandomNumberGenerator {
public:
    FixedNumberGenerator(int number);
    int getRandomNumber(int min, int max) override;

private:
    int number;
};

#endif //SS26_FIXEDNUMBERGENERATOR_H
