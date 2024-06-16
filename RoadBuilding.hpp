#include "DevCard.hpp"


class RoadBuilding : public DevCard {
        virtual void use_card(Board &board, Player &player);
        virtual string type() const ;
};