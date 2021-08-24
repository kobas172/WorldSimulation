#include "Organism.h"
#include "World.h"

Organism::Organism(World *world, int strength, int initiative, char name) {
    std::cout << std::endl << std::endl << "Wywoluje konstruktor organizmu" << std::endl << std::endl << std::endl;
    this->world = world;
    this->age = 1;
    this->strength = strength;
    this->initiative = initiative;
    this->name = name;
    this->location.x = rand() % getWorldSizeX();
    this->location.y = rand() % getWorldSizeY();
    while (world->getWorldMap()[this->location.y][this->location.x] != nullptr)
    {
        this->location.x = rand() % getWorldSizeX();
        this->location.y = rand() % getWorldSizeY();
    }
    world->addToMap(this);
    world->addToVector(this);
}

Organism::Organism(World *world, Coordinates location, int strength, int initiative, char name){
    std::cout << std::endl << std::endl << "Wywoluje konstruktor organizmu" << std::endl << std::endl << std::endl;
    this->world = world;
    this->location.x = location.x;
    this->location.y = location.y;
    this->strength = strength;
    this->initiative = initiative;
    this->name = name;
    this->age = 1;
    world->addToMap(this);
    world->addToVector(this);
}

int Organism::getWorldSizeX() const {
    return world->getSizeX();
}

int Organism::getWorldSizeY() const {
    return world->getSizeY();
}

int Organism::getLocationX() const {
    return location.x;
}

int Organism::getLocationY() const {
    return location.y;
}

int Organism::getStrength() const {
    return this->strength;
}

int Organism::getInitiative() const {
    return initiative;
}

int Organism::getAge() const {
    return age;
}

char Organism::getName() const {
    return name;
}

World *Organism::getWorld() const {
    return world;
}

void Organism::setLocationX(int locationX) {
    this->location.x = locationX;
}

void Organism::setLocationY(int locationY) {
    this->location.y = locationY;
}

void Organism::setStrength(int strength) {
    this->strength = strength;
}

void Organism::setInitiative(int initiative) {
    this->initiative = initiative;
}

void Organism::setAge(int age) {
    this->age = age;
}

void Organism::setName(char name) {
    this->name = name;
}

void Organism::setWorld(World *world) {
    this->world = world;
}

void Organism::draw() {
    cout << name;
}

void Organism::move(Coordinates newLocation) {
    world->getWorldMap()[newLocation.y][newLocation.x] = world->getWorldMap()[location.y][location.x];
    world->getWorldMap()[location.y][location.x] = nullptr;
    setLocationX(newLocation.x);
    setLocationY(newLocation.y);
}

Organism::~Organism() {
    world->deleteOrganism(this);
}

