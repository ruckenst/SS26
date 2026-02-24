#include "ShapeManager.h"

ShapeManager::ShapeManager(int size) {
    maxSize = size;
    currentCount = 0;

    shapes = new Shape[size];
}

ShapeManager::~ShapeManager() {
    delete[] shapes;
}

void ShapeManager::addShape(Shape shape) {
    if(currentCount == maxSize) {
        // Array full
        return;
    }

    shapes[currentCount] = shape;
    currentCount++;
}

void ShapeManager::printShapes() const {
    for(int i = 0; i < currentCount; i++) {
        shapes[i].print();
    }
}