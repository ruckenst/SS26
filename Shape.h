#ifndef SS26_SHAPE_H
#define SS26_SHAPE_H

#include <string>
#include "Coordinate.h"

class Shape {
public:
    Shape();
    Shape(Coordinate position);
    virtual ~Shape() = default;

    virtual void print() const = 0;

    Coordinate getPosition() const;
    int getY() const;

    void setX(int newX);
    void setY(int newY);
    void setPosition(Coordinate position);

protected:
    Coordinate position;
};

#endif //SS26_SHAPE_H