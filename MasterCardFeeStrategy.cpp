#include "MasterCardFeeStrategy.h"

float MasterCardFeeStrategy::calculateFee(float amount) {
    return amount * 0.02 + 0.1;
}
