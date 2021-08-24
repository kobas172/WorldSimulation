#pragma once
#include "Animal.h"

class Wolf : public Animal {

public:
    Wolf(World *world, Coordinates location);
    Wolf(World *world);

};
