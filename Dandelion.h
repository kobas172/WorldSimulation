#pragma once
#include "Plant.h"

class Dandelion : public Plant {

public:
    Dandelion(World *world, Coordinates location);
    Dandelion(World *world);

    void action() override;
};
