#include <iostream>

namespace myNamespace {
    void increment(int& i) {
        i++;
    }

    void myFunc() {
        int i = 123;
        increment(i);

        std::cout << "i: " << i << std::endl;

        bool isTrue = true;
        std::string myString = "Some String";

        int xyz;
        int abc;
        std::cout << "Enter xyz: ";
        std::cin >> xyz >> abc;

        std::cout << "Hello! " << xyz << ", " << abc << "!" << std::endl;
    }
}

namespace myOtherNamespace {
    void myFunc() {
        std::cout << "Bye!\n";
    }
}

//using namespace myNamespace;
//using namespace myOtherNamespace;

int main() {
    myNamespace::myFunc();
    myOtherNamespace::myFunc();

    return 0;
}