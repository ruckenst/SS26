#include "FeeStrategyFactory.h"
#include "TransferFeeStrategy.h"
#include "PayPalFeeStrategy.h"
#include "MasterCardFeeStrategy.h"

static TransferFeeStrategy   transferStrategy;
static PayPalFeeStrategy     paypalStrategy;
static MasterCardFeeStrategy mastercardStrategy;

FeeStrategy* FeeStrategyFactory::strategies[3] = {
        &transferStrategy,
        &paypalStrategy,
        &mastercardStrategy
};

FeeStrategy* FeeStrategyFactory::createStrategy(PaymentProvider provider) {
    if(provider >= 3) {
        return nullptr;
    }

    return strategies[provider];
}
