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
// 🌲🧱 🌾🪨 🐑

void Catan::SetPlayerColor()
{
    p1.setColor(RED);
    p2.setColor(BLUE);
    p3.setColor(GREEN);
}

// void Catan::ChooseStartingPlayer()
// {
//     int p1_roll = p1.rollDice();
//     int p2_roll = p2.rollDice();
//     int p3_roll = p3.rollDice();
//     if (p1_roll > p2_roll && p1_roll > p3_roll) {
//         cout << "Player 1 goes first" << endl;
//     } else if (p2_roll > p1_roll && p2_roll > p3_roll) {
//         cout << "Player 2 goes first" << endl;
//     } else if (p3_roll > p1_roll && p3_roll > p2_roll) {
//         cout << "Player 3 goes first" << endl;
//     } else {
//         cout << "There was a tie, rerolling" << endl;
//         ChooseStartingPlayer();
//     }
//     //
// }

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
    cout << "Hello " << p1.getName() << ", Your color is: " << p1.getColor() << endl;
    cout << "Hello " << p2.getName() << ", Your color is: " << p2.getColor() << endl;
    cout << "Hello " << p3.getName() << ", Your color is: " << p3.getColor() << endl;
    // RED player goes first, then BLUE, then GREEN
    firstTour(board);
    // each player places 2 settlements and 2 roads
    // each player gets 2 resources for each settlement and 1 resource for each city
}

void Catan::firstTour(Board &board)
{
    // each player place 2 settlements and 2 roads
    // RED player goes first
    cout << "Player 1, place your first settlement: ";
    int vertexNum;
    cin >> vertexNum;
    while (p1.placeSettlementFirst(board, vertexNum) == 0)
    {
        cout << "Invalid vertex, please try again" << endl;
        cin >> vertexNum;
    }
    cout << "Player 1, place your first road: ";
    int edgeNum;
    cin >> edgeNum;
    while (p1.placeRoad(board, edgeNum) == 0)
    {
        cout << "Invalid edge, please try again" << endl;
        cin >> edgeNum;
    }
    cout << "Player 1, place your second settlement: ";
    cin >> vertexNum;
    while (p1.placeSettlementFirst(board, vertexNum) == 0)
    {
        cout << "Invalid vertex, please try again" << endl;
        cin >> vertexNum;
    }
    cout << "Player 1, place your second road: ";
    cin >> edgeNum;
    while (p1.placeRoad(board, edgeNum) == 0)
    {
        cout << "Invalid edge, please try again" << endl;
        cin >> edgeNum;
    }
    // BLUE player goes second
    cout << "Player 2, place your first settlement: ";
    cin >> vertexNum;
    while (p2.placeSettlementFirst(board, vertexNum) == 0)
    {
        cout << "Invalid vertex, please try again" << endl;
        cin >> vertexNum;
    }
    cout << "Player 2, place your first road: ";
    cin >> edgeNum;
    while (p2.placeRoad(board, edgeNum) == 0)
    {
        cout << "Invalid edge, please try again" << endl;
        cin >> edgeNum;
    }
    cout << "Player 2, place your second settlement: ";
    cin >> vertexNum;
    while (p2.placeSettlementFirst(board, vertexNum) == 0)
    {
        cout << "Invalid vertex, please try again" << endl;
        cin >> vertexNum;
    }
    // p2.addResource(board.getVertex(vertexNum)->getResource(),1);
    cout << "Player 2, place your second road: ";
    cin >> edgeNum;
    while (p2.placeRoad(board, edgeNum) == 0)
    {
        cout << "Invalid edge, please try again" << endl;
        cin >> edgeNum;
    }
    // GREEN player goes third
    cout << "Player 3, place your first settlement: ";
    cin >> vertexNum;
    while (p3.placeSettlementFirst(board, vertexNum) == 0)
    {
        cout << "Invalid vertex, please try again" << endl;
        cin >> vertexNum;
    }
    cout << "Player 3, place your first road: ";
    cin >> edgeNum;
    while (p3.placeRoad(board, edgeNum) == 0)
    {
        cout << "Invalid edge, please try again" << endl;
        cin >> edgeNum;
    }
    cout << "Player 3, place your second settlement: ";
    cin >> vertexNum;
    while (p3.placeSettlementFirst(board, vertexNum) == 0)
    {
        cout << "Invalid vertex, please try again" << endl;
        cin >> vertexNum;
    }
    cout << "Player 3, place your second road: ";
    cin >> edgeNum;
    while (p3.placeRoad(board, edgeNum) == 0)
    {
        cout << "Invalid edge, please try again" << endl;
        cin >> edgeNum;
    }
}

void Catan::Dice7()
{
    // cout << "Dice rolled a 7" << endl;
    // all players with more than 7 cards must discard half of their cards
    int p1_resources = p1.getResources()[1] + p1.getResources()[2] + p1.getResources()[3] + p1.getResources()[4] + p1.getResources()[5];
    int p2_resources = p2.getResources()[1] + p2.getResources()[2] + p2.getResources()[3] + p2.getResources()[4] + p2.getResources()[5];
    int p3_resources = p3.getResources()[1] + p3.getResources()[2] + p3.getResources()[3] + p3.getResources()[4] + p3.getResources()[5];
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
        cout << "Player 1, it's your turn" << endl;
        turn(board, p1, p2, p3);
        // player 2's turn
        cout << "Player 2, it's your turn" << endl;
        turn(board, p2, p1, p3);
        // player 3's turn
        cout << "Player 3, it's your turn" << endl;
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
    int choice;
    cout << player.getName() << " ,you have the following resources:" << endl;
    player.printResources();
    cout << "Would you like to use a dev card before rolling the dice?" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    cin >> choice;
    if (choice == 1)
    {
        // player.playDevCard();
        // end turn
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
        cin >> choice;
        if (choice == 1)
        {
            cout << "What would you like to build?" << endl;
            cout << "1. Settlement" << endl;
            cout << "2. Road" << endl;
            cout << "3. City" << endl;
            cout << "4. Development card" << endl;
            cin >> choice;
            if (choice == 1)
            {
                // 🌲🧱 🌾🪨 🐑

                cout << "cost of building a settlement is: 1 brick 🧱, 1 wood 🌲, 1 wheat 🌾, 1 sheep 🐑" << endl;
                // check if player has enough resources
                // if they do, build the settlement
                // if they don't, print an error message
                if (player.getResources()[1] < 1 || player.getResources()[2] < 1 || player.getResources()[3] < 1 || player.getResources()[4] < 1)
                {
                    cout << "You do not have enough resources to build a settlement" << endl;
                }
                else
                {
                    cout << "Enter the vertex number to place your settlement: ";
                    int vertexNum;
                    cin >> vertexNum;
                    while (player.placeSettlement(board, vertexNum) == 0)
                    {
                        cout << "Invalid vertex, please try again" << endl;
                        cin >> vertexNum;
                    }
                    player.getResources()[1]--;
                    player.getResources()[2]--;
                    player.getResources()[3]--;
                    player.getResources()[4]--;
                }
            }
            else if (choice == 2)
            {
                cout << "cost of building a road is 1 brick 🧱, 1 wood 🌲" << endl;
                // check if player has enough resources
                // if they do, build the road
                // if they don't, print an error message
                if (player.getResources()[1] < 1 || player.getResources()[2] < 1)
                {
                    cout << "You do not have enough resources to build a road" << endl;
                }
                else
                {
                    cout << "Enter the edge number to place your road: ";
                    int edgeNum;
                    cin >> edgeNum;
                    while (player.placeRoad(board, edgeNum) == 0)
                    {
                        cout << "Invalid edge, please try again" << endl;
                        cin >> edgeNum;
                    }
                    player.getResources()[1]--;
                    player.getResources()[2]--;
                }
            }
            else if (choice == 3)
            {
                cout << "cost of building a city is 3 iron 🪨, 2 wheat 🌾" << endl;
                // check if player has enough resources
                // if they do, build the city
                // if they don't, print an error message
                if (player.getResources()[5] < 3 || player.getResources()[4] < 2)
                {
                    cout << "You do not have enough resources to build a city" << endl;
                }
                else
                {
                    cout << "Enter the vertex number to place your city: ";
                    int vertexNum;
                    cin >> vertexNum;
                    while (player.placeCity(board, vertexNum) == 0)
                    {
                        cout << "Invalid vertex, please try again" << endl;
                        cin >> vertexNum;
                    }
                    player.getResources()[5] -= 3;
                    player.getResources()[4] -= 2;
                }
            }
            else if (choice == 4)
            {
                cout << "cost of buying a development card is 1 iron 🪨, 1 sheep 🐑, 1 wheat 🌾" << endl;
                //  player.buyDevelopmentCard();
            }
        }
        else if (choice == 2)
        {
            // player trade
            pair<map<int, int>, map<int, int>> trade = player.trade();
            map<int, int> wants_give = trade.first;  // what player want to give
            map<int, int> wants_take = trade.second; // what player want to take
            // try to take from player 1
            Player *player_to_take = nullptr;
            if (player2.getResources()[1] - wants_take[1] >= 0 && player2.getResources()[2] - wants_take[2] >= 0 && player2.getResources()[3] - wants_take[3] >= 0 && player2.getResources()[4] - wants_take[4] >= 0 && player2.getResources()[5] - wants_take[5] >= 0)
            {
                cout << "Player " << player2.getName() << " do you want to trade with " << player.getName() << "?" << endl;
                cout << "1. Yes" << endl;
                cout << "2. No" << endl;
                cin >> choice;
                if (choice == 1)
                {
                    player_to_take = &player2;
                }
            }
            if (player3.getResources()[1] - wants_take[1] >= 0 && player3.getResources()[2] - wants_take[2] >= 0 && player3.getResources()[3] - wants_take[3] >= 0 && player3.getResources()[4] - wants_take[4] >= 0 && player3.getResources()[5] - wants_take[5] >= 0)
            {
                cout << "Player " << player3.getName() << " do you want to trade with " << player.getName() << "?" << endl;
                cout << "1. Yes" << endl;
                cout << "2. No" << endl;
                cin >> choice;
                if (choice == 1)
                {
                    player_to_take = &player3;
                }
            }
            if (player_to_take == nullptr)
            {
                cout << "No player has the resources you want" << endl;
            }
            else
            {
                //  cout << "before trade" << endl;
                // player.printResources();
                // cout << "before trade" << endl;
                // player_to_take -> printResources();

                player_to_take->addResource(1, wants_give[1]);
                player_to_take->addResource(2, wants_give[2]);
                player_to_take->addResource(3, wants_give[3]);
                player_to_take->addResource(4, wants_give[4]);
                player_to_take->addResource(5, wants_give[5]);
                player.addResource(1, wants_take[1]);
                player.addResource(2, wants_take[2]);
                player.addResource(3, wants_take[3]);
                player.addResource(4, wants_take[4]);
                player.addResource(5, wants_take[5]);

                // update the resources of the players after decreasing the resources
                player_to_take->getResources()[1] -= wants_take[1];
                player_to_take->getResources()[2] -= wants_take[2];
                player_to_take->getResources()[3] -= wants_take[3];
                player_to_take->getResources()[4] -= wants_take[4];
                player_to_take->getResources()[5] -= wants_take[5];
                player.getResources()[1] -= wants_give[1];
                player.getResources()[2] -= wants_give[2];
                player.getResources()[3] -= wants_give[3];
                player.getResources()[4] -= wants_give[4];
                player.getResources()[5] -= wants_give[5];
            }
            // cout << "after trade" << endl;
            // player.printResources();
            // cout << "after trade" << endl;
            // player_to_take -> printResources();
        }
    }
    else if (choice == 3)
    {
        player.endTurn();
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
    // playerDice = dice;
    cout << "Dice rolled: " << dice << endl;
    for (int i = 0; i < board.getTiles()->size(); i++)
    {
        if (board.getTiles()->at(i).getNumber() == dice)
        {
            int resource = board.getTiles()->at(i).getResource();
            // cout << "Resource: " << resource << endl;
            for (int j = 0; j < board.getTiles()->at(i).getVertices().size(); j++)
            {
                if (board.getTiles()->at(i).getVertices()[j]->getHasSettlement() == 1)
                {
                    // add resource to all player that has a settlement on the tile
                    if (board.getTiles()->at(i).getVertices()[j]->getColor() == p1.getColor())
                    {
                        p1.addResource(resource, 1);
                        cout << "Player 1 got " << resource << " from settlement" << endl;
                    }
                    if (board.getTiles()->at(i).getVertices()[j]->getColor() == p2.getColor())
                    {
                        p2.addResource(resource, 1);
                        cout << "Player 2 got " << resource << " from settlement" << endl;
                    }
                    if (board.getTiles()->at(i).getVertices()[j]->getColor() == p3.getColor())
                    {
                        p3.addResource(resource, 1);
                        cout << "Player 3 got " << resource << " from settlement" << endl;
                    }
                }
                if (board.getTiles()->at(i).getVertices()[j]->getHasCity() == 1)
                {
                    if (board.getTiles()->at(i).getVertices()[j]->getColor() == p1.getColor())
                    {
                        p1.addResource(resource, 2);
                        cout << "Player 1 got " << resource << " from city" << endl;
                    }
                    if (board.getTiles()->at(i).getVertices()[j]->getColor() == p2.getColor())
                    {
                        p2.addResource(resource, 2);
                        cout << "Player 2 got " << resource << " from city" << endl;
                    }
                    if (board.getTiles()->at(i).getVertices()[j]->getColor() == p3.getColor())
                    {
                        p3.addResource(resource, 2);
                        cout << "Player 3 got " << resource << " from city" << endl;
                    }
                }
            }
        }
    }
}
