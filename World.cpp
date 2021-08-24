#include "World.h"

World::World() {
    srand(time(NULL));
    this->size.x = 0;
    this->size.y = 0;
    this->round = 1;
    this->isGameOn = true;
    this->worldMap = nullptr;
    this->superPower = false;
    this->rounds = 0;
    this->toNext = 5;
}

World::World(Coordinates size) {
    srand(time(NULL));
    this->size.x = size.x;
    this->size.y = size.y;
    this->round = 1;
    this->isGameOn = true;
    this->worldMap = new Organism**[size.y];
    this->superPower = false;
    this->rounds = 0;
    this->toNext = 5;
    for (int i = 0; i < size.y; i++)
        worldMap[i] = new Organism*[size.x];
    clearMap(size);
    Wolf *wolf1 = new Wolf(this);
//    Wolf *wolf2 = new Wolf(this);
//    Sheep *sheep1 = new Sheep(this);
//    Sheep *sheep2 = new Sheep(this);
//    Fox *fox1 = new Fox(this);
//    Fox *fox2 = new Fox(this);
//    Antelope *antelope1 = new Antelope(this);
//    Antelope *antelope2 = new Antelope(this);
//    Turtle *turtle1 = new Turtle(this);
//    Turtle *turtle2 = new Turtle(this);
//    Human *human = new Human(this);
//    Grass *grass = new Grass(this);
//    Dandelion *dandelion = new Dandelion(this);
//    Guarana *guarana = new Guarana(this);
//    Hogweed *hogweed = new Hogweed(this);
//    WolfBerries *wolfBerries = new WolfBerries(this);
}

void World::drawWorld() {
    for (int i = -1; i < size.y+1; i++)
    {
        for (int j = -1; j < size.x+1; j++)
        {
            if (i == -1 && j == -1)
                cout << "+";
            else if (i == size.y && j == size.x)
                cout << " +";
            else if (i == -1 && j == size.x)
                cout << " +";
            else if (i == size.y && j == -1)
                cout << "+";
            else if (i == -1 || i == size.y)
                cout << " -";
            else if (j == -1 || j == size.x)
                cout << "| ";
            else if (worldMap[i][j] == nullptr)
            {
                cout << ". ";
            }
            else
            {
                cout << worldMap[i][j]->getName() << " ";
            }
        }
        cout << endl;
    }
}

void World::clearMap(Coordinates size) {
    for (int i = 0; i < size.y; i++)
        for (int j = 0; j < size.x; j++)
            this->worldMap[i][j] = nullptr;
}

int World::getSizeX() const {
    return this->size.x;
}

int World::getSizeY() const {
    return this->size.y;
}

void World::addToMap(Organism *organism) {
    this->worldMap[organism->getLocationY()][organism->getLocationX()] = organism;
}

void World::addToVector(Organism *organism) {
    organismVector.push_back(organism);
}

bool World::isOutside(Coordinates coordinates) {
    if (coordinates.x >= getSizeX() || coordinates.x < 0 || coordinates.y >= getSizeY() || coordinates.y < 0)
        return true;
    return false;
}

Organism ***World::getWorldMap() const {
    return worldMap;
}

void World::makeMove() {
    cout << "Piotr Gorkowski, gr 2, 184515" << endl;
    updateVector();
    sortVector();
    int temp = organismVector.size();
    cout << "Round number: " << round << endl;
    drawWorld();
    round++;
    for (int i = 0; i < temp; i++)
        if (organismVector[i] != nullptr)
        {
            organismVector[i]->setAge(organismVector[i]->getAge() + 1);
            organismVector[i]->action();
//            Sleep(1000);
//            system("CLS");
//            drawWorld();
        }
    updateVector();
    sortVector();
    if (!checkVector())
        setIsGameOn(false);
    cout << "Do you want to save? y/n" << endl;
    int opt = _getch();
    if (opt == 'y')
    {
        saveToFile();
        cout << "Saved succesfully!" << endl;
        _getch();
        exit(1);
    }
}

Organism * World::detectedCollision(Coordinates coordinates) {
    if(worldMap[coordinates.y][coordinates.x] != nullptr)
        return worldMap[coordinates.y][coordinates.x];
    return nullptr;
}

Coordinates World::findField(Coordinates coordinates) {
    Coordinates temp = coordinates;
    temp.x++;
    if (!isOutside(temp) && worldMap[temp.y][temp.x] == nullptr)
        return temp;
    temp.x-=2;
    if (!isOutside(temp) && worldMap[temp.y][temp.x] == nullptr)
        return temp;
    temp.x++;
    temp.y++;
    if (!isOutside(temp) && worldMap[temp.y][temp.x] == nullptr)
        return temp;
    temp.y-=2;
    if (!isOutside(temp) && worldMap[temp.y][temp.x] == nullptr)
        return temp;
    temp.x = -1;
    temp.y = -1;
    return temp;
}

bool World::isThereSomeone(Coordinates coordinates, Organism* organism) {
    Organism* temp;
    if (worldMap[coordinates.y][coordinates.x] == nullptr)
        return false;
    else
    {
        temp = worldMap[coordinates.y][coordinates.x];
        if (temp->getName() == organism->getName())
            return false;
        else if (temp->getStrength() > organism->getStrength())
            return true;
        return false;
    }
}

void World::newOrganism(Organism *organism, Coordinates coordinates)
{
    if (organism->getName() == 'W')
    {
        cout << "Wolf reproduces" << endl;
        Wolf* newWolf = new Wolf(this, coordinates);
    }
    else if (organism->getName() == 'S')
    {
        cout << "Sheep reproduces" << endl;
        Sheep* newSheep = new Sheep(this, coordinates);
    }
    else if (organism->getName() == 'F')
    {
        cout << "Fox reproduces" << endl;
        Fox* newFox = new Fox(this, coordinates);
    }
    else if (organism->getName() == 'T')
    {
        cout << "Turtle reproduces" << endl;
        Turtle* newTurtle = new Turtle(this, coordinates);
    }
    else if (organism->getName() == 'A')
    {
        cout << "Turtle reproduces" << endl;
        Antelope* newAntelope = new Antelope(this, coordinates);
    }
    else if (organism->getName() == 'G')
    {
        cout << "Grass reproduces" << endl;
        Grass* newGrass = new Grass(this, coordinates);
    }
    else if (organism->getName() == 'D')
    {
        cout << "Dandelion reproduces" << endl;
        Dandelion* newDandelion = new Dandelion(this, coordinates);
    }
    else if (organism->getName() == 'U')
    {
        cout << "Guarana reproduces" << endl;
        Guarana* newGuarana = new Guarana(this, coordinates);
    }
    else if (organism->getName() == 'B')
    {
        cout << "Wolf berries reproduces" << endl;
        WolfBerries* newWolfBerries = new WolfBerries(this, coordinates);
    }
    else if (organism->getName() == 'H')
    {
        cout << "Hogweed reproduces" << endl;
        Hogweed* newHogweed = new Hogweed(this, coordinates);
    }
}

Organism *World::getOrganism(Coordinates coordinates) const {
    return worldMap[coordinates.y][coordinates.x];
}

void World::deleteOrganism(Organism *organism) {
    for (int i = 0; i < organismVector.size(); i++)
    {
        if (organismVector[i] == organism)
        {
            worldMap[organism->getLocationY()][organism->getLocationX()] = nullptr;
            delete worldMap[organism->getLocationY()][organism->getLocationX()];
            organismVector[i] = nullptr;
            break;
        }
    }
}

void World::updateVector() {
    for (int i = 0; i < organismVector.size(); i++)
    {
        if (organismVector[i] == nullptr)
        {
            organismVector.erase(std::remove(organismVector.begin(), organismVector.end(), organismVector[i]), organismVector.end());
            //organismVector.erase(organismVector.begin()+i);
        }
    }
}

void World::sortVector() {
    for (int i = 0; i < organismVector.size()-1; i++)
    {
        for (int j = 0; j < organismVector.size()-1-i; j++)
            if (organismVector[j]->getInitiative() < organismVector[j+1]->getInitiative())
            {
                Organism* temp = organismVector[j];
                organismVector[j] = organismVector[j+1];
                organismVector[j+1] = temp;
            }
    }
    for (int i = 0; i < organismVector.size()-1; i++)
    {
        for (int j = 0; j < organismVector.size()-1-i; j++)
            if (organismVector[j]->getInitiative() == organismVector[j+1]->getInitiative() && organismVector[j]->getAge() < organismVector[j+1]->getAge())
            {
                Organism* temp = organismVector[j];
                organismVector[j] = organismVector[j+1];
                organismVector[j+1] = temp;
            }
    }
}

void World::moveOrganism(Organism *organism, Coordinates coordinates) {
    worldMap[organism->getLocationY()][organism->getLocationX()] = nullptr;
    worldMap[coordinates.y][coordinates.x] = organism;
    organism->setLocationY(coordinates.y);
    organism->setLocationX(coordinates.x);
}

bool World::isStillGameOn() const{
    if (!this->isGameOn)
        return false;
    return true;
}

void World::setIsGameOn(bool isGameOn) {
    this->isGameOn = isGameOn;
}

bool World::checkVector() {
    for (int i = 0; i < organismVector.size(); i++)
        if (organismVector[i]->getName() == '#')
            return true;
    return false;
}

void World::debugVector()
{
    for (int i = 0; i < organismVector.size(); i++)
        cout << organismVector[i]->getName();
}

void World::saveToFile() {
    ofstream myFile;
    myFile.open("world.txt");
    myFile << this->getSizeY() << " " << this->getSizeX() << " " << this->round << " " << this->organismVector.size() <<  "\n";
    for (int i = 0; i < organismVector.size(); i++)
    {
        if (organismVector[i]->getName() == '#')
        {
            myFile << (int)organismVector[i]->getName() << " " << organismVector[i]->getLocationY() << " " << organismVector[i]->getLocationX() << " " << organismVector[i]->getStrength() << " " << organismVector[i]->getInitiative() << " " << organismVector[i]->getAge() << " " << getSuperPower() << " " << getRounds() << " " << getToNext() << "\n";
        }
        else
        {
            myFile << (int)organismVector[i]->getName() << " " << organismVector[i]->getLocationY() << " " << organismVector[i]->getLocationX() << " " << organismVector[i]->getStrength() << " " << organismVector[i]->getInitiative() << " " << organismVector[i]->getAge() << "\n";
        }
    }
    myFile.close();
}

void World::setSuperPower(bool superPower) {
    this->superPower = superPower;
}

void World::setRounds(int rounds) {
    this->rounds = rounds;
}

void World::setToNext(int toNext) {
    this->toNext = toNext;
}

void World::setSizeX(int sizeX)
{
    this->size.x = sizeX;
}

void World::setSizeY(int sizeY)
{
    this->size.y = sizeY;
}

bool World::getSuperPower() const {
    return this->superPower;
}

int World::getRounds() const {
    return this->rounds;
}

int World::getToNext() const {
    return this->toNext;
}

void World::loadFromFile() {
    ifstream myFile;
    myFile.open("world.txt");
    if (!myFile.is_open())
        cout << "Something went wrong file cannot be loaded!" << endl;
    else
    {
        string line;
        int i = 0;
        int j = 0;
        int organismCount = 0;
        while (getline(myFile, line))
        {
            stringstream lineStream(line);
            int value;
            if (!i)
            {
                while (lineStream >> value)
                {
                    if (j == 0)
                        setSizeY(value);
                    else if (j == 1)
                        setSizeX(value);
                    else if (j == 2)
                        setRounds(value);
                    else
                        organismCount = value;
                    j++;
                }
                generateWorld();
                i++;
            }
            else
            {
                char name;
                Coordinates loc;
                int stren, init, age, rounds, toNext;
                int k = 0;
                bool superPower;
                while (lineStream >> value)
                {
                    if (k == 0)
                    {
                        name = char(value);
                    }
                    else if (k == 1)
                    {
                        loc.y = value;
                    }
                    else if (k == 2)
                    {
                        loc.x = value;
                    }
                    else if (k == 3)
                    {
                        stren = value;
                    }
                    else if (k == 4)
                    {
                        init = value;
                    }
                    else if (k == 5)
                    {
                        age = value;
                    }
                    else if (k == 6)
                    {
                        superPower = value;
                    }
                    else if (k == 7)
                    {
                        rounds = value;
                    }
                    else if (k == 8)
                    {
                        toNext = value;
                    }
                    k++;
                }
                if (name == 'W')
                {
                    Wolf* newWolf = new Wolf(this, loc);
                    newWolf->setLocationY(loc.y);
                    newWolf->setLocationX(loc.x);
                    newWolf->setStrength(stren);
                    newWolf->setInitiative(init);
                    newWolf->setAge(age);
                }
                else if (name == 'S')
                {
                    Sheep* newSheep = new Sheep(this, loc);
                    newSheep->setLocationY(loc.y);
                    newSheep->setLocationX(loc.x);
                    newSheep->setStrength(stren);
                    newSheep->setInitiative(init);
                    newSheep->setAge(age);
                }
                else if (name == 'F')
                {
                    Fox* newFox = new Fox(this, loc);
                    newFox->setLocationY(loc.y);
                    newFox->setLocationX(loc.x);
                    newFox->setStrength(stren);
                    newFox->setInitiative(init);
                    newFox->setAge(age);
                }
                else if (name == 'T')
                {
                    Turtle* newTurtle = new Turtle(this, loc);
                    newTurtle->setLocationY(loc.y);
                    newTurtle->setLocationX(loc.x);
                    newTurtle->setStrength(stren);
                    newTurtle->setInitiative(init);
                    newTurtle->setAge(age);
                }
                else if (name == 'A')
                {
                    Antelope* newAntelope = new Antelope(this, loc);
                    newAntelope->setLocationY(loc.y);
                    newAntelope->setLocationX(loc.x);
                    newAntelope->setStrength(stren);
                    newAntelope->setInitiative(init);
                    newAntelope->setAge(age);
                }
                else if (name == 'G')
                {
                    Grass* newGrass = new Grass(this, loc);
                    newGrass->setLocationY(loc.y);
                    newGrass->setLocationX(loc.x);
                    newGrass->setStrength(stren);
                    newGrass->setInitiative(init);
                    newGrass->setAge(age);
                }
                else if (name == 'D')
                {
                    Dandelion* newDandelion = new Dandelion(this, loc);
                    newDandelion->setLocationY(loc.y);
                    newDandelion->setLocationX(loc.x);
                    newDandelion->setStrength(stren);
                    newDandelion->setInitiative(init);
                    newDandelion->setAge(age);
                }
                else if (name == 'U')
                {
                    Guarana* newGuarana = new Guarana(this, loc);
                    newGuarana->setLocationY(loc.y);
                    newGuarana->setLocationX(loc.x);
                    newGuarana->setStrength(stren);
                    newGuarana->setInitiative(init);
                    newGuarana->setAge(age);
                }
                else if (name == 'B')
                {
                    WolfBerries* newWolfBerries = new WolfBerries(this, loc);
                    newWolfBerries->setLocationY(loc.y);
                    newWolfBerries->setLocationX(loc.x);
                    newWolfBerries->setStrength(stren);
                    newWolfBerries->setInitiative(init);
                    newWolfBerries->setAge(age);
                }
                else if (name == 'H')
                {
                    Hogweed* newHogweed = new Hogweed(this, loc);
                    newHogweed->setLocationY(loc.y);
                    newHogweed->setLocationX(loc.x);
                    newHogweed->setStrength(stren);
                    newHogweed->setInitiative(init);
                    newHogweed->setAge(age);
                }
                else if (name == '#')
                {
                    Human* newHuman = new Human(this, loc);
                    newHuman->setLocationY(loc.y);
                    newHuman->setLocationX(loc.x);
                    newHuman->setStrength(stren);
                    newHuman->setInitiative(init);
                    newHuman->setAge(age);
                    setSuperPower(superPower);
                    setRounds(rounds);
                    setToNext(toNext);
                }
            }
        }
    }
    myFile.close();
}

void World::generateWorld() {
    this->worldMap = new Organism**[size.y];
    for (int i = 0; i < size.y; i++)
        worldMap[i] = new Organism*[size.x];
    clearMap(size);
}

World::~World() {
    for (int i = 0; i < organismVector.size(); i++)
    {
        organismVector[i]->Organism::~Organism();
    }
    updateVector();
}
