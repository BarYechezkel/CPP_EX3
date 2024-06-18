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
    // // BLUE player goes second
    cout << "Player 2, " << p2.getName() << ", place your first settlement: ";
    vertexNum = inputInt();
    while (p2.placeSettlementFirst(board, vertexNum) == 0)
    {
        cout << "Invalid vertex, please try again" << endl;
        vertexNum = inputInt();
    }
    cout << "Player 2, " << p2.getName() << ", place your first road: ";
    edgeNum = inputInt();
    while (p2.placeRoad(board, edgeNum) == 0)
    {
        cout << "Invalid edge, please try again" << endl;
        edgeNum = inputInt();
    }
    cout << "Player 2, " << p2.getName() << ", place your second settlement: ";
    vertexNum = inputInt();
    while (p2.placeSettlementFirst(board, vertexNum) == 0)
    {
        cout << "Invalid vertex, please try again" << endl;
        vertexNum = inputInt();
    }
    // p2.addResource(board.getVertex(vertexNum)->getResource(),1);
    cout << "Player 2, " << p2.getName() << ", place your second road: ";
    edgeNum = inputInt();
    while (p2.placeRoad(board, edgeNum) == 0)
    {
        cout << "Invalid edge, please try again" << endl;
        edgeNum = inputInt();
    }
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
        // cout << p3.getName() << ", it's your turn" << endl;
        // turn(board, p3, p1, p2);
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

        if (choice == 1)
        {
            if (player.getDevCards().size() == 0)
            {
                cout << "You do not have any development cards" << endl;
                continue;
            }

            cout << "Which dev card would you like to play?" << endl;
            player.printCards();
            // cout << "1. Knight" << endl;
            // cout << "2. Road Building" << endl;
            // cout << "3. Year of Plenty" << endl;
            // cout << "4. Monopoly" << endl;
            // cout << "5. Victory Point" << endl;
            cout << "6. Return" << endl; // Added option to return
            while (1)
            {
                choice = inputInt();
                if (choice >= 1 && choice <= 6)
                {
                    break;
                }
                cout << "Invalid choice, please try again" << endl;
            }
            if (choice == 6)
            {
                return; // Exit the function to return to the previous menu
            }
            int return_value = player.playDevCard(choice, board);
            if (return_value == 5)
            {
                // all the other players need to give the chosen resource to the player
                cout << "Player " << player.getName() << " played Monopoly card" << endl;
                cout << "Which resource would you like to take from the other players?" << endl;
                cout << "1. Wood 🌲" << endl
                     << "2. Brick 🧱" << endl
                     << "3. Sheep 🐑" << endl
                     << "4. Wheat 🌾" << endl
                     << "5. Iron 🪨" << endl;
                cout << "6. Return" << endl; // Added option to return
                while (1)
                {
                    choice = inputInt();
                    if (choice >= 1 && choice <= 6)
                    {
                        break;
                    }
                    cout << "Invalid choice, please try again" << endl;
                }
                if (choice == 6)
                {
                    return; // Exit the function to return to the previous menu
                }
                // all the other players need to give the chosen resource to the player
                choice = choice - 1;
                for (int i = 0; i < players.size(); i++)
                {
                    if (players.at(i) != &player)
                    {
                        if (players.at(i)->getResources()[choice] > 0)
                        {
                            int amount = players.at(i)->getResources()[choice];
                            players.at(i)->deleteResource(choice, amount);
                            player.addResource(choice, amount);
                        }
                        else
                        {
                            cout << "Player " << players.at(i)->getName() << " does not have any " << choice << " to give" << endl;
                        }
                    }
                }
            }
            return;
        }

        if (choice == 2)
        {
            player.rollDice();
            cout << "You rolled a " << player.getDiceRoll() << endl;
            if (player.getDiceRoll() == 7)
            {
                Dice7();
            }
            ResourceDistribution(board, player.getDiceRoll());
            cout << player.getName() << " ,you have the following resources:" << endl;
            player.printResources();
            cout << "Would you like to build, trade, or end your turn?" << endl;
            cout << "1. Build" << endl;
            cout << "2. Trade" << endl;
            cout << "3. End turn" << endl;
            while (1)
            {
                choice = inputInt();
                if (choice == 1 || choice == 2 || choice == 3)
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
                cout << "4. Development card: 1 sheep 🐑 , 1 wheat 🌾 , 1 iron  🪨" << endl;
                cout << "5. Return" << endl; // Added option to return
                while (1)
                {
                    choice = inputInt();
                    if (choice >= 1 && choice <= 5)
                    {
                        break;
                    }
                    cout << "Invalid choice, please try again" << endl;
                }
                if (choice == 5)
                {
                    return; // Exit the function to return to the previous menu
                }
                if (choice == 1)
                {
                    cout << "Cost of building a settlement is: 1 wood 🌲, 1 brick 🧱, 1 sheep 🐑, 1 wheat 🌾" << endl;
                    if (player.getResources()[WOOD] < 1 || player.getResources()[BRICK] < 1 || player.getResources()[SHEEP] < 1 || player.getResources()[WHEAT] < 1)
                    {
                        cout << "You do not have enough resources to build a settlement" << endl;
                    }
                    else
                    {
                        cout << "Enter the vertex number to place your settlement: ";
                        int vertexNum;
                        vertexNum = inputInt();
                        while (player.placeSettlement(board, vertexNum) == 0)
                        {
                            cout << "Invalid vertex, please try again" << endl;
                            vertexNum = inputInt();
                        }
                        player.deleteResource(WOOD, 1);
                        player.deleteResource(BRICK, 1);
                        player.deleteResource(SHEEP, 1);
                        player.deleteResource(WHEAT, 1);
                    }
                }
                else if (choice == 2)
                {
                    cout << "Cost of building a road is: 1 wood 🌲, 1 brick 🧱" << endl;
                    if (player.getResources()[WOOD] < 1 || player.getResources()[BRICK] < 1)
                    {
                        cout << "You do not have enough resources to build a road" << endl;
                    }
                    else
                    {
                        cout << "Enter the edge number to place your road: ";
                        int edgeNum;
                        edgeNum = inputInt();
                        while (player.placeRoad(board, edgeNum) == 0)
                        {
                            cout << "Invalid edge, please try again" << endl;
                            edgeNum = inputInt();
                        }
                        player.deleteResource(WOOD, 1);
                        player.deleteResource(BRICK, 1);
                    }
                }
                else if (choice == 3)
                {
                    cout << "Cost of building a city is: 2 wheat 🌾, 3 iron 🪨" << endl;
                    if (player.getResources()[WHEAT] < 2 || player.getResources()[IRON] < 3)
                    {
                        cout << "You do not have enough resources to build a city" << endl;
                    }
                    else
                    {
                        cout << "Enter the vertex number to place your city: ";
                        int vertexNum;
                        vertexNum = inputInt();
                        while (player.placeCity(board, vertexNum) == 0)
                        {
                            cout << "Invalid vertex, please try again" << endl;
                            return;
                            // vertexNum = inputInt();
                        }
                        player.deleteResource(WHEAT, 2);
                        player.deleteResource(IRON, 3);
                    }
                }
                else if (choice == 4)
                {
                    cout << "Cost of buying a development card is: 1 sheep 🐑, 1 wheat 🌾, 1 iron 🪨" << endl;
                    if (player.getResources()[SHEEP] < 1 || player.getResources()[WHEAT] < 1 || player.getResources()[IRON] < 1)
                    {
                        cout << "You do not have enough resources to buy a development card" << endl;
                    }
                    else
                    {
                        unique_ptr<DevCard> card = getCard();
                        player.addCard(std::move(card));
                        player.deleteResource(SHEEP, 1);
                        player.deleteResource(WHEAT, 1);
                        player.deleteResource(IRON, 1);
                        player.printCards();
                    }
                }
            }
            else if (choice == 2)
            {
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
                    return;
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
                        return;
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
                    }
                }
            }
            else if (choice == 3)
            {
                player.endTurn();
            }
            return;
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
    devCards.pop_back();
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
