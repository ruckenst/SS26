#include <iostream>
#include <array>
#include <vector>
#include "LinkedList.h"

template <typename T>
void printSomething(T something){
    std::cout << "Something: " << something << std::endl;
}

int main() {
    LinkedList<int> myList;

    myList.insertBack(10);
    myList.print();

    double myVar = 123;

    printSomething(myVar);
    printSomething<double>(123);
    printSomething(123.567);
    printSomething("Something");
    return 0;
}