#include "Shape.h"
#include "ShapeManager.h"

int main() {
    ShapeManager shapeManager(10);

    shapeManager.addShape(Shape(12, 32));
    shapeManager.addShape(Shape(43, 12));
    shapeManager.addShape(Shape(3, 4));

    shapeManager.printShapes();

    return 0;
}