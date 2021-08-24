#pragma once
#include "Animal.h"

class Sheep : public Animal {

public:
    Sheep(World *world, Coordinates location);
    Sheep(World *world);
};
