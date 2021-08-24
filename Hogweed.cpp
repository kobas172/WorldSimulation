#include "Hogweed.h"
#include "World.h"

Hogweed::Hogweed(World *world, Coordinates location) : Plant(world, location, 10, 0, 'H') {

}

Hogweed::Hogweed(World *world) : Plant(world,  10, 0, 'H') {

}

void Hogweed::action() {
    Coordinates toCheck;
    toCheck.y = this->getLocationY();
    toCheck.x = this->getLocationX() + 1;
    killAnimal(toCheck);
    toCheck.x = this->getLocationX() - 1;
    killAnimal(toCheck);
    toCheck.x = this->getLocationX();
    toCheck.y = this->getLocationY() + 1;
    killAnimal(toCheck);
    toCheck.y = this->getLocationY() - 1;
    killAnimal(toCheck);
    Plant::action();
}

bool Hogweed::isAnimal(Coordinates coordinates) {
    if (world->getWorldMap()[coordinates.y][coordinates.x]->getName() == 'A' ||
            world->getWorldMap()[coordinates.y][coordinates.x]->getName() == 'W' ||
            world->getWorldMap()[coordinates.y][coordinates.x]->getName() == 'S' ||
            world->getWorldMap()[coordinates.y][coordinates.x]->getName() == 'F' ||
            world->getWorldMap()[coordinates.y][coordinates.x]->getName() == 'T' ||
            world->getWorldMap()[coordinates.y][coordinates.x]->getName() == '#')
        return true;
    return false;
}

void Hogweed::killAnimal(Coordinates coordinates) {
    if (!world->isOutside(coordinates) && world->getWorldMap()[coordinates.y][coordinates.x] != nullptr)
    {
        if (isAnimal(coordinates) && !(world->getWorldMap()[coordinates.y][coordinates.x]->getName() == '#' && world->getSuperPower()))
        {
            cout << "Hogweed kills " << world->getWorldMap()[coordinates.y][coordinates.x]->getName() << endl;
            world->deleteOrganism(world->getWorldMap()[coordinates.y][coordinates.x]);
        }
    }
}

