#include "Shape.h"
#include "ShapeManager.h"
#include <iostream>
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"

int main() {
    int shapeManagerSize;

    std::cout << "Enter the size of the manager: ";
    std::cin >> shapeManagerSize;

    ShapeManager myShapeManager(shapeManagerSize);

    while(true){
        char action;
        do{
            std::cout << "(p)rint - (a)dd - e(x)it" << std::endl;
            std::cin >> action;
        } while(action != 'p' && action != 'a' && action != 'x');

        if(action == 'x') {
            break;
        } else if(action == 'p') {
            myShapeManager.printShapes();
        } else {
            char shapeToCreate;
            do{
                std::cout << "(t)riangle - (r)ectangle - (c)ircle" << std::endl;
                std::cin >> shapeToCreate;
            } while(shapeToCreate != 't' &&
                    shapeToCreate != 'r' &&
                    shapeToCreate != 'c');

            char shapeColorChar;
            do{
                std::cout << "(b)lue - (g)reen - (y)ellow - (r)ed" << std::endl;
                std::cin >> shapeColorChar;
            } while(shapeColorChar != 'b' &&
                    shapeColorChar != 'g' &&
                    shapeColorChar != 'y' &&
                    shapeColorChar != 'r');

            Color shapeColor = charToColor(shapeColorChar);
            Shape* newShape;
            switch(shapeToCreate) {
                case 't':
                    Coordinate cornerA, cornerB, cornerC;
                    std::cout << "Enter your coordinates: ";
                    std::cin >> cornerA.x >> cornerA.y >> cornerB.x >> cornerB.y >> cornerC.x >> cornerC.y;

                    newShape = new Triangle(cornerA, cornerB, cornerC, shapeColor);
                    break;
                case 'r':
                    Coordinate rectPosition, opposite;
                    std::cout << "Enter your coordinates: ";
                    std::cin >> rectPosition.x >> rectPosition.y >> opposite.x >> opposite.y;

                    newShape = new Rectangle(rectPosition, opposite, shapeColor);
                    break;
                default:
                    Coordinate circleCenter;
                    int radius;
                    std::cout << "Enter your coordinate and radius: ";
                    std::cin >> circleCenter.x >> circleCenter.y >> radius;

                    newShape = new Circle(circleCenter, radius, shapeColor);
                    break;
            }

            myShapeManager.addShape(newShape);
        }
    }

    return 0;
}