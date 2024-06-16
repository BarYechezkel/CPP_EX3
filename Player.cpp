#include "Player.hpp"
#include <iostream> // Add this include for cout and endl
#include <cstdlib>  // Add this include for rand()
using namespace std;

// Accessors
string Player::getName() const
{
    return name;
}

int Player::getPoints()
{
    return points;
}

int Player::getColor() const
{
    return color;
}

int Player::getDiceRoll()
{
    return playerDice;
}

map<int, int> &Player::getResources()
{
    return resources;
}

// Mutators
void Player::setName(string name)
{
    this->name = name;
}

void Player::setColor(int color)
{
    this->color = color;
}

void Player::addResource(int resource, int amount)
{
    resources[resource] += amount;
}

// Game actions
int Player::rollDice()
{
    // Roll two dice and sum the results to get a number between 2 and 12
    int dice1 = rand() % 6 + 1; // Random number between 1 and 6
    int dice2 = rand() % 6 + 1; // Random number between 1 and 6
    int dice = dice1 + dice2;
    playerDice = dice;
    return dice;
}

void Player::trade(Player p2, string give, string take, int giveNum, int takeNum)
{
    // Implement trade logic
}

void Player::endTurn()
{
    // Implement end turn logic
}

void Player::printPoints()
{
    // Implement printing points logic
}

void Player::printResources()
{
    // Print the defined resources
    // cout << "Player " << name << " has the following resources: " << endl;
    // Emoji
    cout << "Wood  🌲 : " << resources[1] << endl;  // Tree emoji for Wood
    cout << "Brick 🧱 : " << resources[2] << endl;  // Brick emoji
    cout << "Sheep 🐑 : " << resources[3] << endl;  // Sheep emoji
    cout << "Wheat 🌾 : " << resources[4] << endl;  // Wheat emoji
    cout << "Iron  🪨  : " << resources[4] << endl; // Wheat emoji
}

// Placement actions
int Player::placeSettlementFirst(Board &board, int vertexNum)
{
    // place settlement on the board
    //  cout << "Placing settlement on vertex " << vertexNum << endl;
    // for (int i = 0; i < board.getVertex(vertexNum)->getEdges().size(); i++)
    // {
    //     // print the edges of the vertex
    //     cout << "Edge " << i << " of vertex " << vertexNum << " has id " << board.getVertex(vertexNum)->getEdges()[i]->getId() << endl;
    //     // board.getVertex(vertexNum)->getEdges()[i]->getId()
    // }
    if (isValidPlaceFirst(board, vertexNum) == 0)
    {
        return 0;
    }
    board.getVertex(vertexNum)->buildSettlement(color);
    for (int i = 0; i < board.getVertex(vertexNum)->getResources().size(); i++)
    {
        if (board.getVertex(vertexNum)->getResources()[i] > 0)
        {
            resources[i]++;
        }
    }
    points++;
    return 1;
}

int Player::placeSettlement(Board &board, int vertexNum)
{
    if (vertexNum < 0 || vertexNum > 53)
    {
        cout << "Invalid vertex number" << endl;
        return 0;
    }
    Vertex *vertex = board.getVertex(vertexNum);
    if (vertex->getHasSettlement() || vertex->getHasCity())
    {
        cout << "This vertex already has a " << (vertex->getHasSettlement() ? "settlement" : "city") << ", color:" << vertex->getColor() << endl;
        return 0; // Return 0 indicating failure
    }

    // Initialize variables
    int isValid = 0;
    Edge *firstEdge = nullptr;
    int otherVertex = 0;

    // Loop through the edges of the vertex to find the first edge owned by the player
    for (Edge *edge : vertex->getEdges())
    {
        if (edge->getPlayerColor() == color)
        {
            firstEdge = edge;

            // Check both ends of the edge for valid placement
            for (Vertex *endVertex : {firstEdge->getVertex1(), firstEdge->getVertex2()})
            {
                if (endVertex->getId() != vertexNum &&
                    (endVertex->getHasSettlement() == 0 || endVertex->getHasCity() == 0))
                {
                    otherVertex = endVertex->getId();
                    // Loop through the edges of the other vertex to check if it's connected to other player-owned edges
                    for (Edge *otherEdge : board.getVertex(otherVertex)->getEdges())
                    {
                        if (otherEdge->getId() != firstEdge->getId() && otherEdge->getPlayerColor() == color)
                        {
                            isValid = 1; // Set isValid to 1 indicating a valid location is found
                            break;       // Exit the loop since a valid location is found
                        }
                    }
                }
                if (isValid)
                    break; // Exit the loop if a valid location is found
            }
        }
        if (isValid)
            break; // Exit the loop if a valid location is found
    }

    // If no valid location is found, return 0 indicating failure
    if (!isValid)
        return 0;

    // If a valid location is found, place the settlement and increment points, then return 1 indicating success
    board.getVertex(vertexNum)->buildSettlement(color);
    points++;
    return 1;
}

int Player::placeRoad(Board &board, int edgeNum)
{
    if (edgeNum < 0 || edgeNum > 71)
    {
        cout << "Invalid edge number" << endl;
        return 0;
    }
    // place road on the board
    //  cout << "Placing road on edge " << edgeNum << endl;
    if (board.getEdge(edgeNum)->getHasRoad() == 1)
    {
        cout << "This edge already has a road, color:" << board.getEdge(edgeNum)->getPlayerColor() << endl;
        return 0;
    }
    if (board.getEdge(edgeNum)->getVertex1()->getColor() == color && board.getEdge(edgeNum)->getVertex2()->getColor() == color)
    {
        cout << "This edge is already adjacent to your settlements" << endl;
        return 0;
    }

    int isValid = 0;
    if (board.getEdge(edgeNum)->getVertex1()->getColor() == color)
    {
        if (board.getEdge(edgeNum)->getVertex2()->getHasSettlement() == 0)
        {
            // cout << "This edge is adjacent to a settlement of the same color, you can build a road here" << endl;
            isValid = 1;
        }
        else
        {
            // cout << "This edge is not adjacent to a settlement of the same color, you cannot build a road here" << endl;
            isValid = 0;
        }
    }
    if (board.getEdge(edgeNum)->getVertex2()->getColor() == color)
    {
        if (board.getEdge(edgeNum)->getVertex1()->getHasSettlement() == 0)
        {
            // cout << "This edge is adjacent to a settlement of the same color, you can build a road here" << endl;
            isValid = 1;
        }
        else
        {
            // cout << "This edge is not adjacent to a settlement of the same color, you cannot build a road here" << endl;
            isValid = 0;
        }
    }
    if (board.getEdge(edgeNum)->getVertex1()->getColor() == 0 && board.getEdge(edgeNum)->getVertex2()->getColor() == 0)
    {
        for (int i = 0; i < board.getEdge(edgeNum)->getVertex1()->getEdges().size(); i++)
        {
            if (board.getEdge(edgeNum)->getVertex1()->getEdges()[i]->getPlayerColor() == color)
            {
                isValid = 1;
                break;
            }
        }
        for (int i = 0; i < board.getEdge(edgeNum)->getVertex2()->getEdges().size(); i++)
        {
            if (board.getEdge(edgeNum)->getVertex2()->getEdges()[i]->getPlayerColor() == color)
            {
                isValid = 1;
                break;
            }
        }
    }
    if (isValid == 0)
    {
        cout << "This edge is not adjacent to any of your settlements" << endl;
        cout << "1" << endl;

        return 0;
    }
    board.getEdge(edgeNum)->buildRoad(color);
    return 1;
}

int Player::placeCity(Board &board, int vertexNum)
{
    // place city on the board
    //  cout << "Placing city on vertex " << vertexNum << endl;
    if (board.getVertex(vertexNum)->getHasSettlement() == 0)
    {
        cout << "No settlement on this vertex" << endl;
        return 0;
    }
    if (board.getVertex(vertexNum)->getColor() != color)
    {
        cout << "This is not your settlement" << endl;
        return 0;
    }
    if (board.getVertex(vertexNum)->getHasCity() == 1)
    {
        cout << "There is already a city on this vertex" << endl;
        return 0;
    }
    board.getVertex(vertexNum)->buildCity(color);
    points += 2;
    return 1;
}

pair <map<int,int>,map <int,int>> Player::trade()
{
    cout << "You have the following resources: " << endl;
    printResources();
    cout << "what would you like to give?" << endl;
    int wood_give;
    int brick_give;
    int sheep_give;
    int wheat_give;
    int iron_give;
    cout << "1. Wood 🌲 between 0 - " << resources[1] << endl;
    while (1)
    {
        cin >> wood_give;
        if (wood_give >= 0 && wood_give <= resources[1])
        {
            break;
        }
        cout << "Invalid input, please try again" << endl;
    }
    cout << "2. Brick 🧱 between 0 - " << resources[2] << endl;
    while (1)
    {
        cin >> brick_give;
        if (brick_give >= 0 && brick_give <= resources[2])
        {
            break;
        }
        cout << "Invalid input, please try again" << endl;
    }
    cout << "3. Sheep 🐑 between 0 - " << resources[3] << endl;
    while (1)
    {
        cin >> sheep_give;
        if (sheep_give >= 0 && sheep_give <= resources[3])
        {
            break;
        }
        cout << "Invalid input, please try again" << endl;
    }
    cout << "4. Wheat 🌾 between 0 - " << resources[4] << endl;
    while (1)
    {
        cin >> wheat_give;
        if (wheat_give >= 0 && wheat_give <= resources[4])
        {
            break;
        }
        cout << "Invalid input, please try again" << endl;
    }
    cout << "5. Iron 🪨 between 0 - " << resources[5] << endl;
    while (1)
    {
        cin >> iron_give;
        if (iron_give >= 0 && iron_give <= resources[5])
        {
            break;
        }
        cout << "Invalid input, please try again" << endl;
    }
    map<int,int> want_give;
    want_give[1] = wood_give;
    want_give[2] = brick_give;
    want_give[3] = sheep_give;
    want_give[4] = wheat_give;
    want_give[5] = iron_give;

    map<int,int> want_take;
    cout << "what would you like to receive?" << endl;
    int wood_take;
    int brick_take;
    int sheep_take;
    int wheat_take;
    int iron_take;
    cout << "1. Wood 🌲" << endl;
    cin >> wood_take;
    cout << "2. Brick 🧱" << endl;
    cin >> brick_take;
    cout << "3. Sheep 🐑" << endl;
    cin >> sheep_take;
    cout << "4. Wheat 🌾" << endl;
    cin >> wheat_take;
    cout << "5. Iron 🪨" << endl;
    cin >> iron_take;
    want_take[1] = wood_take;
    want_take[2] = brick_take;
    want_take[3] = sheep_take;
    want_take[4] = wheat_take;
    want_take[5] = iron_take;
    return {want_give , want_take};    
}

int Player::discardHalf()
{
    cout << "you have the following resources: " << endl;
    printResources();
    cout << "Please discard half of your resources" << endl;
    int total_to_discard = resources[1] + resources[2] + resources[3] + resources[4] + resources[5];
    int to_discard = total_to_discard / 2;
    cout << "You need to discard " << to_discard << " resources" << endl;
    // if the player has less than 7 resources, they do not need to discard
    // if player do not discard half, they will try again

    while (discardUtility(to_discard) != 1)
        ;
    printResources();
    return 1;
}

int Player::discardUtility(int to_discard)
{
    int discarded = 0;
    int wood = 0;
    int brick = 0;
    int sheep = 0;
    int wheat = 0;
    int iron = 0;

    if (resources[1] > 0)
    {
        cout << "you have" << resources[1] << " wood 🌲 " << "how many would you like to discard?" << endl;
        cin >> wood;
        discarded += wood;
    }
    if (resources[2] > 0)
    {
        cout << "you have " << resources[2] << " brick 🧱 " << "how many would you like to discard?" << endl;
        cin >> brick;
        discarded += brick;
    }
    if (resources[3] > 0)
    {
        cout << "you have " << resources[3] << " sheep 🐑 " << "how many would you like to discard?" << endl;
        cin >> sheep;
        discarded += sheep;
    }
    if (resources[4] > 0)
    {
        cout << "you have " << resources[4] << " wheat 🌾 " << "how many would you like to discard?" << endl;
        cin >> wheat;
        discarded += wheat;
    }
    if (resources[5] > 0)
    {
        cout << "you have " << resources[5] << " iron 🪨 " << "how many would you like to discard?" << endl;
        cin >> iron;
        discarded += iron;
    }
    if (discarded != to_discard)
    {
        cout << "You did not discard the correct amount of resources, please try again" << endl;
        return 0;
    }
    else
    {
        cout << "You have successfully discarded half of your resources" << endl;
        resources[1] -= wood;
        resources[2] -= brick;
        resources[3] -= sheep;
        resources[4] -= wheat;
        resources[5] -= iron;
        return 1;
    }
}

// Utility functions
string Player::parseColor(int color)
{
    if (color == 1)
    {
        return "RED";
    }
    else if (color == 2)
    {
        return "BLUE";
    }
    else if (color == 3)
    {
        return "GREEN";
    }
    else
    {
        return "No color";
    }
}

int Player::isValidPlaceFirst(Board &board, int vertexNum)
{
    if (vertexNum < 0 || vertexNum > 53)
    {
        cout << "Invalid vertex number" << endl;
        return 0;
    }
    if (board.getVertex(vertexNum)->getHasSettlement() == 1)
    {
        cout << "This vertex already has a settlement, color:" << board.getVertex(vertexNum)->getColor() << endl;
        return 0;
    }

    int isValid = 1;
    for (int i = 0; i < board.getVertex(vertexNum)->getEdges().size(); i++)
    {
        if (board.getVertex(vertexNum)->getEdges()[i]->getVertex1()->getId() != vertexNum)
        {
            if (board.getVertex(vertexNum)->getEdges()[i]->getVertex1()->getColor() != 0)
            {
                isValid = 0;
            }
        }
        if (board.getVertex(vertexNum)->getEdges()[i]->getVertex2()->getId() != vertexNum)
        {
            if (board.getVertex(vertexNum)->getEdges()[i]->getVertex2()->getColor() != 0)
            {
                isValid = 0;
            }
        }
    }
    if (isValid == 0)
    {
        return 0;
    }
    return 1;
}
