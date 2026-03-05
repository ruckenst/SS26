#ifndef SS26_SHAPE_H
#define SS26_SHAPE_H

#include <string>
#include "Coordinate.h"
#include "Colors.h"

class Shape {
public:
    Shape();
    Shape(Coordinate position, Color color);
    virtual ~Shape() = default;

    virtual void print() const = 0;
    virtual Shape* clone() const = 0;

    Coordinate getPosition() const;

    void setX(int newX);
    void setY(int newY);
    void setPosition(Coordinate position);

protected:
    Coordinate position;
    Color color;
};

#endif //SS26_SHAPE_H