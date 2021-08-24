#include "Guarana.h"

Guarana::Guarana(World *world, Coordinates location) : Plant(world, location, 0, 0, 'U') {

}

Guarana::Guarana(World *world) : Plant(world, 0, 0, 'U') {

}

void Guarana::fight(Organism *attacker, Organism *defender) {
    attacker->setStrength(attacker->getStrength() + 3);
    Plant::fight(attacker, defender);
}

