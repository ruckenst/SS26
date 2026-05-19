#include "Animal.h"
#include <iostream>

Animal::Animal(std::string name) {
    this->name = name;
}

void Animal::printStats() const {
    std::cout << "[" << getType() << "] " << name << std::endl;
}