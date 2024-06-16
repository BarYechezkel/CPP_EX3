#ifndef CATAN_HPP
#define CATAN_HPP
#include "Player.hpp"
#include "Board.hpp"
#include <vector>
#include <string>
#include <iostream>

#define RED 1
#define BLUE 2
#define GREEN 3



class Catan{

private: 
    Player &p1;
    Player &p2;
    Player &p3;
    Board &board;

    


    public:
    Catan(Player &p1, Player &p2, Player &p3,  Board &board) : p1(p1), p2(p2), p3(p3) , board(board){ 
    }
    //chosen starting player
    void ChooseStartingPlayer();
    //progress the game
    void progressGame();
    //set color to player
    void SetPlayerColor();
    void turn(Board &board, Player &player,Player &p2, Player &p3);
    void printWinner();
    Board getBoard();
    void StartGame();
    void firstTour(Board &board);
    void Dice7();
    void playerResources(Board &board);
    void ResourceDistribution(Board &board, int diceRoll);
};

#endif//CATAN_HPP


