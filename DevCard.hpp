#ifndef DEVCARD_HPP
#define DEVCARD_HPP
#include <iostream>
#include <string>
#include "Board.hpp"
#include "Player.hpp"
using namespace std;
class DevCard {
public:
    // Pure virtual function making this class abstract
    virtual string type() const = 0;
    virtual void use_card() = 0;
    virtual ~DevCard() = default;      // Virtual destructor
};

// class Knight : public DevCard {
//         virtual void use_card(Board &board, Player &player){
//             cout << "Knight" << endl;
//         }
//         virtual string type() const {
//             return "Knight";
//         }

// };
// class RoadBuilding : public DevCard {
//         virtual void use_card(Board &board, Player &player){
//             cout << "Two Road Building" << endl;
//         }
//         virtual string type() const {
//             return "Two Road Building";
//         }

// };
// class YearOfPlenty : public DevCard {
//         virtual void use_card(Board &board, Player &player){
//             cout << "Year Of Plenty" << endl;
//         }
//         virtual string type() const {
//             return "Year Of Plenty";
//         }

// };
// class Monopoly : public DevCard {
//         virtual void use_card(Board &board, Player &player){
//             cout << "Monopoly" << endl;
//         }
//         virtual string type() const {
//             return "Monopoly";
//         }

// };
// class VictoryPoint : public DevCard {
//         virtual void use_card(Board &board, Player &player){
//             cout << "Victory Point" << endl;
//         }
//         virtual string type() const {
//             return "Victory Point";
//         }
// };

#endif // DEVCARD_HPP





