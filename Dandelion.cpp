#include "Dandelion.h"

Dandelion::Dandelion(World *world, Coordinates location)  : Plant(world, location, 0, 0, 'D') {

}

Dandelion::Dandelion(World *world) : Plant(world, 0, 0, 'D') {

}

void Dandelion::action() {
    for (int i = 0; i < 3; i++)
        Plant::action();
}

