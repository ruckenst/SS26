#ifndef SS26_SHAPE_H
#define SS26_SHAPE_H

#include "Coordinate.h"

class Shape {
public:
    Shape();
    Shape(Coordinate coordinate);
    virtual ~Shape() = default;

    virtual void print() const = 0;

    Coordinate getPosition() const;

    void setX(int newX);
    void setY(int newY);
    void setPosition(Coordinate newPosition);

protected:
    Coordinate position;
};

#endif //SS26_SHAPE_H
