#ifndef SS26_TEST_H
#define SS26_TEST_H

#include <memory>

class Test;

class TestB {
public:
    TestB();
    ~TestB();

    std::shared_ptr<Test> ref;
};

class Test {
public:
    Test();
    ~Test();

    std::shared_ptr<TestB> ref;
};

#endif //SS26_TEST_H
