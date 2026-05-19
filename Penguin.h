#ifndef SS26_PENGUIN_H
#define SS26_PENGUIN_H


#include "Animal.h"

class Penguin : public Animal {
public:
    explicit Penguin(std::string name, int i);
    std::string getType() const override;
};

#endif //SS26_PENGUIN_H
