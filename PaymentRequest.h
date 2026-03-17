#ifndef SS26_PAYMENTREQUEST_H
#define SS26_PAYMENTREQUEST_H

#include "PaymentProvider.h"

class PaymentRequest {
public:
    PaymentProvider provider;
    float amount;

    PaymentRequest(PaymentProvider provider, float amount);
};

#endif //SS26_PAYMENTREQUEST_H
