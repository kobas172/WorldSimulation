#pragma once
#include "Organism.h"

class Animal : public Organism {

protected:
    virtual void makeMove();
    void reproduce(Organism* organism);
    bool sameType(Organism* organism);
    virtual void MakeMoveToField(Coordinates field);

public:
    Animal(World* world, Coordinates location, int strength, int initiative, char name);
    Animal(World* world, int strength, int initiative, char name);

    virtual void action() override;
    virtual void collision(Organism* organism) override;
    virtual void fight(Organism* attacker, Organism* defender);
};
