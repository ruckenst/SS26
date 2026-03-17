#include "PaymentHandler.h"

PaymentHandler::PaymentHandler() {
    next = nullptr;
}

void PaymentHandler::setNext(PaymentHandler* next) {
    this->next = next;
}

bool PaymentHandler::handle(PaymentRequest &request) {
    if(next != nullptr){
        return next->handle(request);
    }

    return true;
}
