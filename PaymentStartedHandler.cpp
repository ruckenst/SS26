#include "PaymentStartedHandler.h"

#include <iostream>

bool PaymentStartedHandler::handle(PaymentRequest &request) {
    std::cout << "Payment starting..." << std::endl;

    return PaymentHandler::handle(request);
}
