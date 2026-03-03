#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle(Coordinate position, Coordinate oppositePosition) : Shape(position) {
    this->oppositePosition = oppositePosition;
}

void Rectangle::print() const {
    std::cout << "\033[32m";
    std::cout << "xA: " << position.x << "; yA: " << position.y << std::endl;
    std::cout << "xB: " << oppositePosition.x << "; yB: " << position.y << std::endl;
    std::cout << "xC: " << oppositePosition.x << "; yC: " << oppositePosition.y << std::endl;
    std::cout << "xD: " << position.x << "; yD: " << oppositePosition.y << std::endl;
    std::cout << "\033[0m";
}
