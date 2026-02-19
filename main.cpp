#include "Shape.h"

int main() {
    Shape myShape(10, 93);
    Shape mySecondShape(30, 32);
    Shape myThirdShape(32, 3);

    Shape myCopiedShape = myShape;
    myCopiedShape.setPosition(2, 3);

    myShape.print();
    mySecondShape.print();
    myThirdShape.print();
    myCopiedShape.print();

    return 0;
}