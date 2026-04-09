#include <iostream>

#include "Customer.h"
#include "Checkout.h"

int main() {
    Checkout checkout;

    Customer myCustomer;
    myCustomer.addItem("Zwiebel");
    myCustomer.addItem("Tomate");
    myCustomer.addItem("Orangensaft");
    myCustomer.addItem("Cola");

    checkout.enqueueCustomer(myCustomer);
    checkout.enqueueCustomer(myCustomer);
    checkout.enqueueCustomer(myCustomer);
    checkout.enqueueCustomer(myCustomer);
    checkout.enqueueCustomer(myCustomer);

    checkout.print();

    checkout.processCustomer();

    checkout.print();

    checkout.processCustomer();

    return 0;
}