#include "Circle.h"
#include <iostream>

Circle::Circle(Coordinate position, int radius) : Shape(position) {
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
    // x: %d; y: %d, radius: %d
    std::cout << "x: " << position.x << "; y: " << position.y << "; radius: " << radius << std::endl;
}