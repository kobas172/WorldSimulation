#pragma once
#include "Animal.h"

class Turtle : public Animal {

public:
    Turtle(World *world, Coordinates location);
    Turtle(World *world);

    void makeMove() override;
    void fight(Organism* attacker, Organism* defender) override;

};
