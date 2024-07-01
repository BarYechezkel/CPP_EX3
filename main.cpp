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
    catan.StartGame();
    catan.progressGame();
    return 0;
}
