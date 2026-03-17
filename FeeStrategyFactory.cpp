#include "FeeStrategyFactory.h"
#include "PayPalFeeStrategy.h"
#include "TransferFeeStrategy.h"
#include "MasterCardFeeStrategy.h"

static TransferFeeStrategy  transferStrategy;
static PayPalFeeStrategy    paypalStrategy;
static MasterCardFeeStrategy mastercardStrategy;

FeeStrategy* FeeStrategyFactory::strategies[] = {
        &transferStrategy,  // Index 0 = Transfer
        &paypalStrategy,    // Index 1 = PayPal
        &mastercardStrategy // Index 2 = MasterCard
};

FeeStrategy *FeeStrategyFactory::getStrategy(PaymentProvider provider) {
    if (provider >= 3) {
        return nullptr;
    }

    return strategies[provider];
}
