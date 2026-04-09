#include <iostream>
#include "Customer.h"
#include "Checkout.h"

int main() {
    Checkout checkout;
    Customer myCustomer;

    myCustomer.insertItem("Tomaten");
    myCustomer.insertItem("Zwiebel");
    myCustomer.insertItem("Orangensaft");
    myCustomer.insertItem("Cola");

    checkout.print();

    checkout.enqueueCustomer(myCustomer);

    checkout.print();

    checkout.processCustomer();
    checkout.processCustomer();
    checkout.processCustomer();
    checkout.processCustomer();

    return 0;
}