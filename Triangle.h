#ifndef SS26_TRIANGLE_H
#define SS26_TRIANGLE_H

#include "Shape.h"

class Triangle : public Shape {
public:
    Triangle(Coordinate positionA, Coordinate positionB, Coordinate positionC);

    void print() const override;

private:
    Coordinate positionB;
    Coordinate positionC;
};

#endif //SS26_TRIANGLE_H
