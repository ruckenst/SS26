#include "PaymentFinishedHandler.h"

#include <iostream>

bool PaymentFinishedHandler::handle(PaymentRequest &request) {
    std::cout << "Payment finished!" << std::endl;

    return PaymentHandler::handle(request);
}
