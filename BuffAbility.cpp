#include "BuffAbility.h"
#include <iostream>

void BuffAbility::action() {
    this->buff();
    std::cout << "An enhancing Buff!" << std::endl;
}

void BuffAbility::buff() {
    std::cout << "YEAAAH BUFFS!!" << std::endl;
}

AbilityType BuffAbility::getAbilityType() {
    return Buff;
}
