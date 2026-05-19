#ifndef SS26_ANIMAL_H
#define SS26_ANIMAL_H

#include <string>

class Animal {
public:
    explicit Animal(std::string name);
    virtual ~Animal() = default;

    virtual std::string getType() const = 0;
    void printStats() const;

private:
    std::string name;
};


#endif //SS26_ANIMAL_H
