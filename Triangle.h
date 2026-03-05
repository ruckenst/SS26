#ifndef SS26_TRIANGLE_H
#define SS26_TRIANGLE_H

#include "Shape.h"
#include "Coordinate.h"

class Triangle : public Shape {
public:
    Triangle(Coordinate cornerAPosition,
             Coordinate cornerBPosition,
             Coordinate cornerCPosition,
             Color color);

    void print() const override;
    Triangle* clone() const override;

private:
    Coordinate cornerBPosition;
    Coordinate cornerCPosition;
};


#endif //SS26_TRIANGLE_H
