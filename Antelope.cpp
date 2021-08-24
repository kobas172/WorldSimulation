#include "Antelope.h"
#include "World.h"

Antelope::Antelope(World *world, Coordinates location) : Animal(world, location, 4, 4, 'A') {

}

Antelope::Antelope(World *world) : Animal(world,  4, 4, 'A') {

}

void Antelope::makeMove() {
    int move = rand()%4;
    Coordinates temp;
    switch (move) {
        case NORTH:
            temp.x = 0;
            temp.y = 2;
            MakeMoveToField(temp);
            break;
        case SOUTH:
            temp.x = 0;
            temp.y = -2;
            MakeMoveToField(temp);
            break;
        case EAST:
            temp.x = 2;
            temp.y = 0;
            MakeMoveToField(temp);
            break;
        case WEST:
            temp.x = -2;
            temp.y = 0;
            MakeMoveToField(temp);
            break;
    }
}

void Antelope::fight(Organism *attacker, Organism *defender) {
    int temp = rand()%2;
    Coordinates coordinates, def;
    def.x = defender->getLocationX();
    def.y = defender->getLocationY();
    coordinates = world->findField(def);
    if (!temp && !world->isOutside(coordinates))
    {
        cout << "Antelope fled away!" << endl;
        move(coordinates);
        world->moveOrganism(attacker, def);
    }
    else
        Animal::fight(attacker, defender);
}

