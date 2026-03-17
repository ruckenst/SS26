#include "PaymentFinishedHandler.h"
#include <iostream>


bool PaymentFinishedHandler::handle(PaymentRequest &request) {
    std::cout << "Payment process finished!" << std::endl;

    return PaymentHandler::handle(request);
}
