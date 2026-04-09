#include "Checkout.h"
#include <iostream>

void Checkout::enqueueCustomer(Customer customer) {
    customers.push(customer);
}

void Checkout::print() const {
    std::cout << "Currently in line: " << customers.size() << std::endl;
}

void Checkout::processCustomer() {
    if(customers.empty()) {
        std::cout << "The queue is currently empty!" << std::endl;
        return;
    }

    Customer currentCustomer = customers.front();
    std::cout << "Processing customer with item count: " << currentCustomer.getItemCount() << std::endl;
    currentCustomer.print();

    customers.pop();
}
