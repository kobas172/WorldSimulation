#pragma once
#include "Plant.h"

class WolfBerries : public Plant {

public:
    WolfBerries(World *world, Coordinates location);
    WolfBerries(World *world);
    void fight(Organism* attacker, Organism* defender) override;

};

