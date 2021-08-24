#include "Wolf.h"

Wolf::Wolf(World *world, Coordinates location) : Animal(world, location, 9, 5, 'W') {
    std::cout << std::endl << std::endl << "Wywoluje konstruktor wilka" << std::endl << std::endl << std::endl;
}

Wolf::Wolf(World *world) : Animal(world, 9, 5, 'W') {
    std::cout << std::endl << std::endl << "Wywoluje konstruktor wilka" << std::endl << std::endl << std::endl;
}
