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
    vector<Player*> players;
    Board &board;
    vector<unique_ptr<DevCard>> devCards;

public:
    Catan(Player &p1, Player &p2, Player &p3, Board &board) : p1(p1), p2(p2), p3(p3), board(board)
    {

        // Knight Cards (Soldier Cards):3 cards
        // Victory Point Cards: 4 cards
        // Road Building Cards: 2 cards
        // Year of Plenty Cards: 2 cards
        // Monopoly Cards: 2 cards
        devCards.push_back(std::make_unique<Knight>());
        devCards.push_back(std::make_unique<Knight>());
        devCards.push_back(std::make_unique<Knight>());
        devCards.push_back(std::make_unique<VictoryPoint>());
        devCards.push_back(std::make_unique<VictoryPoint>());
        devCards.push_back(std::make_unique<VictoryPoint>());
        devCards.push_back(std::make_unique<VictoryPoint>());
        devCards.push_back(std::make_unique<RoadBuilding>());
        devCards.push_back(std::make_unique<RoadBuilding>());
        devCards.push_back(std::make_unique<YearOfPlenty>());
        devCards.push_back(std::make_unique<YearOfPlenty>());
        devCards.push_back(std::make_unique<Monopoly>());
        devCards.push_back(std::make_unique<Monopoly>());

        players.push_back(&p1);
        players.push_back(&p2);
        players.push_back(&p3);

        // Create a random device and a generator
        std::random_device rd;
        std::mt19937 g(rd());
        // Shuffle the vector
        std::shuffle(devCards.begin(), devCards.end(), g);
    }
    // chosen starting player
    void ChooseStartingPlayer();
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
    void playerResources(Board &board);
    void ResourceDistribution(Board &board, int diceRoll);
    unique_ptr<DevCard> getCard();
    int inputInt();
};

#endif // CATAN_HPP
