#include "Human.h"
#include "World.h"

Human::Human(World *world, Coordinates location) : Animal(world, location, 5, 4, '#') {

}

Human::Human(World *world) : Animal(world,5, 4, '#') {

}


void Human::makeMove() {
    cout << "Move with arrow keys: " << endl;
    int move = 0;
    move = _getch();
    Coordinates coordinates(0,0);
    if (move == 224)
    {
        move = _getch();
        switch (move)
        {
        case 72:
            coordinates.y = -1;
            Animal::MakeMoveToField(coordinates);
            break;
        case 80:
            coordinates.y = 1;
            Animal::MakeMoveToField(coordinates);
            break;
        case 77:
            coordinates.x = 1;
            Animal::MakeMoveToField(coordinates);
            break;
        case 75:
            coordinates.x = -1;
            Animal::MakeMoveToField(coordinates);
            break;
        }
    }
}

void Human::action() {

    cout << "Your turn! " << endl;
    immortality();
    makeMove();
}

void Human::immortality() {
    if (world->getSuperPower())
    {
        world->setRounds(world->getRounds() + 1);
        if (world->getRounds() == 5)
        {
            world->setSuperPower(false);
            world->setToNext(0);
        }
    }
    else
    {
        world->setToNext(world->getToNext() + 1);
        if (world->getToNext() >= 5)
        {
            cout << "Do you want to turn immortality? y/n" << endl;
            int chr = _getch();
            if (chr == 'y' && world->getToNext() >= 5)
            {
                world->setSuperPower(true);
                world->setRounds(1);
            }
        }
    }
    cout << "Superpower : " << world->getSuperPower() << endl;
}

void Human::collision(Organism *organism) {
    if (!world->getSuperPower() || this->strength > organism->getStrength())
        Animal::collision(organism);
    else
    {
        Coordinates newCoo = world->findField(this->location);
        if (!world->isOutside(newCoo))
        {
            move(newCoo);
        }
    }
}

