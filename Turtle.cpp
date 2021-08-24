#include "Turtle.h"
#include "World.h"

Turtle::Turtle(World *world, Coordinates location) : Animal(world, location, 2, 1, 'T') {

}

Turtle::Turtle(World *world) : Animal(world, 2, 1, 'T') {

}

void Turtle::makeMove() {
    int willMove = rand()%4;
    if (!willMove)
        Animal::makeMove();
    else
        cout << "Turtle stays on his place!" << endl;
}

void Turtle::fight(Organism *attacker, Organism *defender) {
    if (defender->getName() == 'T' && attacker->getStrength() < 5)
        cout << "Turtle pushed back the attack" << endl;
    else
        Animal::fight(attacker, defender);
}


