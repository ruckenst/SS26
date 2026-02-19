#include "Shape.h"
#include <iostream>

Shape::Shape() {
    x = 0;
    y = 0;
}

Shape::Shape(int x, int y) {
    this->x = x;
    this->y = y;
}

int Shape::getX() const {
   return x;
}

int Shape::getY() const {
    return y;
}

void Shape::setX(int newX) {
    if(newX < 0) {
        std::cerr << "X must not be smaller than 0!" << std::endl;
        return;
    }

    x = newX;
}

void Shape::setY(int newY) {
    if(newY < 0) {
        std::cerr << "Y must not be smaller than 0!" << std::endl;
        return;
    }

    y = newY;
}

void Shape::setPosition(int newX, int newY) {
    setX(newX);
    setY(newY);
}

void Shape::print() const {
    // x: %d; y: %d
    std::cout << "x: " << x << "; y: " << y << std::endl;
}
