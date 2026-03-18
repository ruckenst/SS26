#include "MyClass.h"
#include <iostream>

int MyClass::numberOfReferences = 0;

MyClass::MyClass(int value) {
    this->value = value;

    MyClass::numberOfReferences++;
}

void MyClass::print() const {
    std::cout << value << std::endl;
}

int MyClass::getNumberOfReferences() {
    return MyClass::numberOfReferences;
}