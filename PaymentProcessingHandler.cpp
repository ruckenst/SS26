#include "PaymentProcessingHandler.h"
#include "FeeStrategyFactory.h"

#include <iostream>

bool PaymentProcessingHandler::handle(PaymentRequest &request) {
    float fee = FeeStrategyFactory::getStrategy(request.provider)->calculateFee(request.amount);

    std::cout << "Paid:  " << request.amount << std::endl;
    std::cout << "Fee:   " << fee << std::endl;
    std::cout << "Total: " << request.amount + fee << std::endl;

    return PaymentHandler::handle(request);
}
