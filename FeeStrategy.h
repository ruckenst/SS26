#ifndef SS26_FEESTRATEGY_H
#define SS26_FEESTRATEGY_H

class FeeStrategy {
public:
    virtual ~FeeStrategy() = default;
    virtual float calculateFee(float amount) = 0;
};

#endif //SS26_FEESTRATEGY_H
