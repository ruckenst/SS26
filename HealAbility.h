#ifndef SS26_HEALABILITY_H
#define SS26_HEALABILITY_H


#include "Ability.h"

class HealAbility : public Ability {
public:
    void action() override;
    AbilityType getAbilityType() override;
};


#endif //SS26_HEALABILITY_H
