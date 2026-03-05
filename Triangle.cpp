#include "Triangle.h"
#include <iostream>

Triangle::Triangle(Coordinate cornerAPosition, Coordinate cornerBPosition, Coordinate cornerCPosition, Color color)
    : Shape(cornerAPosition, color) {
    this->cornerBPosition = cornerBPosition;
    this->cornerCPosition = cornerCPosition;
}

void Triangle::print() const {
    std::cout << getColorCode(color);
    std::cout << "xA: " << position.x << "; yA: " << position.y << std::endl;
    std::cout << "xB: " << cornerBPosition.x << "; yB: " << cornerBPosition.y << std::endl;
    std::cout << "xC: " << cornerCPosition.x << "; yC: " << cornerCPosition.y << std::endl;
    std::cout << RESET;
}

Triangle* Triangle::clone() const {
    return new Triangle(*this);
}