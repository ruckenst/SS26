#include "MasterCardFeeStrategy.h"

float MasterCardFeeStrategy::calculateFee(float amount) {
    return amount * 0.015 + 0.10;
}
