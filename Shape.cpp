#include "Shape.h"
#include <iostream>

Shape::Shape() : Shape({0, 0}, Red) {
}

Shape::Shape(Coordinate position, Color color) {
    setPosition(position);
    this->color = color;
}

Coordinate Shape::getPosition() const {
    return position;
}

void Shape::setX(int newX) {
    if(newX < 0) {
        std::cerr << "X must not be smaller than 0!" << std::endl;
        return;
    }

    position.x = newX;
}

void Shape::setY(int newY) {
    if(newY < 0) {
        std::cerr << "Y must not be smaller than 0!" << std::endl;
        return;
    }

    position.y = newY;
}

void Shape::setPosition(Coordinate position) {
    setX(position.x);
    setY(position.y);
}