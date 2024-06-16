#include "DevCard.hpp"


class Monopoly : public DevCard {
        virtual void use_card(Board &board, Player &player);
        virtual string type() const;
        
};