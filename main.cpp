#include <iostream>
#include <vector>
#include "LinkedList.h"

template<typename T>
void doSomething(T something) {
    std::cout << "Something: " << something << std::endl;
}

template<typename T>
void doSomethingWithVector(std::vector<T>& vector) {
    for(auto& element : vector) {
        std::cout << element << ", ";
    }

    std::cout << std::endl;
}

int main() {
    LinkedList<char> myList;

    myList.insertBack('a');
    myList.insertBack('X');
    myList.insertBack('3');
    myList.print([](char c) {
        std::cout << c;
    });

    myList.sort([](char left, char right) {
        return left < right;
    });

    std::vector<int> myIntegerVector = {1, 2, 3};
    std::vector<char> myCharVector = {'a', 'b', 'c'};

    doSomethingWithVector(myIntegerVector);
    doSomethingWithVector(myCharVector);

    int myIntegers[3] = {1, 2, 3};

    doSomething<char>(123);
    doSomething<int>(123.567);
    doSomething("Something");
    doSomething<int>('X');
    doSomething(myIntegers);
    return 0;
}