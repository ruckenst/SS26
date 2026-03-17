#ifndef SS26_FEESTRATEGYFACTORY_H
#define SS26_FEESTRATEGYFACTORY_H

#include "FeeStrategy.h"
#include "PaymentProvider.h"

class FeeStrategyFactory {
public:
    static FeeStrategy* getStrategy(PaymentProvider provider);

private:
    static FeeStrategy* strategies[3];
};

#endif //SS26_FEESTRATEGYFACTORY_H
