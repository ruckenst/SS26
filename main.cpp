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

    ShapeManager movedObject = std::move(otherCopy);

    std::cout << std::endl;
    movedObject.printShapes();

    std::cout << "HERE IS OTHER COPY: " <<  std::endl;
    otherCopy.printShapes();

    movedObject = std::move(movedObject);

    std::cout << "HERE IS MOVED OBJECT: " <<  std::endl;
    std::cout << std::endl;
    movedObject.printShapes();

    return 0;
}
