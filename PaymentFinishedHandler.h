#ifndef SS26_PAYMENTFINISHEDHANDLER_H
#define SS26_PAYMENTFINISHEDHANDLER_H

#include "PaymentHandler.h"

class PaymentFinishedHandler : public PaymentHandler {
public:
    bool handle(PaymentRequest& request) override;
};


#endif //SS26_PAYMENTFINISHEDHANDLER_H
