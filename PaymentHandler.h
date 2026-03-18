#ifndef SS26_PAYMENTHANDLER_H
#define SS26_PAYMENTHANDLER_H

#include "PaymentRequest.h"

class PaymentHandler {
public:
    void setNext(PaymentHandler* next);

    virtual bool handle(PaymentRequest& request);

private:
    PaymentHandler* next;
};


#endif //SS26_PAYMENTHANDLER_H
