#include "Triangle.h"
#include <iostream>

Triangle::Triangle(Coordinate cornerAPosition, Coordinate cornerBPosition, Coordinate cornerCPosition) : Shape(cornerAPosition) {
    this->cornerBPosition = cornerBPosition;
    this->cornerCPosition = cornerCPosition;
}

void Triangle::print() const {
    std::cout << "xA: " << position.x << "; yA: " << position.y << std::endl;
    std::cout << "xB: " << cornerBPosition.x << "; yB: " << cornerBPosition.y << std::endl;
    std::cout << "xC: " << cornerCPosition.x << "; yC: " << cornerCPosition.y << std::endl;
}