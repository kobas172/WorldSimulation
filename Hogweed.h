#pragma once
#include "Plant.h"

class Hogweed : public Plant{

    bool isAnimal(Coordinates coordinates);
    void killAnimal(Coordinates coordinates);
public:
    Hogweed(World *world, Coordinates location);
    Hogweed(World *world);
    void action() override;

};
