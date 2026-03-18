#ifndef SS26_PAYPALFEESTRATEGY_H
#define SS26_PAYPALFEESTRATEGY_H

#include "FeeStrategy.h"

class PayPalFeeStrategy : public FeeStrategy {
public:
    float calculateFee(float amount) override;
};

#endif //SS26_PAYPALFEESTRATEGY_H
