#include <iostream>
#include "MyStaticClass.h"
#include "WorldGenerator.h"
#include "MersenneTwisterRandomNumberGenerator.h"
#include "FixedRandomNumberGenerator.h"

int main() {
    MyStaticClass someClassA(1);
    MyStaticClass someClassB(2);
    MyStaticClass someClassC(3);

    someClassA.print();
    someClassB.print();
    someClassC.print();

    std::cout << MyStaticClass::getObjectCount() << std::endl;

    //IRandomNumberGenerator* rng = new MersenneTwisterRandomNumberGenerator();
    IRandomNumberGenerator* rng = new FixedRandomNumberGenerator();

    WorldGenerator myWorld(rng);

    delete rng;

    return 0;
}