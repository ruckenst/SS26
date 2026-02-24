#ifndef SS26_SHAPE_H
#define SS26_SHAPE_H

#include <string>

class Shape {
public:
    Shape();
    Shape(int x, int y);

    void print() const;

    int getX() const;
    int getY() const;

    void setX(int newX);
    void setY(int newY);
    void setPosition(int newX, int newY);

private:
    int x;
    int y;
};

#endif //SS26_SHAPE_H