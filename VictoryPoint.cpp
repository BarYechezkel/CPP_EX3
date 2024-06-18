#include "VictoryPoint.hpp"


void VictoryPoint::use_card(Board &board, Player &player)
{
    player.addPoints(1);
}

string VictoryPoint::type() const
{
    return "VictoryPoint";
}


