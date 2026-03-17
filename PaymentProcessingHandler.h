#ifndef SS26_PAYMENTPROCESSINGHANDLER_H
#define SS26_PAYMENTPROCESSINGHANDLER_H


#include "PaymentHandler.h"

class PaymentProcessingHandler : public PaymentHandler {
public:
    bool handle(PaymentRequest& request) override;
};


#endif //SS26_PAYMENTPROCESSINGHANDLER_H
