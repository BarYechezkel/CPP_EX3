#include "VictoryPoint.hpp"


void VictoryPoint::use_card(Board &board, Player &player, vector<Player*> &players)
{
    player.addPoints(1);
    cout << player.getName() << " got 1 victory point!" << endl;
}

string VictoryPoint::type() const
{
    return "VictoryPoint";
}


