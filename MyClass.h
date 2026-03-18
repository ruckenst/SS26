#ifndef SS26_MYCLASS_H
#define SS26_MYCLASS_H


class MyClass {
public:
    MyClass(int value);
    void print() const;

    static int getNumberOfReferences();

private:
    int value;
    static int numberOfReferences;
};


#endif //SS26_MYCLASS_H
