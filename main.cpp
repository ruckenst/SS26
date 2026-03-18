#include <iostream>
#include "FeeStrategy.h"
#include "FeeStrategyFactory.h"
#include "PaymentRequest.h"
#include "PaymentHandler.h"
#include "PaymentStartedHandler.h"
#include "PaymentProcessingHandler.h"
#include "PaymentFinishedHandler.h"

void pay(FeeStrategy* strategy, float amount) {
    float fee = strategy->calculateFee(amount);

    /*
    switch(provider) {
        case Transfer:
            fee = 0;
            break;
        case PayPal:
            fee = amount * 0.03;
            break;
        case MasterCard:
            fee = amount * 0.015 + 0.1;
            break;
        default:
            std::cout << "Unknown provider!" << std::endl;
            return;
    }
     */

    std::cout << "=====================" << std::endl;
    std::cout << "Payment complete!" << std::endl;
    std::cout << "Amount: " << amount << std::endl;
    std::cout << "Fee:    " << fee << std::endl;
    std::cout << "Total:  " << amount + fee << std::endl;
    std::cout << "=====================" << std::endl;
}

int main() {

    PaymentRequest myPaymentRequest(PayPal, 20.00);

    PaymentStartedHandler* paymentStartedHandler = new PaymentStartedHandler();
    PaymentProcessingHandler* paymentProcessingHandler = new PaymentProcessingHandler();
    PaymentFinishedHandler* paymentFinishedHandler = new PaymentFinishedHandler();

    paymentStartedHandler->setNext(paymentProcessingHandler);
    paymentProcessingHandler->setNext(paymentFinishedHandler);

    paymentStartedHandler->handle(myPaymentRequest);

    return 0;
}