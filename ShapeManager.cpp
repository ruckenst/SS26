#include "ShapeManager.h"
#include <iostream>

ShapeManager::ShapeManager(int size) {
    maxSize = size;
    currentCount = 0;

    shapes = new Shape*[size];
}

ShapeManager::~ShapeManager() {
    freeShapes();
}

ShapeManager::ShapeManager(const ShapeManager& other) {
    maxSize = other.maxSize;
    currentCount = other.currentCount;

    shapes = new Shape*[maxSize];
    for(int i = 0; i < other.currentCount; i++) {
        shapes[i] = other.shapes[i]->clone();
    }
}

ShapeManager::ShapeManager(ShapeManager&& other) {
    std::cout << "MOVE CONSTRUCTOR!" << std::endl;

    maxSize = other.maxSize;
    currentCount = other.currentCount;
    shapes = other.shapes;

    other.maxSize = 0;
    other.currentCount = 0;
    other.shapes = nullptr;
}

void ShapeManager::addShape(Shape* shape) {
    if(currentCount == maxSize) {
        std::cerr << "ShapeManager is full! Shape was not added.\n";
        delete shape;
        return;
    }

    shapes[currentCount] = shape;
    currentCount++;
}

void ShapeManager::printShapes() const {
    for(int i = 0; i < currentCount; i++) {
        shapes[i]->print();
    }
}

ShapeManager &ShapeManager::operator=(ShapeManager &&other) {
    std::cout << "MOVE ASSIGMENT OPERATOR" << std::endl;

    if(this == &other) {
        std::cerr << "Tried to move itself!" << std::endl;
        return *this;
    }

    freeShapes();

    maxSize = other.maxSize;
    currentCount = other.currentCount;
    shapes = other.shapes;

    other.maxSize = 0;
    other.currentCount = 0;
    other.shapes = nullptr;

    return *this;
}

ShapeManager &ShapeManager::operator=(const ShapeManager &other) {
    if(this == &other) {
        std::cerr << "Tried to copy itself!" << std::endl;
        return *this;
    }

    freeShapes();

    maxSize = other.maxSize;
    currentCount = other.currentCount;

    shapes = new Shape*[maxSize];
    for(int i = 0; i < other.currentCount; i++) {
        shapes[i] = other.shapes[i]->clone();
    }

    return *this;
}

void ShapeManager::freeShapes() {
    for(int i = 0; i < currentCount; i++) {
        delete shapes[i];
        shapes[i] = nullptr;
    }

    delete[] shapes;
    shapes = nullptr;
    currentCount = 0;
}