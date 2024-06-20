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
        resources[0] = 5; // wood
        resources[1] = 5; // brick
        resources[2] = 5; // sheep
        resources[3] = 5; // wheat
        resources[4] = 5; // iron

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
    int playDevCard(Board &board, vector<Player*> &players);
    map<int, int> &getResources();
    void addCard(unique_ptr<DevCard> card);
    void removeCard(string cardType,int cardNum);
    void useCard(string cardType, Board &board, vector<Player*> &players);
    // void updateDevCards();
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
    void printResources();

    // Placement actions
    int placeSettlementFirst(Board &board, int vertexNum);
    int placeSettlementUtil(Board &board);
    int placeSettlement(Board &board, int vertexNum);
    int placeRoad(Board &board, int edgeNum);
    int placeRoadUtil(Board &board);
    int placeCity(Board &board, int vertexNum);
    int placeCityUtil(Board &board);
    pair <map <int,int>,map <int,int>> trade();
    int discardHalf();
    int discardUtility(int to_discard);

    // Utility functions
    std::string parseColor(int color);
    int isValidPlaceFirst(Board &board, int vertexNum);
};

#endif // PLAYER_HPP