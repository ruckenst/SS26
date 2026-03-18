#include "FixedNumberGenerator.h"

FixedNumberGenerator::FixedNumberGenerator(int number) {
    this->number = number;
}

int FixedNumberGenerator::getRandomNumber(int min, int max) {
    return number > max ? max : number;
}