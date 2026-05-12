#include <iostream>
#include <memory>
#include "Test.h"

void something(std::shared_ptr<Test>& testPointer) {
    if(true){
        auto myOtherSharedTest = testPointer;
    }
}

void something(std::weak_ptr<Test> testPointer) {
    if(true){
        auto myOtherSharedTest = testPointer;
    }
}

int main() {
    Test* myTest = new Test();
    delete myTest;

    std::shared_ptr<Test> mySharedTest = std::make_shared<Test>();
    std::cout << "Before Function" << std::endl;
    something(mySharedTest);
    something(std::weak_ptr<Test>(mySharedTest));
    std::cout << "After Function" << std::endl;

    std::unique_ptr<Test> myUniqueTest = std::make_unique<Test>();


    return 0;
}