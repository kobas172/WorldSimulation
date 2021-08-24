#include "World.h"

int main() {
    int opt;
    cout << "Piotr Gorkowski, gr 2, 184515" << endl;
    cout << "1. Start new game." << endl;
    cout << "2. Load game." << endl;
    opt = _getch();
    if (opt == '1')
    {
        cout << "Enter world size: " << endl;
        Coordinates map;
        cout << "height: ";
        cin >> map.y;
        cout << "width: ";
        cin >> map.x;
        cout << endl;
        World world(map);
        while (world.isStillGameOn())
        {
            world.makeMove();
        }
    }
    else if (opt == '2')
    {
        World world = World();
        world.loadFromFile();
        while (world.isStillGameOn())
        {
            world.makeMove();
            cout << endl;
        }
    }
    cout << "END OF THE GAME!";
    _getch();
    _getch();
    _getch();
}
