#ifndef SS26_LION_H
#define SS26_LION_H


#include "Animal.h"

class Lion : public Animal {
public:
    explicit Lion(std::string name);
    std::string getType() const override;
};


#endif //SS26_LION_H
