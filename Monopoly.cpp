#include "Monopoly.hpp"
#include <limits>

int check_inputInt();

void Monopoly::use_card(Board &board, Player &player, vector<Player *> &players)
{
    // all the other players need to give the chosen resource to the player
    cout << "Player " << player.getName() << " played Monopoly card" << endl;
    cout << "Which resource would you like to take from the other players?" << endl;
    cout << "1. Wood 🌲" << endl
         << "2. Brick 🧱" << endl
         << "3. Sheep 🐑" << endl
         << "4. Wheat 🌾" << endl
         << "5. Iron 🪨" << endl;
    int choice;
    while (1)
    {
        choice = check_inputInt();
        if (choice >= 1 && choice <= 6)
        {
            break;
        }
        cout << "Invalid choice, please try again" << endl;
    }

    int resource = choice - 1;
    // all the other players need to give the chosen resource to the player

    for (int i = 0; i < players.size(); i++)
    {
        if (players.at(i) != &player)
        {
            if (players.at(i)->getResources()[resource] > 0)
            {
                int amount = players.at(i)->getResources()[resource];
                players.at(i)->deleteResource(resource, amount);
                player.addResource(resource, amount);
            }
            // else
            // {
            //     cout << "Player " << players.at(i)->getName() << " does not have any " << choice << " to give" << endl;
            // }
        }
    }
    cout << "Player " << player.getName() << " now has: " << endl;
    player.printResources();
}


string Monopoly::type() const
{
    return "Monopoly";
}


int check_inputInt()
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