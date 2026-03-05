#include "Circle.h"
#include <iostream>

Circle::Circle(Coordinate position, int radius, Color color) : Shape(position, color) {
    this->radius = radius;
}

Circle::~Circle(){
    std::cout << "Deleting Circle" << std::endl;
}

int Circle::getRadius() const {
    return radius;
}

void Circle::setRadius(int newRadius) {
    if(newRadius <= 0) {
        std::cerr << "Radius must be bigger than 0!" << std::endl;
        return;
    }

    radius = newRadius;
}

void Circle::print() const {
    std::cout << getColorCode(color);
    std::cout << "x: " << position.x << "; y: " << position.y << "; radius: " << radius << std::endl;
    std::cout << RESET;
}

Circle* Circle::clone() const {
    return new Circle(*this);
}