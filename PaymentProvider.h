#ifndef SS26_PAYMENTPROVIDER_H
#define SS26_PAYMENTPROVIDER_H

enum PaymentProvider {
    Transfer,   // 0% Fee
    PayPal,     // 1.5% Fee
    MasterCard  // 2% Fee + 0.10
};

#endif //SS26_PAYMENTPROVIDER_H
