#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle(Coordinate position, Coordinate oppositeSidePosition, Color color)
    : Shape(position, color) {
    this->oppositeSidePosition = oppositeSidePosition;
}

void Rectangle::print() const {
    std::cout << getColorCode(color);
    std::cout << "xA: " << position.x << "; yA: " << position.y << std::endl;
    std::cout << "xB: " << oppositeSidePosition.x << "; yB: " << position.y << std::endl;
    std::cout << "xC: " << oppositeSidePosition.x << "; yC: " << oppositeSidePosition.y << std::endl;
    std::cout << "xD: " << position.x << "; yD: " << oppositeSidePosition.y << std::endl;
    std::cout << RESET;
}

Rectangle* Rectangle::clone() const {
    return new Rectangle(*this);
}
