#include "Customer.h"
#include <iostream>
#include <algorithm>

void Customer::addItem(std::string item) {
    items.push_back(item);

//    std::sort(items.begin(), items.end(), [](std::string left, std::string right) {
//        return left > right;
//    });

    std::ranges::sort(items, std::greater());
}

void Customer::print() const {
    for(int i = 0; i < items.size(); i++) {
        std::cout << i + 1 << ". " << items[i] << std::endl;
    }
}

int Customer::getItemCount() const {
    return items.size();
}
