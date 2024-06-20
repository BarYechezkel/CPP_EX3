#include "Player.hpp"
#include <iostream> // Add this include for cout and endl
#include <cstdlib>  // Add this include for rand()
#include <limits>
using namespace std;

int inputInt();

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

string Player::getColorName() const
{
    if (color == 1)
    {
        return "RED";
    }
    if (color == 2)
    {
        return "BLUE";
    }
    if (color == 3)
    {
        return "GREEN";
    }
    return "";
}

int Player::getDiceRoll()
{
    return playerDice;
}

vector<unique_ptr<DevCard>> &Player::getDevCards()
{
    return vecDevCards;
}

int Player::playDevCard(Board &board, vector<Player *> &players)
{
    while (1)
    {
        // after we check in catan.cpp that the player has the card, we will call this function
        //  1. VictoryPoint
        //  2. Knight
        //  3. RoadBuilding
        //  4. YearOfPlenty
        //  5. Monopoly
        if (vecDevCards.size() == 0)
        {
            cout << "You do not have any development cards" << endl;
            return 0;
        }
        cout << "Which dev card would you like to play?" << endl;
        // cout << "1. Knight" << endl;
        // cout << "2. Road Building" << endl;
        // cout << "3. Year of Plenty" << endl;
        // cout << "4. Monopoly" << endl;
        // cout << "5. Victory Point" << endl;
        printCards();
        cout << "6. Return" << endl; // Added option to return
        int choice;
        while (1)
        {
            choice = inputInt();
            if (choice >= 1 && choice <= 6)
            {
                break;
            }
            cout << "Invalid choice, please try again" << endl;
        }

        if (choice == 6)
        {
            return 6;
        }
        if (choice == 1)
        {
            if (devCards["VictoryPoint"] == 0)
            {
                cout << "You do not have any victory point cards" << endl;
                continue;
            }
            // if the player has a victory point card
            // take a card from vecDevCards
            //  use the card buy playing it
            // remove the card from vecDevCards
            // add the card to the player's points
            // update the player's points
            // return 1
            useCard("VictoryPoint", board, players);
            removeCard("VictoryPoint", 1);
            return 1;
        }
        if (choice == 2)
        {
            if (devCards["Knight"] < 3)
            {
                cout << "You need 3 knight cards to get 2 points" << endl;
                continue;
            }
            if (devCards["Knight"] >= 3)
            {
                cout << "You have 3 knight cards, you got 2 points" << endl;
                // only update the points if the player has 3 knight cards
                addPoints(2);
                removeCard("Knight", 3);
                return 2;
            }
        }
        if (choice == 3)
        {
            // you can bulid 2 roads
            useCard("RoadBuilding", board, players);
            removeCard("RoadBuilding", 1);
            return 3;
        }
        if (choice == 4)
        {
            // you can take 2 resources from the bank
            useCard("YearOfPlenty", board, players);
            removeCard("YearOfPlenty", 1);
            return 4;
        }
        if (choice == 5)
        {
            // you can take all the resources of a type
            useCard("Monopoly", board, players);
            removeCard("Monopoly", 1);
            return 5;
        }
    }
    return 0;
}

map<int, int> &Player::getResources()
{
    return resources;
}

void Player::addCard(unique_ptr<DevCard> card)
{
    string cardType = card->type();
    vecDevCards.push_back(move(card));
    if (cardType == "VictoryPoint")
    {
        devCards["VictoryPoint"]++;
    }
    else if (cardType == "Knight")
    {
        devCards["Knight"]++;
    }
    else if (cardType == "RoadBuilding")
    {
        devCards["RoadBuilding"]++;
    }
    else if (cardType == "YearOfPlenty")
    {
        devCards["YearOfPlenty"]++;
    }
    else if (cardType == "Monopoly")
    {
        devCards["Monopoly"]++;
    }
}

void Player::removeCard(string cardType, int cardNum)
{
    // remove the card from the player's map of cards
    //   remove the card from the player's vecDevCards
    //   update the player's map of cards
    //   return 1
    int count = 0;
    for (int i = 0; i < vecDevCards.size(); i++)
    {
        if (vecDevCards[i]->type() == cardType)
        {
            vecDevCards.erase(vecDevCards.begin() + i);
            count++;
        }
        if (count == cardNum)
        {
            break;
        }
    }
    devCards[cardType] -= cardNum;
}

void Player::useCard(string cardType, Board &board, vector<Player *> &players)
{
    // use the card
    //  remove the card from the player's map of cards
    //  remove the card from the player's vecDevCards
    //  update the player's map of cards
    //  return 1
    for (int i = 0; i < vecDevCards.size(); i++)
    {
        if (vecDevCards[i]->type() == cardType)
        {
            vecDevCards[i]->use_card(board, *this, players);
            break;
        }
    }
}

void Player::printCards()
{
    // print the cards you have
    if (vecDevCards.size() == 0)
    {
        cout << "You do not have any development cards" << endl;
    }
    else
    {
        cout << "1. victory point: " << devCards["VictoryPoint"] << endl;
        cout << "2. Knight: " << devCards["Knight"] << endl;
        cout << "3. Road Building: " << devCards["RoadBuilding"] << endl;
        cout << "4. Year Of Plenty: " << devCards["YearOfPlenty"] << endl;
        cout << "5. Monopoly: " << devCards["Monopoly"] << endl;
    }
}

void Player::addPoints(int points)
{
    this->points += points;
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

void Player::deleteResource(int resource, int amount)
{
    resources[resource] -= amount;
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


void Player::printResources()
{
    // Print the defined resources
    // cout << "Player " << name << " has the following resources: " << endl;
    // Emoji
    cout << "Wood  🌲 : " << resources[0] << endl;  // Tree emoji for Wood
    cout << "Brick 🧱 : " << resources[1] << endl;  // Brick emoji
    cout << "Sheep 🐑 : " << resources[2] << endl;  // Sheep emoji
    cout << "Wheat 🌾 : " << resources[3] << endl;  // Wheat emoji
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
        resources[i] += board.getVertex(vertexNum)->getResources()[i];
    }
    points++;
    return 1;
}

int Player::placeSettlementUtil(Board &board)
{
    // cout << "Cost of building a settlement is: 1 wood 🌲, 1 brick 🧱, 1 sheep 🐑, 1 wheat 🌾" << endl;
    // cout << "1. Return" << endl;
    if (getResources()[WOOD] < 1 || getResources()[BRICK] < 1 || getResources()[SHEEP] < 1 || getResources()[WHEAT] < 1)
    {
        cout << "You do not have enough resources to build a settlement" << endl;
        return 0;
    }

    cout << "Enter the vertex number to place your settlement: ";
    int vertexNum;
    vertexNum = inputInt();
    while (placeSettlement(board, vertexNum) == 0)
    {
        cout << "Invalid vertex, please try again. or enter -1 to exit" << endl;
        vertexNum = inputInt();

        if (vertexNum == -1)
        {
            return 0;
        }
    }
    deleteResource(WOOD, 1);
    deleteResource(BRICK, 1);
    deleteResource(SHEEP, 1);
    deleteResource(WHEAT, 1);
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

int Player::placeRoadUtil(Board &board)
{
    // cout << "Cost of building a road is: 1 wood 🌲, 1 brick 🧱" << endl;
    if (getResources()[WOOD] < 1 || getResources()[BRICK] < 1)
    {
        cout << "You do not have enough resources to build a road" << endl;
        return 0;
    }

    cout << "Enter the edge number to place your road: ";
    int edgeNum;
    edgeNum = inputInt();
    while (placeRoad(board, edgeNum) == 0)
    {
        cout << "Invalid edge, please try again. or enter -1 to exit" << endl;
        edgeNum = inputInt();

        if (edgeNum == -1)
        {
            return 0;
        }
    }
    deleteResource(WOOD, 1);
    deleteResource(BRICK, 1);
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

int Player::placeCityUtil(Board &board)
{
    cout << "Cost of building a city is: 2 wheat 🌾, 3 iron 🪨" << endl;
    if (getResources()[WHEAT] < 2 || getResources()[IRON] < 3)
    {
        cout << "You do not have enough resources to build a city" << endl;
        return 0;
    }

    cout << "Enter the vertex number to place your city: ";
    int vertexNum;
    vertexNum = inputInt();
    while (placeCity(board, vertexNum) == 0)
        {
            cout << "Invalid vertex, please try again. or enter -1 to exit" << endl;
            vertexNum = inputInt();

            if (vertexNum == -1)
            {
                return 0;
            }
        }
    deleteResource(WHEAT, 2);
    deleteResource(IRON, 3);
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

pair<map<int, int>, map<int, int>> Player::trade()
{
    // cout << "You have the following resources: " << endl;
    // printResources();
    cout << "what would you like to give?" << endl;
    int wood_give;
    int brick_give;
    int sheep_give;
    int wheat_give;
    int iron_give;
    cout << "1. Wood 🌲 between 0 - " << resources[0] << ": ";
    while (1)
    {
        wood_give = inputInt();
        if (wood_give >= 0 && wood_give <= resources[0])
        {
            break;
        }
        cout << "Invalid input, please try again" << endl;
    }
    cout << "2. Brick 🧱 between 0 - " << resources[1] << ": ";
    while (1)
    {
        brick_give = inputInt();
        if (brick_give >= 0 && brick_give <= resources[1])
        {
            break;
        }
        cout << "Invalid input, please try again" << endl;
    }
    cout << "3. Sheep 🐑 between 0 - " << resources[2] << ": ";
    while (1)
    {
        sheep_give = inputInt();
        if (sheep_give >= 0 && sheep_give <= resources[2])
        {
            break;
        }
        cout << "Invalid input, please try again" << endl;
    }
    cout << "4. Wheat 🌾 between 0 - " << resources[3] << ": ";
    while (1)
    {
        wheat_give = inputInt();
        if (wheat_give >= 0 && wheat_give <= resources[3])
        {
            break;
        }
        cout << "Invalid input, please try again" << endl;
    }
    cout << "5. Iron 🪨  between 0 - " << resources[4] << ": ";
    while (1)
    {
        iron_give = inputInt();
        if (iron_give >= 0 && iron_give <= resources[4])
        {
            break;
        }
        cout << "Invalid input, please try again" << ": ";
    }
    cout << endl;
    map<int, int> want_give;
    want_give[0] = wood_give;
    want_give[1] = brick_give;
    want_give[2] = sheep_give;
    want_give[3] = wheat_give;
    want_give[4] = iron_give;

    map<int, int> want_take;
    cout << "what would you like to receive?" << endl;
    int wood_take;
    int brick_take;
    int sheep_take;
    int wheat_take;
    int iron_take;
    cout << "1. Wood 🌲: ";
    wood_take = inputInt(); // cout << endl;
    cout << "2. Brick 🧱: ";
    brick_take = inputInt(); // cout << endl;
    cout << "3. Sheep 🐑: ";
    sheep_take = inputInt(); // cout << endl;
    cout << "4. Wheat 🌾: ";
    wheat_take = inputInt(); // cout << endl;
    cout << "5. Iron 🪨 : ";
    iron_take = inputInt(); // cout << endl;
    cout << endl;
    want_take[0] = wood_take;
    want_take[1] = brick_take;
    want_take[2] = sheep_take;
    want_take[3] = wheat_take;
    want_take[4] = iron_take;
    return {want_give, want_take};
}

int Player::discardHalf()
{
    cout << "you have the following resources: " << endl;
    printResources();
    cout << "Please discard half of your resources" << endl;
    int total_to_discard = resources[0] + resources[1] + resources[2] + resources[3] + resources[4];
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

    if (resources[0] > 0)
    {
        cout << "you have " << resources[0] << " wood 🌲 " << "how many would you like to discard?" << endl;
        wood = inputInt();
        discarded += wood;
    }
    if (resources[1] > 0)
    {
        cout << "you have " << resources[1] << " brick 🧱 " << "how many would you like to discard?" << endl;
        brick = inputInt();
        discarded += brick;
    }
    if (resources[2] > 0)
    {
        cout << "you have " << resources[2] << " sheep 🐑 " << "how many would you like to discard?" << endl;
        sheep = inputInt();
        discarded += sheep;
    }
    if (resources[3] > 0)
    {
        cout << "you have " << resources[3] << " wheat 🌾 " << "how many would you like to discard?" << endl;
        wheat = inputInt();
        discarded += wheat;
    }
    if (resources[4] > 0)
    {
        cout << "you have " << resources[4] << " iron 🪨 " << "how many would you like to discard?" << endl;
        iron = inputInt();
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
        resources[0] -= wood;
        resources[1] -= brick;
        resources[2] -= sheep;
        resources[3] -= wheat;
        resources[4] -= iron;
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

int inputInt()
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
