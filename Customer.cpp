#include "Customer.h"
#include <iostream>
#include <algorithm>

void Customer::print() const {
    int i = 1;
    for(const auto& item : items) {
        std::cout << i++ << ". " << item << std::endl;
    }

//    for(int j = 0; j < items.size(); j++) {
//        std::cout << j + 1 << ". " << items[j] << std::endl;
//    }
}

void Customer::insertItem(std::string newItem) {
    items.push_back(newItem);

    /*
    std::ranges::sort(items, [](std::string left, std::string right) {
        return left < right;
    });
    */

    std::sort(items.begin(), items.end(), std::greater());
}

int Customer::getItemCount() const {
    return items.size();
}
