#ifndef SS26_IRANDOMNUMBERGENERATOR_H
#define SS26_IRANDOMNUMBERGENERATOR_H

class IRandomNumberGenerator {
public:
    virtual ~IRandomNumberGenerator() = default;

    virtual int getRandomNumber(int min, int max) = 0;
};

#endif //SS26_IRANDOMNUMBERGENERATOR_H
