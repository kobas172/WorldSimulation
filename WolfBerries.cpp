#include "WolfBerries.h"
#include "World.h"

WolfBerries::WolfBerries(World *world, Coordinates location)  : Plant(world, location, 99, 0, 'B') {

}

WolfBerries::WolfBerries(World *world) : Plant(world, 99, 0, 'B') {

}

void WolfBerries::fight(Organism *attacker, Organism *defender) {
    if (attacker->getName() == '#' && world->getSuperPower() && attacker->getStrength() < defender->getStrength())
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
        cout << " won " << defender->getName() << endl;
        world->deleteOrganism(attacker);
        world->deleteOrganism(defender);
    }
}



