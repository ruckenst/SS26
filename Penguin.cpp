#include "Penguin.h"

Penguin::Penguin(std::string name) : Animal(name) {

}

std::string Penguin::getType() const {
    return "Penguin";
}