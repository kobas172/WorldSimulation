#pragma once
#include "Animal.h"

class Human : public Animal {
    void immortality();
    void makeMove() override;

public:
    Human(World *world, Coordinates location);
    Human(World *world);
    void action() override;
    void collision(Organism* organism) override;


};

