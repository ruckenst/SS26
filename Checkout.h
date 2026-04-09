#ifndef SS26_CHECKOUT_H
#define SS26_CHECKOUT_H

#include "Customer.h"
#include <queue>

class Checkout {
public:
    void print() const;
    void enqueueCustomer(Customer customer);
    void processCustomer();

private:
    std::queue<Customer> customers;
};

#endif //SS26_CHECKOUT_H
