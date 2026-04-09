#ifndef SS26_CUSTOMER_H
#define SS26_CUSTOMER_H

#include <string>
#include <vector>

class Customer {
public:
    void print() const;
    void insertItem(std::string newItem);
    int getItemCount() const;

private:
    std::vector<std::string> items;
};

#endif //SS26_CUSTOMER_H
