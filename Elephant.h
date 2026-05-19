#ifndef SS26_ELEPHANT_H
#define SS26_ELEPHANT_H


#include "Animal.h"

class Elephant : public Animal {
public:
    explicit Elephant(std::string name);
    std::string getType() const override;
};


#endif //SS26_ELEPHANT_H
