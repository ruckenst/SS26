#ifndef SS26_SHAPEMANAGER_H
#define SS26_SHAPEMANAGER_H

#include "Shape.h"

class ShapeManager {
public:
    ShapeManager(int length);
    ~ShapeManager();

    // ShapeManager copied(existing);
    ShapeManager(const ShapeManager& other);
    ShapeManager(ShapeManager&& other);

    // ShapeManager copied = existing;
    ShapeManager& operator=(const ShapeManager& other);

    void addShape(const Shape shape);
    void printShapes() const;

private:
    Shape* shapes;
    int maxLength;
    int currentLength;
};


#endif //SS26_SHAPEMANAGER_H
