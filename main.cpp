#include "Shape.h"
#include "ShapeManager.h"
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
#include <iostream>

int main() {
    Shape *shapes[5] = {nullptr};

    shapes[0] = new Circle({2, 6}, 10);
    shapes[1] = new Triangle({5, 2}, {1, 5}, {6, 4});
    shapes[2] = new Rectangle({3, 5}, {1, 9});

    for (int i = 0; i < 5; i++) {
        if (shapes[i] == nullptr) continue;

        shapes[i]->print();
    }

    for (int i = 0; i < 5; i++) {
        if (shapes[i] == nullptr) continue;

        delete shapes[i];
        shapes[i] = nullptr;
    }

    return 0;
}
