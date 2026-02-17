#include <iostream>

namespace myNamespace {
    void increment(int& i) {
        i++;
    }

    void myFunc() {
        int xyz;
        bool myBool = true;
        std::string myString;

        std::cout << "Enter name: ";
        std::cin >> myString;

        std::cout << "Enter xyz: ";
        std::cin >> xyz;

        increment(xyz);

        std::cout << "Hello " << std::endl << myString << "; " << xyz << " world!\n";
    }
}

namespace myOtherNamespace {
    void myFunc() {
        std::cout << "Bye world!" << std::endl;
    }
}

//using namespace myNamespace;
//using namespace myOtherNamespace;

int main() {
    myNamespace::myFunc();
    myOtherNamespace::myFunc();

    return 0;
}