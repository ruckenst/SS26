#include "ShapeManager.h"
#include <iostream>

ShapeManager::ShapeManager(int length) {
    maxLength = length;
    currentLength = 0;

    shapes = new Shape[length];
}

ShapeManager::~ShapeManager() {
    delete[] shapes;
}

ShapeManager::ShapeManager(const ShapeManager &other) {
    std::cout << "COPY CONSTRUCTOR" << std::endl;
    maxLength = other.maxLength;
    currentLength = other.currentLength;

    shapes = new Shape[maxLength];
    for(int i = 0; i < other.currentLength; i++) {
        shapes[i] = other.shapes[i];
    }
}

ShapeManager::ShapeManager(ShapeManager &&other) {
    std::cout << "MOVE CONSTRUCTOR" << std::endl;
    maxLength = other.maxLength;
    currentLength = other.currentLength;
    shapes = other.shapes;

    other.maxLength = 0;
    other.currentLength = 0;
    other.shapes = nullptr;
}

ShapeManager& ShapeManager::operator=(ShapeManager &&other) {
    std::cout << "MOVE ASSIGNMENT OPERATOR" << std::endl;

    if(this == &other) {
        std::cout << "Tried to move itself!" << std::endl;
        return *this;
    }

    delete[] shapes;

    maxLength = other.maxLength;
    currentLength = other.currentLength;
    shapes = other.shapes;

    other.maxLength = 0;
    other.currentLength = 0;
    other.shapes = nullptr;

    return *this;
}

ShapeManager& ShapeManager::operator=(const ShapeManager &other) {
    std::cout << "COPY ASSIGNMENT OPERATOR" << std::endl;
    if(this == &other) {
        return *this;
    }

    delete[] shapes;
    currentLength = other.currentLength;
    maxLength = other.maxLength;

    shapes = new Shape[maxLength];
    for(int i = 0; i < other.currentLength; i++) {
        shapes[i] = other.shapes[i];
    }

    return *this;
}

void ShapeManager::addShape(const Shape shape) {
    if(currentLength >= maxLength) {
        // Already full
        return;
    }

    shapes[currentLength] = shape;
    currentLength++;
}

void ShapeManager::printShapes() const {
    for(int i = 0; i < currentLength; i++) {
        shapes[i].print();
    }
}