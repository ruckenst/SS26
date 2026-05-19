#include "Elephant.h"

Elephant::Elephant(std::string name) : Animal(name) {

}

std::string Elephant::getType() const {
    return "Elephant";
}
