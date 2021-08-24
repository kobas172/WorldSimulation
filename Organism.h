#pragma once
#include "Utilities.h"

class World;

class Organism {
protected:
    int strength;
    int initiative;
    Coordinates location;
    int age;
    char name;
protected:
    World *world;

public:
    Organism(World* world, int strength, int initiative, char name);
    Organism(World* world, Coordinates location, int strength, int initiative, char name);

    virtual void action() = 0;
    virtual void collision(Organism* organism) = 0;
    void draw();

    int getWorldSizeX() const;
    int getWorldSizeY() const;
    int getLocationX() const;
    int getLocationY() const;
    int getStrength() const;
    int getInitiative() const;
    int getAge() const;
    char getName() const;
    World* getWorld() const;

    void setLocationX(int locationX);
    void setLocationY(int locationY);
    void setStrength(int strength);
    void setInitiative(int initiative);
    void setAge(int age);
    void setName(char name);
    void setWorld(World* world);

    void move(Coordinates newLocation);

    ~Organism();
};


