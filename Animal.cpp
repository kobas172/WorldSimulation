#include "Animal.h"
#include "World.h"

Animal::Animal(World *world, Coordinates location, int strength, int initiative, char name) : Organism(world, location, strength, initiative, name) {
    std::cout << std::endl << std::endl << "Wywoluje konstruktor animala" << std::endl << std::endl << std::endl;
}

Animal::Animal(World *world, int strength, int initiative, char name) : Organism(world, strength, initiative, name) {
    std::cout << std::endl << std::endl << "Wywoluje konstruktor animala" << std::endl << std::endl << std::endl;
}

void Animal::action() {
    makeMove();
}

void Animal::collision(Organism *organism) {
    if (sameType(organism))
        reproduce(organism);
    else
    {
        fight(organism, this);
    }
}

bool Animal::sameType(Organism* organism) {
    if(this->getName() == organism->getName())
        return true;
    return false;
}

void Animal::reproduce(Organism* organism) {
    Coordinates freePlace = world->findField(this->location);
    if (!world->isOutside(freePlace))
        world->newOrganism(organism, freePlace);
    else
        cout << "There is no space to reproduce!" << endl;
}

void Animal::MakeMoveToField(Coordinates field) {
    Coordinates newLocation;
    newLocation.x = getLocationX() + field.x;
    newLocation.y = getLocationY() + field.y;
    Organism* temp = nullptr;
    if (!world->isOutside(newLocation))
    {
        temp = world->detectedCollision(newLocation);
    }
    if (world->isOutside(newLocation))
    {
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

void Animal::makeMove() {
    int move = rand()%4;
    Coordinates temp;
    switch (move) {
        case NORTH:
            temp.x = 0;
            temp.y = 1;
            MakeMoveToField(temp);
            break;
        case SOUTH:
            temp.x = 0;
            temp.y = -1;
            MakeMoveToField(temp);
            break;
        case EAST:
            temp.x = 1;
            temp.y = 0;
            MakeMoveToField(temp);
            break;
        case WEST:
            temp.x = -1;
            temp.y = 0;
            MakeMoveToField(temp);
            break;
    }
}

void Animal::fight(Organism *attacker, Organism *defender)
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

