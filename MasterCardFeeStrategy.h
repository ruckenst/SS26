#ifndef SS26_MASTERCARDFEESTRATEGY_H
#define SS26_MASTERCARDFEESTRATEGY_H

#include "FeeStrategy.h"

class MasterCardFeeStrategy : public FeeStrategy {
public:
    float calculateFee(float amount) override;
};

#endif //SS26_MASTERCARDFEESTRATEGY_H
