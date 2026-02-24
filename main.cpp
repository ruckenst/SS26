#include "Shape.h"
#include "ShapeManager.h"
#include <iostream>

int main() {
    ShapeManager shapeManager(10);

    shapeManager.addShape(Shape(4, 2));
    shapeManager.addShape(Shape(6, 2));
    shapeManager.addShape(Shape(32, 4));

    shapeManager.printShapes();

    ShapeManager copy(shapeManager);
    copy.addShape(Shape(4, 5));

    std::cout << std::endl;
    copy.printShapes();

    std::cout << std::endl;
    shapeManager.printShapes();

    copy = shapeManager;
    std::cout << std::endl;
    copy.printShapes();

    ShapeManager otherCopy = copy;
    std::cout << std::endl;
    otherCopy.printShapes();

    return 0;
}
