#ifndef CATAN_HPP
#define CATAN_HPP
#include "Player.hpp"
#include "Board.hpp"
#include <vector>
#include <string>
#include <iostream>
#include "DevCard.hpp"
#include "Knight.hpp"
#include "VictoryPoint.hpp"
#include "RoadBuilding.hpp"
#include "YearOfPlenty.hpp"
#include "Monopoly.hpp"
#include <algorithm>
#include <random>
#include <vector>
#include <limits>

#define RED 1
#define BLUE 2
#define GREEN 3

class Catan
{

private:
    Player &p1;
    Player &p2;
    Player &p3;
    vector<Player *> players;
    Board &board;
    vector<unique_ptr<DevCard>> devCards;

public:
    Catan(Player &p1, Player &p2, Player &p3, Board &board); 

    // progress the game
    void progressGame();
    // set color to player
    void SetPlayerColor();
    void turn(Board &board, Player &player, Player &p2, Player &p3);
    void printWinner();
    Board getBoard();
    void StartGame();
    void firstTour(Board &board);
    void Dice7();
    int resourceTrade(Player &player, Player &p2, Player &p3);
    int cardsTrade(Player &player, Player &p2, Player &p3);

    int buyDevCard(Player &player);
    void playerResources(Board &board);
    void ResourceDistribution(Board &board, int diceRoll);
    unique_ptr<DevCard> getCard();
    int inputInt();
    vector<unique_ptr<DevCard>> &getDevCards(); // get dev cards in bank
};

#endif // CATAN_HPP
