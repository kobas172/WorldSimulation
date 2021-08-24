#include "Grass.h"

Grass::Grass(World *world, Coordinates location) : Plant(world, location, 0, 0, 'G') {

}

Grass::Grass(World *world) : Plant(world,  0, 0, 'G') {

}
