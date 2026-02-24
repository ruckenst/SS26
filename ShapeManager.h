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

    //ShapeManager(Shape* shapes);

    void addShape(Shape shape);
    //void deleteShape(int index);
    void printShapes() const;

private:
    Shape* shapes;
    int maxSize;
    int currentCount;
};


#endif //SS26_SHAPEMANAGER_H
