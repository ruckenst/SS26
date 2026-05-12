#include "Test.h"
#include <iostream>

Test::Test() {
    std::cout << "Class created" << std::endl;
}

Test::~Test() {
    std::cout << "Class deleted" << std::endl;
}
