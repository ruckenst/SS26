#include <iostream>
#include "WorldGenerator.h"
#include "MyClass.h"
#include "MersenneTwister.h"
#include "FixedNumberGenerator.h"

int main() {
    MyClass myClassA(1);
    MyClass myClassB(2);
    MyClass myClassC(3);

    myClassA.print();
    myClassB.print();
    myClassC.print();

    std::cout << "Number of References: " << MyClass::getNumberOfReferences() << std::endl;

    RandomNumberGenerator* rng = new MersenneTwister();

    WorldGenerator myGenerator(rng);

    delete rng;

    return 0;
}