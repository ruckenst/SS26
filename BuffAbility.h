#ifndef SS26_BUFFABILITY_H
#define SS26_BUFFABILITY_H


#include "Ability.h"

class BuffAbility : public Ability {
public:
    void action() override;
    AbilityType getAbilityType() override;
    void buff();
};


#endif //SS26_BUFFABILITY_H
