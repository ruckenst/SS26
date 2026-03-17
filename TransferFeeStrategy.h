#ifndef SS26_TRANSFERFEESTRATEGY_H
#define SS26_TRANSFERFEESTRATEGY_H

#include "FeeStrategy.h"

class TransferFeeStrategy : public FeeStrategy {
public:
    float calculateFee(float amount) override;
};

#endif //SS26_TRANSFERFEESTRATEGY_H
