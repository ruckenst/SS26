#ifndef SS26_PAYMENTREQUEST_H
#define SS26_PAYMENTREQUEST_H

#include "PaymentProvider.h"

class PaymentRequest {
public:
    PaymentRequest(PaymentProvider provider, float amount);

    float amount;
    PaymentProvider provider;
};


#endif //SS26_PAYMENTREQUEST_H
