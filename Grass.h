#pragma once
#include "Plant.h"

class Grass : public Plant {

public:
    Grass(World *world, Coordinates location);
    Grass(World *world);

};