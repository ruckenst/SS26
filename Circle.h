#ifndef SS26_CIRCLE_H
#define SS26_CIRCLE_H

#include "Shape.h"
#include "Coordinate.h"

class Circle : public Shape {
public:
    Circle(Coordinate position, int radius);
    ~Circle() override;

    int getRadius() const;
    void setRadius(int newRadius);

    void print() const override;

private:
    int radius;
};

#endif //SS26_CIRCLE_H
