#include "Plant.h"
#include "World.h"

Plant::Plant(World *world, Coordinates location, int strength, int initiative, char name) : Organism(world, location, strength, initiative, name) {

}

Plant::Plant(World *world, int strength, int initiative, char name) : Organism(world, strength, initiative, name) {

}

void Plant::action() {
    int probability = rand()%100;
    if (probability > 90)
    {
        Coordinates freePlace = world->findField(location);
        if (!world->isOutside(freePlace))
            world->newOrganism(this, freePlace);
        else
            cout << "There is no place to reproduce!" << endl;
    }
}

void Plant::collision(Organism *organism) {
    fight(organism, this);
}

void Plant::fight(Organism *attacker, Organism *defender)
{
    if (attacker->getName() == '#'  && world->getSuperPower() && attacker->getStrength() < defender->getStrength())
    {
        cout << "You escaped to safe square!" << endl;
        Coordinates newCoo = world->findField(this->location);
        if (!world->isOutside(newCoo))
        {
            world->moveOrganism(attacker, newCoo);
        }
    }
    else
    {
        cout << "Fight between " << attacker->getName() << " and " << defender->getName();
        if (attacker->getStrength() >= defender->getStrength())
        {
            Coordinates newLocation(defender->getLocationY(), defender->getLocationX());
            world->deleteOrganism(defender);
            world->moveOrganism(attacker ,newLocation);
            cout << " won " << attacker->getName() << endl;
        }
        else
        {
            cout << " won " << defender->getName() << endl;
            world->deleteOrganism(attacker);
        }
    }
}
