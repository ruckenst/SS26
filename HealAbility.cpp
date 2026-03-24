#include "HealAbility.h"
#include <iostream>

void HealAbility::action() {
    std::cout << "A refreshing Heal!" << std::endl;
}

AbilityType HealAbility::getAbilityType() {
    return Heal;
}
