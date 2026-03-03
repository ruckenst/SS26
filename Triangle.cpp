#include "Triangle.h"
#include <iostream>

Triangle::Triangle(Coordinate positionA, Coordinate positionB, Coordinate positionC) : Shape(positionA) {
    this->positionB = positionB;
    this->positionC = positionC;
}

void Triangle::print() const {
    std::cout << "xA: " << position.x << "; yA: " << position.y << std::endl;
    std::cout << "xB: " << positionB.x << "; yB: " << positionB.y << std::endl;
    std::cout << "xC: " << positionC.x << "; yC: " << positionC.y << std::endl;
}
