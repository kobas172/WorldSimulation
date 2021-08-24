#pragma once
#include "Animal.h"

class Antelope : public Animal {

public:
    Antelope(World *world, Coordinates location);
    Antelope(World *world);

    void makeMove() final;
    void fight(Organism* attacker, Organism* defender) override;
};
