#ifndef SS26_CIRCLE_H
#define SS26_CIRCLE_H

#include "Shape.h"
#include "Coordinate.h"

class Circle : public Shape {
public:
    Circle(Coordinate position, int radius, Color color);
    ~Circle() override;

    int getRadius() const;
    void setRadius(int newRadius);

    void print() const override;
    Circle* clone() const override;

private:
    int radius;
};


#endif //SS26_CIRCLE_H
