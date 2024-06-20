#include "RoadBuilding.hpp"
#include <iostream>
#include <limits>

int checksInputInt();

void RoadBuilding::use_card(Board &board, Player &player, vector<Player *> &players)
{
    cout << "Enter the first edge number to place your road: ";
    int edgeNum;
    edgeNum = checksInputInt();
    while (player.placeRoad(board, edgeNum) == 0)
    {
        cout << "Invalid edge, please try again" << endl;
        edgeNum = checksInputInt();
    }
    cout << "Enter the second edge number to place your road: ";
    edgeNum = checksInputInt();
    while (player.placeRoad(board, edgeNum) == 0)
    {
        cout << "Invalid edge, please try again" << endl;
        edgeNum = checksInputInt();
    }
}

string RoadBuilding::type() const
{
    return "RoadBuilding";
}

int checksInputInt()
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