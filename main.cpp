#include <iostream>
#include <memory>
#include "Test.h"

void something(std::shared_ptr<Test> pointer) {
    if(true){
        auto myOtherTest = pointer;
    }
}

void something(std::weak_ptr<Test> pointer) {
    if(true){
        auto myOtherTest = pointer;
    }
}

void something(std::unique_ptr<Test> pointer) {
    if(true){
        //auto myOtherTest = pointer;
    }
}

int main() {
    Test* myTest = new Test();
    delete myTest;

    std::shared_ptr<Test> mySharedTest = std::make_shared<Test>();
    something(std::weak_ptr(mySharedTest));

    std::unique_ptr<Test> myUniqueTest = std::make_unique<Test>();
    //auto myOtherTest = myUniqueTest;
    //something(myUniqueTest);

    return 0;
}