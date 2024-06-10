#include "Catan.hpp"

class Player;
class Board;




void Catan::SetPlayerColor()
{
    p1.setColor(RED);
    p2.setColor(BLUE);
    p3.setColor(GREEN);
}

// void Catan::ChooseStartingPlayer()
// {
//     int p1_roll = p1.rollDice();
//     int p2_roll = p2.rollDice();
//     int p3_roll = p3.rollDice();
//     if (p1_roll > p2_roll && p1_roll > p3_roll) {
//         cout << "Player 1 goes first" << endl;
//     } else if (p2_roll > p1_roll && p2_roll > p3_roll) {
//         cout << "Player 2 goes first" << endl;
//     } else if (p3_roll > p1_roll && p3_roll > p2_roll) {
//         cout << "Player 3 goes first" << endl;
//     } else {
//         cout << "There was a tie, rerolling" << endl;
//         ChooseStartingPlayer();
//     }
//     //
// }



void Catan:: StartGame() {

    //get 3 names from the user
    cout << "Welcome to Catan!" << endl;
    //initialize the board- set the resources and numbers for each tile
    //this->board.InitResourcesAndNumbers();
    cout << "Enter the name of player 1: ";
    string name1;
    cin >> name1;
    p1.setName(name1);
    cout << "Enter the name of player 2: ";
    string name2;
    cin >> name2;
    p2.setName(name2);
    cout << "Enter the name of player 3: ";
    string name3;
    cin >> name3;
    p3.setName(name3);
    SetPlayerColor();
    cout << "Hello " << p1.getName() << ", Your color is: "<< p1.getColor()  <<endl;
    cout << "Hello " << p2.getName() << ", Your color is: "<< p2.getColor()  <<endl;
    cout << "Hello " << p3.getName() << ", Your color is: "<< p3.getColor()  <<endl;
    //RED player goes first, then BLUE, then GREEN
    firstTour(board);
    //each player places 2 settlements and 2 roads
    //each player gets 2 resources for each settlement and 1 resource for each city
}

void Catan::firstTour(Board &board)
{
     //each player place 2 settlements and 2 roads
    //RED player goes first
    cout << "Player 1, place your first settlement: ";
    int vertexNum;
    cin >> vertexNum;
    while (p1.placeSettlementFirst(board, vertexNum) == 0)
    {
        cout << "Invalid vertex, please try again" << endl;
        cin >> vertexNum;
    }
    cout << "Player 1, place your first road: ";
    int edgeNum;
    cin >> edgeNum;
    while (p1.placeRoad(board, edgeNum) == 0)
    {
        cout << "Invalid edge, please try again" << endl;
        cin >> edgeNum;
    }
    cout << "Player 1, place your second settlement: ";
    cin >> vertexNum;
    while (p1.placeSettlementFirst(board, vertexNum) == 0)
    {
        cout << "Invalid vertex, please try again" << endl;
        cin >> vertexNum;
    }
    cout << "Player 1, place your second road: ";
    cin >> edgeNum;
    while (p1.placeRoad(board, edgeNum) == 0)
    {
        cout << "Invalid edge, please try again" << endl;
        cin >> edgeNum;
    }
    //BLUE player goes second
    cout << "Player 2, place your first settlement: ";
    cin >> vertexNum;
    while (p2.placeSettlementFirst(board, vertexNum) == 0)
    {
        cout << "Invalid vertex, please try again" << endl;
        cin >> vertexNum;
    }
    cout << "Player 2, place your first road: ";
    cin >> edgeNum;
    while (p2.placeRoad(board, edgeNum) == 0)
    {
        cout << "Invalid edge, please try again" << endl;
        cin >> edgeNum;
    }
    cout << "Player 2, place your second settlement: ";
    cin >> vertexNum;
    while (p2.placeSettlementFirst(board, vertexNum) == 0)
    {
        cout << "Invalid vertex, please try again" << endl;
        cin >> vertexNum;
    }
   // p2.addResource(board.getVertex(vertexNum)->getResource(),1);
    cout << "Player 2, place your second road: ";
    cin >> edgeNum;
    while (p2.placeRoad(board, edgeNum) == 0)
    {
        cout << "Invalid edge, please try again" << endl;
        cin >> edgeNum;
    }
    //GREEN player goes third
    cout << "Player 3, place your first settlement: ";
    cin >> vertexNum;
    while (p3.placeSettlementFirst(board, vertexNum) == 0)
    {
        cout << "Invalid vertex, please try again" << endl;
        cin >> vertexNum;
    }
    cout << "Player 3, place your first road: ";
    cin >> edgeNum;
    while (p3.placeRoad(board, edgeNum) == 0)
    {
        cout << "Invalid edge, please try again" << endl;
        cin >> edgeNum;
    }
    cout << "Player 3, place your second settlement: ";
    cin >> vertexNum;
    while (p3.placeSettlementFirst(board, vertexNum) == 0)
    {
        cout << "Invalid vertex, please try again" << endl;
        cin >> vertexNum;
    }
    cout << "Player 3, place your second road: ";
    cin >> edgeNum;
    while (p3.placeRoad(board, edgeNum) == 0)
    {
        cout << "Invalid edge, please try again" << endl;
        cin >> edgeNum;
    }
}

void Catan::progressGame()
{
    //each player takes a turn
    //each player can build a settlement, road, or city
    //each player can trade resources with other players
    //each player can buy a development card
    //each player can play a development card
    //each player can end their turn
    //the game is over when a player reaches 10 points
    //the player with the most points wins



    
    board.getBoard();
   // board.getTiles().size();
    while (p1.getPoints() < 10 && p2.getPoints() < 10 && p3.getPoints() < 10)
    {
        //player 1's turn
        cout << "Player 1, it's your turn" << endl;
        p1.printResources();
        p1.rollDice(board);
        p1.printResources();
        p2.printResources();
        p3.printResources();
        cout << "You rolled a " << p1.getDiceRoll() << endl;
        cout << "Would you like to build a settlement, road, or city?" << endl;
        cout << "1. Settlement" << endl;
        cout << "2. Road" << endl;
        cout << "3. City" << endl;
        cout << "4. End turn" << endl;
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter the vertex number to place your settlement: ";
            int vertexNum;
            cin >> vertexNum;
          //  p1.placeSettlement(board, vertexNum);
        }
        else if (choice == 2)
        {
            cout << "Enter the edge number to place your road: ";
            int edgeNum;
            cin >> edgeNum;
            p1.placeRoad(board, edgeNum);
        }
        else if (choice == 3)
        {
            cout << "Enter the vertex number to place your city: ";
            int vertexNum;
            cin >> vertexNum;
            p1.placeCity(board, vertexNum);
        }
        else if (choice == 4)
        {
            p1.endTurn();
        }
        //player 2's turn
        cout << "Player 2, it's your turn" << endl;
        p2.printResources();
        cout << "Would you like to build a settlement, road, or city?" << endl;
        cout << "1. Settlement" << endl;
        cout << "2. Road" << endl;
        cout << "3. City" << endl;
        cout << "4. End turn" << endl;
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter the vertex number to place your settlement: ";
        }
    }
    printWinner();
}




//the game is over when a player reaches 10 points
void Catan::printWinner()
{
    if (p1.getPoints() >= 10)
    {
        cout << "Player 1 wins!" << endl;
    }
    else if (p2.getPoints() >= 10)
    {
        cout << "Player 2 wins!" << endl;
    }
    else if (p3.getPoints() >= 10)
    {
        cout << "Player 3 wins!" << endl;
    }
}





