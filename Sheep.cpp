#include "Sheep.h"

Sheep::Sheep(World *world, Coordinates location) : Animal(world, location, 4, 4, 'S') {

}

Sheep::Sheep(World *world) : Animal(world, 4, 4, 'S') {

}
