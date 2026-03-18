#include "PaymentHandler.h"

void PaymentHandler::setNext(PaymentHandler* next) {
    this->next = next;
}

bool PaymentHandler::handle(PaymentRequest &request) {
    if(this->next != nullptr) {
        return this->next->handle(request);
    }

    return true;
}
