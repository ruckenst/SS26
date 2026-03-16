#include "MyStaticClass.h"

int MyStaticClass::objectCount = 0;

MyStaticClass::MyStaticClass(int id) {
    this->id = id;
    MyStaticClass::objectCount++;
}

void MyStaticClass::print() const {
    std::cout << "id: " << id << " (" << MyStaticClass::objectCount << ")" << std::endl;
}

int MyStaticClass::getObjectCount() {
    return MyStaticClass::objectCount;
}