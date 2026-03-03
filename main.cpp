#include "Shape.h"
#include "ShapeManager.h"
#include <iostream>
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"

int main() {
    Shape *myShapes[5] = {nullptr};

    myShapes[0] = new Circle({2, 4}, 12);
    myShapes[1] = new Triangle({2, 4}, {8, 4}, {9, 5});
    myShapes[2] = new Rectangle({4, 2}, {9, 5});

    for (int i = 0; i < 5; i++) {
        if (myShapes[i] == nullptr) continue;

        myShapes[i]->print();
    }

    for (int i = 0; i < 5; i++) {
        if (myShapes[i] == nullptr) continue;

        delete myShapes[i];
    }

    return 0;
}