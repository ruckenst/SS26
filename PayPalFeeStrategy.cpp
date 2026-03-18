#include "PayPalFeeStrategy.h"

float PayPalFeeStrategy::calculateFee(float amount) {
    return amount * 0.03;
}
