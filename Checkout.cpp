#include "Checkout.h"
#include <iostream>

void Checkout::print() const {
    std::cout << "Currently in line: " << customers.size() << std::endl;
}

void Checkout::enqueueCustomer(Customer customer) {
    customers.push(customer);
}

void Checkout::processCustomer() {
    if (customers.empty()) {
        std::cout << "The queue is empty!" << std::endl;
        return;
    }

    Customer currentCustomer = customers.front();

    std::cout << "Serving customer with items: " << currentCustomer.getItemCount() << std::endl;
    currentCustomer.print();

    customers.pop();
}