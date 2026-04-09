#ifndef SS26_CUSTOMER_H
#define SS26_CUSTOMER_H

#include <string>
#include <vector>

class Customer {
public:
    void addItem(std::string item);
    void print() const;
    int getItemCount() const;

private:
    std::vector<std::string> items;
};

#endif //SS26_CUSTOMER_H
