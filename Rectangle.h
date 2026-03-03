#ifndef SS26_RECTANGLE_H
#define SS26_RECTANGLE_H

#include "Shape.h"
#include "Coordinate.h"

class Rectangle : public Shape {
public:
    Rectangle(Coordinate position, Coordinate oppositeSidePosition);

    void print() const override;

private:
    Coordinate oppositeSidePosition;
};


#endif //SS26_RECTANGLE_H
