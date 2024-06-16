#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <vector>
#include <map>
#include "Board.hpp"
#include "DevCard.hpp"

class Player
{

private:
    string name;
    int points;
    int color;
    int playerDice;
    map<int, int> resources; // key is the resource number, value is the amount of that resource
   // vector <DevCard*> devCards; // key is the dev card number, value is the amount of that dev card
public:
    // Constructor
    Player(string name) : name(name), points(0), color()
    {
        resources[1] = 0; // wood
        resources[2] = 0; // brick
        resources[3] = 0; // sheep
        resources[4] = 0; // wheat
        resources[5] = 0; // iron
    }

     // Accessors
    std::string getName() const;
    int getPoints();
    int getColor() const;
    int getDiceRoll();
    std::map<int, int> &getResources();

    // Mutators
    void setName(std::string name);
    void setColor(int color);
    void addResource(int resource, int amount);

    // Game actions
    int rollDice();
    void trade(Player p2, std::string give, std::string take, int giveNum, int takeNum);
    void endTurn();
    void printPoints();
    void printResources();

    // Placement actions
    int placeSettlementFirst(Board &board, int vertexNum);
    int placeSettlement(Board &board, int vertexNum);
    int placeRoad(Board &board, int edgeNum);
    int placeCity(Board &board, int vertexNum);
    pair <map <int,int>,map <int,int>> trade();
    int discardHalf();
    int discardUtility(int to_discard);

    // Utility functions
    std::string parseColor(int color);
    int isValidPlaceFirst(Board &board, int vertexNum);
};

#endif // PLAYER_HPP