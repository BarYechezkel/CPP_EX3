#include "DevCard.hpp"


class Knight : public DevCard {
        virtual void use_card(Board &board, Player &player);
        virtual string type() const ;
};