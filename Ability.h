#ifndef SS26_ABILITY_H
#define SS26_ABILITY_H

enum AbilityType {
    Buff,
    Damage,
    Heal
};

class Ability {
public:
    virtual ~Ability() = default;
    virtual void action() = 0;
    virtual AbilityType getAbilityType() = 0;
};

#endif //SS26_ABILITY_H
