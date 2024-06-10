#ifndef CATAN_HPP
#define CATAN_HPP
#include "Player.hpp"
#include "Board.hpp"
#include <vector>
#include <string>
#include <iostream>
//using namespace std;

#define RED 1
#define BLUE 2
#define GREEN 3

// class Player;
// class Board;


class Catan{

private: 
    Player &p1;
    Player &p2;
    Player &p3;
    Board &board;

    //set color of player
    void SetPlayerColor();


    public:
    Catan(Player &p1, Player &p2, Player &p3,  Board &board) : p1(p1), p2(p2), p3(p3) , board(board){ 
    }
    //chosen starting player
    void ChooseStartingPlayer();
    //progress the game
    void progressGame();

    

    void printWinner();

    Board getBoard(){
        return board;
    }

    void StartGame();
    void firstTour(Board &board);
    void playerResources(Board &board);

};

#endif//CATAN_HPP