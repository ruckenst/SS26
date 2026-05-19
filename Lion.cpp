#include "Lion.h"

Lion::Lion(std::string name) : Animal(name) {

}

std::string Lion::getType() const {
    return "Lion";
}