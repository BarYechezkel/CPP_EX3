#ifndef DEVCARD_HPP
#define DEVCARD_HPP
#include <iostream>
#include <string>
#include "Board.hpp"
#include <memory>
#include "Player.hpp"
class Player;
using namespace std;
class DevCard {
public:
    // Pure virtual function making this class abstract
    virtual string type() const = 0;
    virtual void use_card(Board &board, Player &player,vector<Player*> &players) = 0;
    virtual ~DevCard() = default;      // Virtual destructor
};

#endif // DEVCARD_HPP





