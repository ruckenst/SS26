#include "Ability.h"
#include "BuffAbility.h"
#include "DamageAbility.h"
#include "HealAbility.h"

#include <iostream>

int main() {
    int a = 10;
    int b = 3;

    std::cout << (double)a / b << std::endl;

    // (...) - C Syntax - VERMEIDEN
    // dynamic_cast
    // static_cast
    // reinterpret_cast - VERMEIDEN

    Ability* abilities[3];

    abilities[0] = new BuffAbility();
    abilities[1] = new DamageAbility();
    abilities[2] = new HealAbility();

    for(auto& ability : abilities) {
        ability->action();
    }

    for(auto& ability : abilities) {
        delete ability;
        ability = nullptr;
    }

    return 0;
}