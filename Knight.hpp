#include "DevCard.hpp"


class Knight : public DevCard {
        virtual void use_card(Board &board, Player &player, vector<Player*> &players) override;
        virtual string type() const override;
        
};