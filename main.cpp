#include "Catan.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include <iostream>

int main()
{
    Player p1("Player1");
    Player p2("Player2");
    Player p3("Player3");
    Board board;
    Catan catan(p1, p2, p3, board);
    // p2.addPoints(10);
    catan.StartGame();
    catan.progressGame();
    // p1.setColor(2);
    // p1.placeSettlementFirst(board,8);
    // p1.placeRoad(board,12);
    // p1.placeRoad(board,11);
    // p1.placeSettlement(board,7);
    // p1.placeRoad(board,10);
    // board.printBoard();

    // cout << "enter cin"<<endl;
    // int x;
    // cin >> x;
    // while (p1.placeSettlement(board, x) == 0)
    // {
    //     cout << "enter cin"<<endl;
    //     cin >> x;
    // }

    // board.printBoard();
    //    board.printBoard();
    //  //  p1.placeSettlement(board, 0);
    //    p1.placeRoad(board, 0);
    //     p1.placeCity(board, 0);
    //    p1.printResources();
    //  board.printBoard();

    //     p2.placeSettlement(board, 3);
    //     p1.placeSettlement(board, 4);
    //     p3.placeSettlement(board, 7);
    //     p2.placeSettlement(board, 4);
    //     board.getVertex(3)->printVertex();
    //     p2.placeRoad(board, 0);
    //     p1.placeRoad(board, 4);
    //     p2.placeCity(board, 3);

    //    board.printBoard();
    // catan.getBoard().printBoard();
    return 0;
}
