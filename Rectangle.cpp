#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle(Coordinate position, Coordinate oppositeSidePosition) : Shape(position) {
    this->oppositeSidePosition = oppositeSidePosition;
}

void Rectangle::print() const {
    std::cout << "\033[33m";
    std::cout << "xA: " << position.x << "; yA: " << position.y << std::endl;
    std::cout << "xB: " << oppositeSidePosition.x << "; yB: " << position.y << std::endl;
    std::cout << "xC: " << oppositeSidePosition.x << "; yC: " << oppositeSidePosition.y << std::endl;
    std::cout << "xD: " << position.x << "; yD: " << oppositeSidePosition.y << std::endl;
    std::cout << "\033[0m";
}
