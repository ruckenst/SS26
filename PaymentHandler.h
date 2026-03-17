#ifndef SS26_PAYMENTHANDLER_H
#define SS26_PAYMENTHANDLER_H

#include "PaymentRequest.h"

class PaymentHandler {
public:
    PaymentHandler();
    void setNext(PaymentHandler* next);

    virtual bool handle(PaymentRequest& request);

protected:
    PaymentHandler* next;
};

#endif //SS26_PAYMENTHANDLER_H
