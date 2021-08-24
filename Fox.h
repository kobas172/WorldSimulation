#pragma once
#include "Animal.h"

class Fox : public Animal {

public:
    Fox(World *world, Coordinates location);
    Fox(World *world);

    void MakeMoveToField(Coordinates field) override;
};
