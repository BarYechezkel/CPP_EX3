#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <vector>
#include <map>
#include "Board.hpp"
#include "DevCard.hpp"

class DevCard;

class Player
{

private:
    string name;
    int points;
    int color;
    int playerDice;
    map<int, int> resources; // key is the resource number, value is the amount of that resource
    vector<unique_ptr<DevCard>> vecDevCards;
    map <string, int> devCards;
public:
    // Constructor
    Player(string name) : name(name), points(0), color()
    {
        resources[0] = 0; // wood
        resources[1] = 0; // brick
        resources[2] = 0; // sheep
        resources[3] = 0; // wheat
        resources[4] = 00; // iron

        devCards["Knight"] = 0;
        devCards["VictoryPoint"] = 0;
        devCards["RoadBuilding"] = 0;
        devCards["YearOfPlenty"] = 0;
        devCards["Monopoly"] = 0;
    }

     // Accessors
    std::string getName() const;
    int getPoints();
    int getColor() const;
    string getColorName() const;
    int getDiceRoll();
    vector<unique_ptr<DevCard>> &getDevCards();
    int playDevCard(int cardNum, Board &board);
    map<int, int> &getResources();
    void addCard(unique_ptr<DevCard> card);
    void updateDevCards();
    void printCards();
    void addPoints(int points);

    // Mutators
    void setName(std::string name);
    void setColor(int color);
    void addResource(int resource, int amount);
    void deleteResource(int resource, int amount);

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