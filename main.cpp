#include <iostream>
#include "FeeStrategy.h"
#include "FeeStrategyFactory.h"
#include "PaymentStartedHandler.h"
#include "PaymentProcessingHandler.h"
#include "PaymentFinishedHandler.h"

void pay(FeeStrategy* strategy, float amount) {
    float fee = strategy->calculateFee(amount);

    std::cout << "Paid:  " << amount << std::endl;
    std::cout << "Fee:   " << fee << std::endl;
    std::cout << "Total: " << amount + fee << std::endl;
}

int main() {
    //pay(FeeStrategyFactory::getStrategy(PayPal), 10.50);

    PaymentStartedHandler paymentStartedHandler;
    PaymentProcessingHandler paymentProcessingHandler;
    PaymentFinishedHandler paymentFinishedHandler;

    paymentStartedHandler.setNext(&paymentProcessingHandler);
    paymentProcessingHandler.setNext(&paymentFinishedHandler);

    PaymentRequest request(PayPal, 20.00);
    paymentStartedHandler.handle(request);

    return 0;
}