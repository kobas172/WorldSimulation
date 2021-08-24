#pragma once

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <algorithm>
#include <conio.h>
#include <fstream>
#include <string>
#include <sstream>
#include <windows.h>
using namespace std;

struct Coordinates {
    int y;
    int x;
    Coordinates(int y, int x)
    {
        this->y = y;
        this->x = x;
    }
    Coordinates()
    {
        this->y = 0;
        this->x = 0;
    }
};

enum directions {
    NORTH = 3,
    WEST = 2,
    EAST = 1,
    SOUTH = 0
};

enum keys {
    UP_ARROW = 72,
    DOWN_ARROW = 80,
    RIGHT_ARROW = 77,
    LEFT_ARROW = 75
};
