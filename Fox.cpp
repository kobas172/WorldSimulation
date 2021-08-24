#include "Fox.h"
#include "World.h"

Fox::Fox(World *world, Coordinates location) : Animal(world, location, 3, 7, 'F')  {

}

Fox::Fox(World *world) : Animal(world, 3, 7, 'F') {

}

void Fox::MakeMoveToField(Coordinates field) {
    Coordinates newLocation;
    newLocation.x = getLocationX() + field.x;
    newLocation.y = getLocationY() + field.y;
    Organism* temp = nullptr;
    if (!world->isOutside(newLocation))
    {
        temp = world->detectedCollision(newLocation);
    }
    if (world->isOutside(newLocation) || world->isThereSomeone(newLocation, this))
    {
        Coordinates check = world->findField(this->location);
        if (!world->isOutside(check))
            makeMove();
    }
    else if (temp != nullptr)
    {
        temp->collision(this);
    }
    else
    {
        cout << this->getName() << " moved to ( " << newLocation.x << " , " << newLocation.y << " )\n";
        move(newLocation);
    }
}

