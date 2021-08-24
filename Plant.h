#pragma once
#include "Organism.h"

class Plant : public Organism {

public:
    Plant(World* world, Coordinates location, int strength, int initiative, char name);
    Plant(World* world, int strength, int initiative, char name);

    void action() override;
    void collision(Organism* organism) override;
    virtual void fight(Organism* attacker, Organism* defender);
};
