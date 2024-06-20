#include "YearOfPlenty.hpp"
#include <iostream>
#include <limits>

int checkInputInt();


void YearOfPlenty::use_card(Board &board, Player &player, vector<Player*> &players)
{
    cout << "Choose two resources to take from the bank" << endl;
     cout <<"1. Wood  🌲" << endl;
    cout << "2. Brick 🧱" << endl;
    cout << "3. Sheep 🐑" << endl;
    cout << "4. Wheat 🌾" << endl;
    cout << "5. Iron  🪨" << endl;
    cout << "Enter the number of the first resource: ";
    int resource1 = checkInputInt();
    if (resource1 < 1 || resource1 > 5)
    {
        cout << "Invalid resource, please try again" << endl;
        resource1 = checkInputInt();
    }
    cout << "Enter the number of the second resource: ";
    int resource2 = checkInputInt();
    if (resource2 < 1 || resource2 > 5)
    {
        cout << "Invalid resource, please try again" << endl;
        resource2 = checkInputInt();
    }
    player.addResource(resource1-1, 1);
    player.addResource(resource2-1, 1);
    cout << "Player " << player.getName() << " now has: " << endl;
    player.printResources();
}

string YearOfPlenty::type() const
{
    return "YearOfPlenty";
}


int checkInputInt()
{
    int input;
    while (1)
    {
        cin >> input;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input, please try again" << endl;
        }
        else
        {
            break;
        }
    }
    return input;
}