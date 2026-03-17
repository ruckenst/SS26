#ifndef SS26_PAYMENTSTARTEDHANDLER_H
#define SS26_PAYMENTSTARTEDHANDLER_H

#include "PaymentHandler.h"

class PaymentStartedHandler : public PaymentHandler {
public:
    bool handle(PaymentRequest& request) override;
};


#endif //SS26_PAYMENTSTARTEDHANDLER_H
