#ifndef SS26_RANDOMNUMBERGENERATOR_H
#define SS26_RANDOMNUMBERGENERATOR_H

class RandomNumberGenerator {
public:
    virtual ~RandomNumberGenerator() = default;
    virtual int getRandomNumber(int min, int max) = 0;
};

#endif //SS26_RANDOMNUMBERGENERATOR_H
