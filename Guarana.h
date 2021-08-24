#pragma once
#include "Plant.h"

class Guarana : public Plant {

public:
    Guarana(World *world, Coordinates location);
    Guarana(World *world);

    void fight(Organism* attacker, Organism* defender) override;


};


