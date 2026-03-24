#ifndef SS26_DAMAGEABILITY_H
#define SS26_DAMAGEABILITY_H


#include "Ability.h"

class DamageAbility : public Ability {
public:
    void action() override;
    AbilityType getAbilityType() override;


};


#endif //SS26_DAMAGEABILITY_H
