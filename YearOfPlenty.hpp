#include "DevCard.hpp"


class YearOfPlenty : public DevCard {
        virtual void use_card(Board &board, Player &player) override;
        virtual string type() const override ;
};