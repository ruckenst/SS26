#include "Shape.h"
#include "ShapeManager.h"
#include <iostream>

ShapeManager someFunction(int size) {
    ShapeManager myTempShapeManager(size);
    myTempShapeManager.addShape(Shape(1, 1));

    return myTempShapeManager;
}

int main() {
    ShapeManager shapeManager(10);

    shapeManager.addShape(Shape(12, 32));
    shapeManager.addShape(Shape(43, 12));
    shapeManager.addShape(Shape(3, 4));

    std::cout << std::endl;
    shapeManager.printShapes();

    ShapeManager copiedShapeManager(shapeManager);
    //ShapeManager copiedShapeManager = shapeManager;

    std::cout << std::endl;
    copiedShapeManager.printShapes();

    shapeManager.addShape(Shape(84, 23));

    std::cout << std::endl;
    shapeManager.printShapes();

    std::cout << std::endl;
    copiedShapeManager.printShapes();

    //ShapeManager movedShapeManger = std::move(copiedShapeManager); // MOVE CONSTRUCTOR
    copiedShapeManager = std::move(copiedShapeManager); // MOVE ASSIGNMENT OPERATOR

    /*
    std::cout << std::endl;
    movedShapeManger.printShapes();
    */

    std::cout << "HERE COMES COPIED: " << std::endl;
    copiedShapeManager.printShapes();

    return 0;
}