#include "PaymentStartedHandler.h"
#include <iostream>

bool PaymentStartedHandler::handle(PaymentRequest &request) {
    std::cout << "Payment process started!" << std::endl;

    return PaymentHandler::handle(request);
}
