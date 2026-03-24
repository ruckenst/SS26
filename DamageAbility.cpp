#include "DamageAbility.h"
#include <iostream>

void DamageAbility::action() {
    std::cout << "A powerful Damage!" << std::endl;
}

AbilityType DamageAbility::getAbilityType() {
    return Damage;
}
