#include "Catan.hpp"

class Player;
class Board;

// #define WOOD 1
// #define BRICK 2
// #define SHEEP 3
// #define WHEAT 4
// #define IRON 5
// #define DESERT 0

// cout << "🌲 Wood: " << resources[1] << endl;   // Tree emoji for Wood
// cout << "🧱 Brick: " << resources[2] << endl;  // Brick emoji
// cout << "🐑 Sheep: " << resources[3] << endl;  // Sheep emoji
// cout << "🌾 Wheat: " << resources[4] << endl;  // Wheat emoji
// cout << "🪨 Iron:
// 🌲🧱 🐑🌾🪨

void Catan::SetPlayerColor()
{
    p1.setColor(RED);
    p2.setColor(BLUE);
    p3.setColor(GREEN);
}
void Catan::StartGame()
{
    // get 3 names from the user
    cout << "Welcome to Catan!" << endl;
    // initialize the board- set the resources and numbers for each tile
    // this->board.InitResourcesAndNumbers();
    cout << "Enter the name of player 1: ";
    string name1;
    cin >> name1;
    p1.setName(name1);
    cout << "Enter the name of player 2: ";
    string name2;
    cin >> name2;
    p2.setName(name2);
    cout << "Enter the name of player 3: ";
    string name3;
    cin >> name3;
    p3.setName(name3);
    SetPlayerColor();
    cout << "Hello " << p1.getName() << ", Your color is: " << p1.getColorName() << endl;
    cout << "Hello " << p2.getName() << ", Your color is: " << p2.getColorName() << endl;
    cout << "Hello " << p3.getName() << ", Your color is: " << p3.getColorName() << endl;
    // RED player goes first, then BLUE, then GREEN
    firstTour(board);
    // each player places 2 settlements and 2 roads
    // each player gets 2 resources for each settlement and 1 resource for each city
}

void Catan::firstTour(Board &board)
{
    // each player place 2 settlements and 2 roads
    // RED player goes first
    cout << "Player 1, " << p1.getName() << ", place your first settlement: ";
    int vertexNum;
    vertexNum = inputInt();
    while (p1.placeSettlementFirst(board, vertexNum) == 0)
    {
        cout << "Invalid vertex, please try again" << endl;
        vertexNum = inputInt();
    }
    cout << "Player 1, " << p1.getName() << ", place your first road: ";
    int edgeNum;
    edgeNum = inputInt();
    while (p1.placeRoad(board, edgeNum) == 0)
    {
        cout << "Invalid edge, please try again" << endl;
        edgeNum = inputInt();
    }
    cout << "Player 1, " << p1.getName() << ", place your second settlement: ";
    vertexNum = inputInt();
    while (p1.placeSettlementFirst(board, vertexNum) == 0)
    {
        cout << "Invalid vertex, please try again" << endl;
        vertexNum = inputInt();
    }
    cout << "Player 1, " << p1.getName() << ", place your second road: ";
    edgeNum = inputInt();
    while (p1.placeRoad(board, edgeNum) == 0)
    {
        cout << "Invalid edge, please try again" << endl;
        edgeNum = inputInt();
    }
    // // // BLUE player goes second
    // cout << "Player 2, " << p2.getName() << ", place your first settlement: ";
    // vertexNum = inputInt();
    // while (p2.placeSettlementFirst(board, vertexNum) == 0)
    // {
    //     cout << "Invalid vertex, please try again" << endl;
    //     vertexNum = inputInt();
    // }
    // cout << "Player 2, " << p2.getName() << ", place your first road: ";
    // edgeNum = inputInt();
    // while (p2.placeRoad(board, edgeNum) == 0)
    // {
    //     cout << "Invalid edge, please try again" << endl;
    //     edgeNum = inputInt();
    // }
    // cout << "Player 2, " << p2.getName() << ", place your second settlement: ";
    // vertexNum = inputInt();
    // while (p2.placeSettlementFirst(board, vertexNum) == 0)
    // {
    //     cout << "Invalid vertex, please try again" << endl;
    //     vertexNum = inputInt();
    // }
    // cout << "Player 2, " << p2.getName() << ", place your second road: ";
    // edgeNum = inputInt();
    // while (p2.placeRoad(board, edgeNum) == 0)
    // {
    //     cout << "Invalid edge, please try again" << endl;
    //     edgeNum = inputInt();
    // }
    // // GREEN player goes third
    // cout << "Player 3, " << p3.getName() << ", place your first settlement: ";
    // vertexNum = inputInt();
    // while (p3.placeSettlementFirst(board, vertexNum) == 0)
    // {
    //     cout << "Invalid vertex, please try again" << endl;
    //     vertexNum = inputInt();
    // }
    // cout << "Player 3, " << p3.getName() << ", place your first road: ";
    // edgeNum = inputInt();
    // while (p3.placeRoad(board, edgeNum) == 0)
    // {
    //     cout << "Invalid edge, please try again" << endl;
    //     edgeNum = inputInt();
    // }
    // cout << "Player 3, " << p3.getName() << ", place your second settlement: ";
    // vertexNum = inputInt();
    // while (p3.placeSettlementFirst(board, vertexNum) == 0)
    // {
    //     cout << "Invalid vertex, please try again" << endl;
    //     vertexNum = inputInt();
    // }
    // cout << "Player 3, " << p3.getName() << ", place your second road: ";
    // edgeNum = inputInt();
    // while (p3.placeRoad(board, edgeNum) == 0)
    // {
    //     cout << "Invalid edge, please try again" << endl;
    //     edgeNum = inputInt();
    // }
}

void Catan::Dice7()
{
    // cout << "Dice rolled a 7" << endl;
    // all players with more than 7 cards must discard half of their cards
    int p1_resources = p1.getResources()[0] + p1.getResources()[1] + p1.getResources()[2] + p1.getResources()[3] + p1.getResources()[4];
    int p2_resources = p2.getResources()[0] + p2.getResources()[1] + p2.getResources()[2] + p2.getResources()[3] + p2.getResources()[4];
    int p3_resources = p3.getResources()[0] + p3.getResources()[1] + p3.getResources()[2] + p3.getResources()[3] + p3.getResources()[4];
    if (p1_resources > 7)
    {
        cout << p1.getName() << ", you have more than 7 resources, you must discard: " << p1_resources / 2 << " resources" << endl;
        p1.discardHalf();
    }
    if (p2_resources > 7)
    {
        cout << p2.getName() << ", you have more than 7 resources, you must discard: " << p2_resources / 2 << " resources" << endl;
        p2.discardHalf();
    }
    if (p3_resources > 7)
    {
        cout << p3.getName() << ", you have more than 7 resources, you must discard : " << p3_resources / 2 << " resources" << endl;
        p3.discardHalf();
    }
}

void Catan::progressGame()
{
    // each player takes a turn
    // each player can build a settlement, road, or city
    // each player can trade resources with other players
    // each player can buy a development card
    // each player can play a development card
    // each player can end their turn
    // the game is over when a player reaches 10 points
    // the player with the most points wins
    while (p1.getPoints() < 10 && p2.getPoints() < 10 && p3.getPoints() < 10)
    {
        // player 1's turn
        cout << p1.getName() << ", it's your turn" << endl;
        turn(board, p1, p2, p3);
        // player 2's turn
        cout << p2.getName() << ", it's your turn" << endl;
        turn(board, p2, p1, p3);
        // // player 3's turn
        cout << p3.getName() << ", it's your turn" << endl;
        turn(board, p3, p1, p2);
    }
    printWinner();
}

// each player takes a turn
// each player can build a settlement, road, or city
// each player can trade resources with other players
// each player can buy a development card
// each player can play a development card
// each player can end their turn
void Catan::turn(Board &board, Player &player, Player &player2, Player &player3)
{
    while (1)
    {
        int choice;
        cout << "You have: " << player.getPoints() << " points" << endl;
        cout << player.getName() << " ,you have the following resources:" << endl;
        player.printResources();
        cout << "Would you like to use a dev card or roll the dice?" << endl;
        cout << "1. Use dev card" << endl;
        cout << "2. Roll dice" << endl;

        while (1)
        {
            choice = inputInt();
            if (choice == 1 || choice == 2)
            {
                break;
            }
            cout << "Invalid choice, please try again" << endl;
        }
        switch (choice)
        {

        case 1:
        {
            int return_value = player.playDevCard(board, players);
            if (return_value == 0)
            {
                // cout << "You do not have any development cards" << endl;
                continue;
            }
            if (return_value > 0 && return_value < 6)
            {
                cout << "You played a development card" << endl;
                return;
            }
            if (choice == 6)
            {
                continue; // Exit the function to return to the previous menu
            }
            break;
        }

        case 2:
        {
            player.rollDice();
            cout << "You rolled a " << player.getDiceRoll() << endl;
            if (player.getDiceRoll() == 7)
            {
                Dice7();
            }
            ResourceDistribution(board, player.getDiceRoll());
            while (1)
            {
                cout << "You have: " << player.getPoints() << " points" << endl;
                cout << player.getName() << " ,you have the following resources:" << endl;
                player.printResources();
                cout << "Would you like to build, trade, or end your turn?" << endl;
                cout << "1. Build" << endl;
                cout << "2. Trade resources" << endl;
                cout << "3. Trade cards" << endl;
                cout << "4. Buy dev card. cost: 1 sheep 🐑 , 1 wheat 🌾 , 1 iron  🪨" << endl;
                cout << "5. End turn" << endl;
                while (1)
                {
                    choice = inputInt();
                    if (choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5)
                    {
                        break;
                    }
                    cout << "Invalid choice, please try again" << endl;
                }
                if (choice == 1)
                {
                    cout << "What would you like to build?" << endl;
                    cout << "1. Settlement:       1 wood  🌲 , 1 brick 🧱 , 1 sheep 🐑 , 1 wheat 🌾" << endl;
                    cout << "2. Road:             1 wood  🌲 , 1 brick 🧱" << endl;
                    cout << "3. City:             2 wheat 🌾 , 3 iron  🪨" << endl;
                    cout << "4. Return" << endl; // Added option to return
                    while (1)
                    {
                        choice = inputInt();
                        if (choice >= 1 && choice <= 4)
                        {
                            break;
                        }
                        cout << "Invalid choice, please try again" << endl;
                    }

                    if (choice == 1)
                    {
                        player.placeSettlementUtil(board);
                        continue;
                    }
                    else if (choice == 2)
                    {
                        player.placeRoadUtil(board);
                        continue;
                    }
                    else if (choice == 3)
                    {
                        player.placeCityUtil(board);
                        continue;
                    }
                    if (choice == 4)
                    {
                        continue; // Exit the function to return to the previous menu
                    }
                }
                else if (choice == 2)
                {
                    resourceTrade(player, player2, player3);
                    continue;
                }
                else if (choice == 3)
                {
                    cardsTrade(player, player2, player3);
                    continue;
                }
                else if (choice == 4)
                {
                    buyDevCard(player);
                    continue;
                }
                else if (choice == 5)
                {
                    player.endTurn();
                    return;
                }
            }
        }
        }
    }
}

// the game is over when a player reaches 10 points
void Catan::printWinner()
{
    if (p1.getPoints() >= 10)
    {
        cout << "Player 1 wins!" << endl;
    }
    else if (p2.getPoints() >= 10)
    {
        cout << "Player 2 wins!" << endl;
    }
    else if (p3.getPoints() >= 10)
    {
        cout << "Player 3 wins!" << endl;
    }
}

Board Catan::getBoard()
{
    return board;
}

// after roll dice, player get resources
// this func is called in progressGame
//  void Catan::playerResources(Board &board)
// need to get the dice and check if the player has a settlement or city on the tile
// if they do, they get resources

void Catan::ResourceDistribution(Board &board, int dice)
{
    for (auto &tile : *board.getTiles())
    {
        if (tile.getNumber() == dice)
        {
            int resource = tile.getResource();

            for (auto &vertex : tile.getVertices())
            {
                int resourceMultiplier = vertex->getHasCity() ? 2 : vertex->getHasSettlement() ? 1
                                                                                               : 0;

                for (auto *player : players)
                {
                    if (vertex->getColor() == player->getColor() && resourceMultiplier > 0)
                    {
                        player->addResource(resource, resourceMultiplier);
                        string resourceName;
                        switch (resource)
                        {
                        case WOOD:
                            resourceName = "wood";
                            break;
                        case BRICK:
                            resourceName = "brick";
                            break;
                        case SHEEP:
                            resourceName = "sheep";
                            break;
                        case WHEAT:
                            resourceName = "wheat";
                            break;
                        case IRON:
                            resourceName = "iron";
                            break;
                        }
                        cout << "Player " << player->getColor() << ", " << player->getName() << ", got " << resourceName << " from "
                             << (resourceMultiplier == 1 ? "settlement" : "city") << endl;
                    }
                }
            }
        }
    }
}

unique_ptr<DevCard> Catan::getCard()
{
    if (devCards.empty())
    {
        return nullptr; // or throw an exception
    }
    auto card = std::move(devCards.back());
    devCards.pop_back(); // remove the card from the deck
    return card;
}

int Catan::inputInt()
{
    int input;
    while (1)
    {
        cin >> input;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input, please try again" << endl;
        }
        else
        {
            break;
        }
    }
    return input;
}

int Catan::resourceTrade(Player &player, Player &player2, Player &player3)
{
    cout << "You have the following resources: " << endl;
    player.printResources();
    cout << "Would you like to trade with another player?" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    cout << "3. Return" << endl; // Added option to return
    int choice;
    while (1)
    {
        choice = inputInt();
        if (choice == 1 || choice == 2 || choice == 3)
        {
            break;
        }
        cout << "Invalid choice, please try again" << endl;
    }
    if (choice == 2)
    {
        return 0;
    }
    if (choice == 3)
    {
        return 0;
    }

    // player trade
    pair<map<int, int>, map<int, int>> trade = player.trade();
    map<int, int> wants_give = trade.first;  // what player wants to give
    map<int, int> wants_take = trade.second; // what player wants to take
    Player *player_to_take = nullptr;
    vector<Player *> possible_trades;

    if (player2.getResources()[0] - wants_take[0] >= 0 && player2.getResources()[1] - wants_take[1] >= 0 && player2.getResources()[2] - wants_take[2] >= 0 && player2.getResources()[3] - wants_take[3] >= 0 && player2.getResources()[4] - wants_take[4] >= 0)
    {
        possible_trades.push_back(&player2);
    }

    if (player3.getResources()[0] - wants_take[0] >= 0 && player3.getResources()[1] - wants_take[1] >= 0 && player3.getResources()[2] - wants_take[2] >= 0 && player3.getResources()[3] - wants_take[3] >= 0 && player3.getResources()[4] - wants_take[4] >= 0)
    {
        possible_trades.push_back(&player3);
    }

    if (possible_trades.empty())
    {
        cout << "No player has the resources you want" << endl;
        return 0;
    }
    else
    {
        for (int i = 0; i < possible_trades.size(); i++)
        {
            cout << "Player " << possible_trades.at(i)->getName() << ", you got requested to trade with " << player.getName() << endl;
            cout << "Player " << player.getName() << " wants to give: " << endl;
            cout << "wood 🌲: " << wants_give[0] << " brick 🧱: " << wants_give[1] << " sheep 🐑: " << wants_give[2] << " wheat 🌾: " << wants_give[3] << " iron 🪨  : " << wants_give[4] << endl;
            cout << "for: " << endl;
            cout << "wood 🌲: " << wants_take[0] << " brick 🧱: " << wants_take[1] << " sheep 🐑: " << wants_take[2] << " wheat 🌾: " << wants_take[3] << " iron 🪨  : " << wants_take[4] << endl;

            cout << "Player " << possible_trades.at(i)->getName() << ", do you want to trade with " << player.getName() << "?" << endl;
            cout << "1. Yes" << endl;
            cout << "2. No" << endl;
            while (1)
            {
                choice = inputInt();
                if (choice == 1 || choice == 2)
                {
                    break;
                }
                cout << "Invalid choice, please try again" << endl;
            }
            if (choice == 1)
            {
                player_to_take = possible_trades.at(i);
                break;
            }
        }
        if (player_to_take == nullptr)
        {
            cout << "No player wants to trade with you" << endl;
            return 0;
        }
        else
        {
            player_to_take->addResource(0, wants_give[0]);
            player_to_take->addResource(1, wants_give[1]);
            player_to_take->addResource(2, wants_give[2]);
            player_to_take->addResource(3, wants_give[3]);
            player_to_take->addResource(4, wants_give[4]);
            player.addResource(0, wants_take[0]);
            player.addResource(1, wants_take[1]);
            player.addResource(2, wants_take[2]);
            player.addResource(3, wants_take[3]);
            player.addResource(4, wants_take[4]);

            player_to_take->deleteResource(0, wants_take[0]);
            player_to_take->deleteResource(1, wants_take[1]);
            player_to_take->deleteResource(2, wants_take[2]);
            player_to_take->deleteResource(3, wants_take[3]);
            player_to_take->deleteResource(4, wants_take[4]);

            player.deleteResource(0, wants_give[0]);
            player.deleteResource(1, wants_give[1]);
            player.deleteResource(2, wants_give[2]);
            player.deleteResource(3, wants_give[3]);
            player.deleteResource(4, wants_give[4]);
            return 1;
        }
    }
}

int Catan::cardsTrade(Player &player, Player &player2, Player &player3)
{
    //     1. victory point: 2
    // 2. Knight: 2
    // 3. Road Building: 2
    // 4. Year Of Plenty: 1
    // 5. Monopoly: 2
    cout << "You have the following cards: " << endl;
    player.printCards();
    cout << "Would you like to trade with another player?" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    cout << "3. Return" << endl; // Added option to return
    int choice;
    while (1)
    {
        choice = inputInt();
        if (choice == 1 || choice == 2 || choice == 3)
        {
            break;
        }
        cout << "Invalid choice, please try again" << endl;
    }
    if (choice == 2)
    {
        return 0;
    }
    if (choice == 3)
    {
        return 0;
    }

    // player trade
    pair<map<int, int>, map<int, int>> trade = player.cardsTrade();
    map<int, int> wants_give = trade.first;  // what player wants to give
    map<int, int> wants_take = trade.second; // what player wants to take
    Player *player_to_take = nullptr;
    vector<Player *> possible_trades;
    if (player2.getCards()["VictoryPoint"] - wants_take[0] >= 0 && player2.getCards()["Knight"] - wants_take[1] >= 0 && player2.getCards()["RoadBuilding"] - wants_take[2] >= 0 && player2.getCards()["YearOfPlenty"] - wants_take[3] >= 0 && player2.getCards()["Monopoly"] - wants_take[4] >= 0)
    {
        possible_trades.push_back(&player2);
    }

    if (player3.getCards()["VictoryPoint"] - wants_take[0] >= 0 && player3.getCards()["Knight"] - wants_take[1] >= 0 && player3.getCards()["RoadBuilding"] - wants_take[2] >= 0 && player3.getCards()["YearOfPlenty"] - wants_take[3] >= 0 && player3.getCards()["Monopoly"] - wants_take[4] >= 0)
    {
        possible_trades.push_back(&player3);
    }

    if (possible_trades.empty())
    {
        cout << "No player has the cards you want" << endl;
        return 0;
    }
    else
    {
        for (int i = 0; i < possible_trades.size(); i++)
        {
            cout << "Player " << possible_trades.at(i)->getName() << ", you got requested to trade cards with " << player.getName() << endl;
            cout << "Player " << player.getName() << " wants to give: " << endl;
            cout << "VictoryPoint: " << wants_give[0] << " Knight: " << wants_give[1] << " RoadBuilding: " << wants_give[2] << " YearOfPlenty: " << wants_give[3] << " Monopoly: " << wants_give[4] << endl;
            cout << "for: " << endl;
            cout << "VictoryPoint: " << wants_take[0] << " Knight: " << wants_take[1] << " RoadBuilding: " << wants_take[2] << " YearOfPlenty: " << wants_take[3] << " Monopoly: " << wants_take[4] << endl;

            cout << "Player " << possible_trades.at(i)->getName() << ", do you want to trade with " << player.getName() << "?" << endl;
            cout << "1. Yes" << endl;
            cout << "2. No" << endl;
            while (1)
            {
                choice = inputInt();
                if (choice == 1 || choice == 2)
                {
                    break;
                }
                cout << "Invalid choice, please try again" << endl;
            }
            if (choice == 1)
            {
                player_to_take = possible_trades.at(i);
                break;
            }
        }
        if (player_to_take == nullptr)
        {
            cout << "No player wants to trade with you" << endl;
            return 0;
        }
        else
        {
            // cout << "---------------------------------" << endl;
            // player.printCards();
            // cout << "---" << endl;
            // player_to_take->printCards();
            // cout << "---------------------------------" << endl;

            for (int i = 0; i < wants_give[0]; i++)
            {
                player_to_take->addCard(player.getCard("VictoryPoint"));
            }
            for (int i = 0; i < wants_give[1]; i++)
            {
                player_to_take->addCard(player.getCard("Knight"));
            }
            for (int i = 0; i < wants_give[2]; i++)
            {
                player_to_take->addCard(player.getCard("RoadBuilding"));
            }
            for (int i = 0; i < wants_give[3]; i++)
            {
                player_to_take->addCard(player.getCard("YearOfPlenty"));
            }
            for (int i = 0; i < wants_give[4]; i++)
            {
                player_to_take->addCard(player.getCard("Monopoly"));
            }

            for (int i = 0; i < wants_take[0]; i++)
            {
                player.addCard(player_to_take->getCard("VictoryPoint"));
            }
            for (int i = 0; i < wants_take[1]; i++)
            {
                player.addCard(player_to_take->getCard("Knight"));
            }
            for (int i = 0; i < wants_take[2]; i++)
            {
                player.addCard(player_to_take->getCard("RoadBuilding"));
            }
            for (int i = 0; i < wants_take[3]; i++)
            {
                player.addCard(player_to_take->getCard("YearOfPlenty"));
            }
            for (int i = 0; i < wants_take[4]; i++)
            {
                player.addCard(player_to_take->getCard("Monopoly"));
            }

            // cout << "---------------------------------" << endl;
            // player.printCards();
            // cout << "---" << endl;
            // player_to_take->printCards();
            // cout << "---------------------------------" << endl;
            return 1;
        }
    }
}

int Catan::buyDevCard(Player &player)
{
    // cout << "Cost of buying a development card is: 1 sheep 🐑, 1 wheat 🌾, 1 iron 🪨" << endl;
    if (player.getResources()[SHEEP] < 1 || player.getResources()[WHEAT] < 1 || player.getResources()[IRON] < 1)
    {
        cout << "You do not have enough resources to buy a development card" << endl;
        return 0;
    }
    else
    {
        unique_ptr<DevCard> card = getCard();
        if (card == nullptr)
        {
            cout << "No more development cards available" << endl;
            return 0;
        }
        else
        {
            cout << "You got a development card: " << card->type() << endl;
            player.addCard(std::move(card));
            player.deleteResource(SHEEP, 1);
            player.deleteResource(WHEAT, 1);
            player.deleteResource(IRON, 1);
            player.printCards();
            return 1;
        }
    }
}
