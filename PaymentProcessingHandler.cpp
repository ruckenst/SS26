#include "PaymentProcessingHandler.h"
#include "FeeStrategyFactory.h"

#include <iostream>

bool PaymentProcessingHandler::handle(PaymentRequest &request) {
    float fee = FeeStrategyFactory::createStrategy(request.provider)->calculateFee(request.amount);

    std::cout << "=====================" << std::endl;
    std::cout << "Payment complete!" << std::endl;
    std::cout << "Amount: " << request.amount << std::endl;
    std::cout << "Fee:    " << fee << std::endl;
    std::cout << "Total:  " << request.amount + fee << std::endl;
    std::cout << "=====================" << std::endl;

    return PaymentHandler::handle(request);
}
