#include "PaymentRequest.h"

PaymentRequest::PaymentRequest(PaymentProvider provider, float amount) {
    this->provider = provider;
    this->amount = amount;
}
