#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <string>
#include <vector>
#include <map>
#include "Board.hpp"
// using namespace std;

class Player
{

private:
    string name;
    int points;
    int color;
    int playerDice;
    map<int, int> resources; // key is the resource number, value is the amount of that resource

public:
    Player(string name) : name(name), points(0), color()
    {
        resources[1] = 0; // wood
        resources[2] = 0; // brick
        resources[3] = 0; // sheep
        resources[4] = 0; // wheat
        resources[5] = 0; // iron
    }

    // void placeSettelemnt(vector<string> places, vector<int> placesNum, Board board);
    // void placeRoad(vector<string> places, vector<int> placesNum, Board board);
    int rollDice(Board &board);
    void trade(Player p2, string give, string take, int giveNum, int takeNum);
    void endTurn();
    void printPoints();
    void setColor(int color)
    {
        this->color = color;
    }
    string getColor();
    int getDiceRoll()
    {
        return playerDice;
    }


    string getName()
    {
        return name;
    }

    int getPoints()
    {
        return points;
    }

    void setName(string name)
    {
        this->name = name;
    }

    int placeSettlementFirst(Board &board, int vertexNum);
    

    int placeRoad(Board &board, int edgeNum);
   

    void placeCity(Board &board, int vertexNum)
    {
        // place city on the board
        //  cout << "Placing city on vertex " << vertexNum << endl;
        if (board.getVertex(vertexNum)->getHasSettlement() == 0)
        {
            cout << "No settlement on this vertex" << endl;
            return;
        }
        if (board.getVertex(vertexNum)->getColor() != color)
        {
            cout << "This is not your settlement" << endl;
            return;
        }
        if (board.getVertex(vertexNum)->getHasCity() == 1)
        {
            cout << "There is already a city on this vertex" << endl;
            return;
        }
        board.getVertex(vertexNum)->buildCity(color);
    }

    void addResource(int resource, int amount)
    {
        resources[resource] += amount;
    }

    void printResources()
    {   //print the define resources
        cout << "Player " << name << " has the following resources: " << endl;
        cout << "Wood: " << resources[1] << endl;
        cout << "Brick: " << resources[2] << endl;
        cout << "Sheep: " << resources[3] << endl;
        cout << "Wheat: " << resources[4] << endl;
        cout << "Iron: " << resources[5] << endl;
    }


    //for first settlement
    int isValidPlaceFirst(Board& board, int vertexNum);


};

#endif