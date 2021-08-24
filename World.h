#pragma once
#include "Organism.h"
#include "Utilities.h"
#include "Wolf.h"
#include "Sheep.h"
#include "Fox.h"
#include "Turtle.h"
#include "Antelope.h"
#include "Grass.h"
#include "Dandelion.h"
#include "Guarana.h"
#include "WolfBerries.h"
#include "Hogweed.h"
#include "Human.h"


class World {
    Coordinates size;
    int round;
    bool isGameOn;
    Organism*** worldMap;
    vector<Organism*> organismVector;
    bool superPower;
    int rounds;
    int toNext;

public:
    World();
    World(Coordinates size);

    void drawWorld();
    void generateWorld();
    void clearMap(Coordinates size);
    void addToMap(Organism* organism);
    void addToVector(Organism* organism);
    bool isOutside(Coordinates coordinates);
    Organism* detectedCollision(Coordinates coordinates);
    Coordinates findField(Coordinates coordinates);
    bool isThereSomeone(Coordinates coordinates, Organism* organism);
    void newOrganism(Organism* organism, Coordinates coordinates);
    void makeMove();
    void moveOrganism(Organism* organism, Coordinates coordinates);
    void deleteOrganism(Organism* organism);
    void updateVector();
    void sortVector();
    void setIsGameOn(bool isGameOn);
    bool checkVector();
    void debugVector();

    void setSuperPower(bool superPower);
    void setRounds(int rounds);
    void setToNext(int toNext);
    void setSizeX(int sizeX);
    void setSizeY(int sizeY);
    
    bool getSuperPower() const;
    int getRounds() const;
    int getToNext() const;
    int getSizeX() const;
    int getSizeY() const;
    Organism*** getWorldMap() const;
    Organism* getOrganism(Coordinates coordinates) const;

    void saveToFile();
    void loadFromFile();

    bool isStillGameOn() const;

    ~World();
};
