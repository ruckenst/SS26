#ifndef SS26_FIXEDRANDOMNUMBERGENERATOR_H
#define SS26_FIXEDRANDOMNUMBERGENERATOR_H

#include "IRandomNumberGenerator.h"

class FixedRandomNumberGenerator : public IRandomNumberGenerator {
public:
    int getRandomNumber(int min, int max) override;
};

#endif //SS26_FIXEDRANDOMNUMBERGENERATOR_H
