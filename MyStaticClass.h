#ifndef SS26_MYSTATICCLASS_H
#define SS26_MYSTATICCLASS_H

#include <iostream>

class MyStaticClass {
public:
    MyStaticClass(int id);

    void print() const;

    static int getObjectCount();

private:
    int id;
    static int objectCount;
};


#endif //SS26_MYSTATICCLASS_H
