#ifndef SS26_SHAPEMANAGER_H
#define SS26_SHAPEMANAGER_H

#include "Shape.h"

class ShapeManager {
public:
    ShapeManager(int size);
    ~ShapeManager();

    ShapeManager(const ShapeManager& other);
    ShapeManager(ShapeManager&& other);

    ShapeManager& operator=(const ShapeManager& other);
    ShapeManager& operator=(ShapeManager&& other);

    void addShape(Shape* shape);
    void printShapes() const;

private:
    Shape** shapes;
    int maxSize;
    int currentCount;

    void freeShapes();
};


#endif //SS26_SHAPEMANAGER_H
