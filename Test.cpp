#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Catan.hpp"
#include "DevCard.hpp"

using namespace std;

TEST_CASE("place settlement first")
{
    SUBCASE("place in first round")
    {
        Board board;
        Player player1("A");
        player1.setColor(RED);
        Player player2("B");
        player2.setColor(BLUE);
        Player player3("C");
        player3.setColor(GREEN);
        Catan catan(player1, player2, player3, board);
        CHECK(player1.placeSettlementFirst(board, 0) == true);
        CHECK(board.getVertex(0)->getColor() == player1.getColor());
        CHECK(player1.getPoints() == 1);
        CHECK(player2.placeSettlementFirst(board, 0) == false);
        CHECK(player3.placeSettlementFirst(board, 0) == false);
    }

    SUBCASE("place on another settlemnent")
    {
        Board board;
        Player player1("A");
        player1.setColor(RED);
        Player player2("B");
        player2.setColor(BLUE);
        Player player3("C");
        player3.setColor(GREEN);
        Catan catan(player1, player2, player3, board);
        CHECK(player1.placeSettlementFirst(board, 0) == true);
        CHECK(board.getVertex(0)->getColor() == player1.getColor());
        CHECK(player2.placeSettlementFirst(board, 0) == false);
        CHECK(board.getVertex(0)->getColor() != player2.getColor());
    }

    SUBCASE("place second settelment near the first one")
    {
        Board board;
        Player player1("A");
        player1.setColor(RED);
        Player player2("B");
        player2.setColor(BLUE);
        Player player3("C");
        player3.setColor(GREEN);
        Catan catan(player1, player2, player3, board);
        CHECK(player1.placeSettlementFirst(board, 8) == true);
        CHECK(player1.placeSettlementFirst(board, 13) == false); // 8 vertex is neighbor to 13 vertex
        CHECK(board.getVertex(1)->getColor() == 0);
        CHECK(player1.getPoints() == 1);
    }
    SUBCASE("place player1 settelment near player2 settelment is not allowed")
    {
        Board board;
        Player player1("A");
        player1.setColor(RED);
        Player player2("B");
        player2.setColor(BLUE);
        Player player3("C");
        player3.setColor(GREEN);
        Catan catan(player1, player2, player3, board);
        CHECK(player1.placeSettlementFirst(board, 0) == true);
        CHECK(player2.placeSettlementFirst(board, 4) == false); // 0 vertex is neighbor to 4 vertex
        CHECK(board.getVertex(2)->getColor() == 0);
        CHECK(player1.getPoints() == 1);
    }
}

TEST_CASE("place settelment after first round")
{
    SUBCASE("player1 place a settlement after first round")
    {
        Board board;
        Player player1("A");
        player1.setColor(RED);
        Player player2("B");
        player2.setColor(BLUE);
        Player player3("C");
        player3.setColor(GREEN);
        Catan catan(player1, player2, player3, board);
        CHECK(player1.placeSettlementFirst(board, 0) == true);
        CHECK(player1.placeRoad(board, 0) == true);
        CHECK(player1.placeSettlement(board, 4) == false);  // place not in continue road
        CHECK(player1.placeSettlement(board, 8) == false);  // place not in continue road
        CHECK(player1.placeSettlement(board, 12) == false); // place not in continue road
        CHECK(player1.placeSettlement(board, 23) == false); // place not in continue road
        CHECK(player1.placeSettlement(board, 7) == false);  // place not in continue road
        CHECK(player1.placeRoad(board, 6) == true);         // 6 edge is neighbor to 0 edge
        CHECK(player1.placeSettlement(board, 7) == true);   // 7 vertex is continue 2 roads
        CHECK(board.getVertex(7)->getColor() == player1.getColor());
        CHECK(player1.getPoints() == 2);
    }

    SUBCASE("player2 place a settlement after first round")
    {
        Board board;
        Player player1("A");
        player1.setColor(RED);
        Player player2("B");
        player2.setColor(BLUE);
        Player player3("C");
        player3.setColor(GREEN);
        Catan catan(player1, player2, player3, board);
        CHECK(player1.placeSettlementFirst(board, 0) == true);
        CHECK(player1.placeRoad(board, 0) == true);
        CHECK(player1.placeRoad(board, 6) == true);
        CHECK(player2.placeSettlement(board, 0) == false); // place not in continue road
        CHECK(player2.placeSettlement(board, 3) == false); // place not in continue road
        CHECK(player2.placeSettlement(board, 7) == false); // place not in continue road
        CHECK(player2.placeSettlement(board, 4) == false); // place not in continue road
        CHECK(board.getVertex(0)->getColor() == player1.getColor());
        CHECK(board.getVertex(3)->getColor() == 0);
        CHECK(board.getVertex(7)->getColor() == 0);
        CHECK(board.getVertex(4)->getColor() == 0);
    }

    SUBCASE(" 3 players place a settlement after first round secssfully")
    {
        Board board;
        Player player1("A");
        player1.setColor(RED);
        Player player2("B");
        player2.setColor(BLUE);
        Player player3("C");
        player3.setColor(GREEN);
        Catan catan(player1, player2, player3, board);
        // place 2 settlements and 2 roads for player1
        CHECK(player1.placeSettlementFirst(board, 0) == true);
        CHECK(player1.placeRoad(board, 0) == true);
        CHECK(player1.placeRoad(board, 6) == true);
        CHECK(player1.placeSettlementFirst(board, 12) == true);
        // place 2 settlements and 2 roads for player2
        CHECK(player2.placeSettlementFirst(board, 2) == true);
        CHECK(player2.placeRoad(board, 4) == true);
        CHECK(player2.placeRoad(board, 8) == true);
        CHECK(player2.placeSettlementFirst(board, 9) == true);
        // place 2 settlements and 2 roads for player3
        CHECK(player3.placeSettlementFirst(board, 16) == true);
        CHECK(player3.placeRoad(board, 18) == true);
        CHECK(player3.placeRoad(board, 23) == true);
        CHECK(player3.placeSettlementFirst(board, 43) == true);
        // check if the 3 players can place a settlement
        // player1
        CHECK(board.getVertex(0)->getColor() == board.getVertex(12)->getColor());
        CHECK(board.getVertex(12)->getColor() == player1.getColor());
        CHECK(player1.placeSettlement(board, 7) == true); // near 2 roads
        CHECK(board.getVertex(0)->getColor() == player1.getColor());

        // player2
        CHECK(board.getVertex(2)->getColor() == board.getVertex(9)->getColor());
        CHECK(board.getVertex(9)->getColor() == player2.getColor());

        CHECK(player2.placeSettlement(board, 14) == false); // not near any road, near to another settlement
        CHECK(player2.placeSettlement(board, 15) == false); // not near any road, near to another settlement

        // player3
        CHECK(board.getVertex(16)->getColor() == board.getVertex(43)->getColor());
        CHECK(board.getVertex(43)->getColor() == player3.getColor());

        CHECK(player3.placeSettlement(board, 11) == false); // need 2 roads
        CHECK(player3.placeSettlement(board, 23) == false); // need 2 roads
        CHECK(player3.placeRoad(board, 33) == true);
        CHECK(player3.placeSettlement(board, 27) == true); // near 2 roads
    }
}

TEST_CASE("place city")
{
    SUBCASE("place city on settelement from first round")
    {
        Board board;
        Player player1("A");
        player1.setColor(RED);
        Player player2("B");
        player2.setColor(BLUE);
        Player player3("C");
        player3.setColor(GREEN);
        Catan catan(player1, player2, player3, board);
        CHECK(player1.placeSettlementFirst(board, 0) == true);
        CHECK(player1.placeRoad(board, 0) == true);
        CHECK(player1.placeRoad(board, 6) == true);
        CHECK(player1.placeCity(board, 0) == true); // place city on first settlement
        CHECK(board.getVertex(0)->getColor() == player1.getColor());
        CHECK(player1.getPoints() == 3);
    }
    SUBCASE("place city after first round")
    {
        Board board;
        Player player1("A");
        player1.setColor(RED);
        Player player2("B");
        player2.setColor(BLUE);
        Player player3("C");
        player3.setColor(GREEN);
        Catan catan(player1, player2, player3, board);
        CHECK(player1.placeSettlementFirst(board, 0) == true);
        CHECK(player1.placeRoad(board, 0) == true);
        CHECK(player1.placeRoad(board, 6) == true);
        CHECK(player1.placeRoad(board, 10) == true);
        CHECK(player1.placeRoad(board, 18) == true);
        CHECK(player1.placeCity(board, 16) == false); // there is no settlement in 16 vertex
        CHECK(player1.placeSettlement(board, 16) == true);
        CHECK(player1.placeCity(board, 16) == true); // now there is a settlement in 16 vertex
        CHECK(player1.getPoints() == 4);
    }
    SUBCASE("place city is not allowed if there is already a city in the vertex")
    {
        Board board;
        Player player1("A");
        player1.setColor(RED);
        Player player2("B");
        player2.setColor(BLUE);
        Player player3("C");
        player3.setColor(GREEN);
        Catan catan(player1, player2, player3, board);
        CHECK(player1.placeSettlementFirst(board, 0) == true);
        CHECK(player1.placeRoad(board, 0) == true);
        CHECK(player1.placeRoad(board, 6) == true);
        CHECK(player1.placeSettlement(board, 7) == true);
        CHECK(player1.placeCity(board, 7) == true);  // there is a settlement in 7 vertex
        CHECK(player1.placeCity(board, 7) == false); // its already a city in 7 vertex
        CHECK(player1.getPoints() == 4);
    }

    SUBCASE("place city is not allowed if there is no settlement in the vertex")
    {
        Board board;
        Player player1("A");
        player1.setColor(RED);
        Player player2("B");
        player2.setColor(BLUE);
        Player player3("C");
        player3.setColor(GREEN);
        Catan catan(player1, player2, player3, board);
        CHECK(player1.placeCity(board, 0) == false); // there is no settlement in 0 vertex
        CHECK(player1.getPoints() == 0);
    }

    SUBCASE("place city is not allowed on settlement from another player")
    {
        Board board;
        Player player1("A");
        player1.setColor(RED);
        Player player2("B");
        player2.setColor(BLUE);
        Player player3("C");
        player3.setColor(GREEN);
        Catan catan(player1, player2, player3, board);
        CHECK(player1.placeSettlementFirst(board, 0) == true);
        CHECK(player1.placeRoad(board, 0) == true);
        CHECK(player1.placeRoad(board, 6) == true);
        CHECK(player1.placeSettlement(board, 7) == true);
        CHECK(player2.placeSettlementFirst(board, 2) == true);
        CHECK(player2.placeCity(board, 0) == false); // there is a settlement in 0 vertex but its not player2's
        CHECK(player2.placeCity(board, 7) == false); // there is a settlement in 7 vertex but its not player2's
        CHECK(player1.placeCity(board, 0) == true);  // there is a settlement in 0 vertex and its player2's
        CHECK(player1.placeCity(board, 7) == true);  // there is a settlement in 7 vertex and its player2's
        CHECK(player1.getPoints() == 6);             // 2 points for each city
        CHECK(player2.getPoints() == 1);             // 1 point for each settlement
    }
}

TEST_CASE("Enough resources to buy a settlement, road, or city")
{
    SUBCASE("player has enough resources to place a settlement")
    {
        Board board;
        Player player1("A");
        player1.setColor(RED);
        // costOfSettlement = {WOOD, BRICK, SHEEP, WHEAT};

        // place settlement on vertex 0 and 2 roads for free
        player1.placeSettlementFirst(board, 0);
        player1.placeRoad(board, 0);
        player1.placeRoad(board, 6);

        player1.addResource(WOOD, 1);
        player1.addResource(BRICK, 1);
        player1.addResource(SHEEP, 1);
        player1.addResource(WHEAT, 1);

        // Save the original buffer of std::cin
        std::streambuf *cinBuffer = std::cin.rdbuf();
        // Create a new input stream with the input you want to test
        std::istringstream testInput("7"); // Redirect std::cin to your input stream
        std::cin.rdbuf(testInput.rdbuf());

        CHECK(player1.placeSettlementUtil(board) == true); // buy settlement and place on vertex 7
        CHECK(board.getVertex(0)->getColor() == player1.getColor());
    }

    SUBCASE("player doesn't have enough resources to place a settlement")
    {
        cout << "---------------------------------------------------------" << endl;
        Board board;
        Player player1("A");
        player1.setColor(RED);
        Catan catan(player1, player1, player1, board);
        CHECK(player1.placeSettlementUtil(board) == false);
        CHECK(board.getVertex(0)->getColor() == 0);
        cout << "---------------------------------------------------------" << endl;
    }

    SUBCASE("player has enough resources to place a road")
    {
        cout << "---------------------------------------------------------" << endl;
        Board board;
        Player player1("A");
        player1.setColor(RED);
        Catan catan(player1, player1, player1, board);
        // cost of road is 1 wood and 1 brick
        player1.addResource(WOOD, 1);
        player1.addResource(BRICK, 1);

        CHECK(player1.placeSettlementFirst(board, 0) == true);
        // Save the original buffer of std::cin
        std::streambuf *cinBuffer = std::cin.rdbuf();
        // Create a new input stream with the input you want to test
        std::istringstream testInput("0"); // Redirect std::cin to your input stream
        std::cin.rdbuf(testInput.rdbuf());
        CHECK(player1.placeRoadUtil(board) == true); // buy road and place on edge 0
        CHECK(board.getEdge(0)->getPlayerColor() == player1.getColor());
        cout << "---------------------------------------------------------" << endl;
    }
    SUBCASE("player doesn't have enough resources to place a road")
    {
        cout << "---------------------------------------------------------" << endl;

        Board board;
        Player player1("A");
        player1.setColor(RED);
        player1.printResources();
        Catan catan(player1, player1, player1, board);
        CHECK(player1.placeRoadUtil(board) == false);
        CHECK(board.getEdge(0)->getPlayerColor() == 0);
        cout << "---------------------------------------------------------" << endl;
    }

    SUBCASE("player has enough resources to place a city")
    {
        cout << "---------------------------------------------------------" << endl;
        Board board;
        Player player1("A");
        player1.setColor(RED);
        Catan catan(player1, player1, player1, board);
        // cost of city is 3 iron and 2 wheat
        player1.addResource(IRON, 3);
        player1.addResource(WHEAT, 2);

        CHECK(player1.placeSettlementFirst(board, 0) == true);
        CHECK(player1.placeRoad(board, 0) == true);
        CHECK(player1.placeRoad(board, 6) == true);
        // Save the original buffer of std::cin
        std::streambuf *cinBuffer = std::cin.rdbuf();
        // Create a new input stream with the input you want to test
        std::istringstream testInput("0"); // Redirect std::cin to your input stream
        std::cin.rdbuf(testInput.rdbuf());
        CHECK(player1.placeCityUtil(board) == true); // buy city and place on vertex 0
        CHECK(board.getVertex(0)->getColor() == player1.getColor());
        cout << "---------------------------------------------------------" << endl;
    }

    SUBCASE("player doesn't have enough resources to place a city")
    {
        cout << "---------------------------------------------------------" << endl;
        Board board;
        Player player1("A");
        player1.setColor(RED);
        Catan catan(player1, player1, player1, board);
        CHECK(player1.placeCityUtil(board) == false);
        CHECK(board.getVertex(0)->getColor() == 0);
        cout << "---------------------------------------------------------" << endl;
    }
}

TEST_CASE("Buy a development card")
{
    SUBCASE("player has enough resources to buy a development card")
    {
        cout << "---------------------------------------------------------" << endl;
        Board board;
        Player player1("A");
        player1.setColor(RED);
        Catan catan(player1, player1, player1, board);
        // cost of development card is 1 iron, 1 wheat, 1 sheep
        player1.addResource(IRON, 1);
        player1.addResource(WHEAT, 1);
        player1.addResource(SHEEP, 1);
        CHECK(catan.buyDevCard(player1) == true);
        CHECK(player1.getDevCards().size() == 1);
        cout << "---------------------------------------------------------" << endl;
    }

    SUBCASE("player doesn't have enough resources to buy a development card")
    {
        cout << "---------------------------------------------------------" << endl;
        Board board;
        Player player1("A");
        player1.setColor(RED);
        Catan catan(player1, player1, player1, board);
        CHECK(catan.buyDevCard(player1) == false);
        CHECK(player1.getDevCards().size() == 0);
        cout << "---------------------------------------------------------" << endl;
    }
}

TEST_CASE("Trade resources")
{
    SUBCASE("player has enough resources to trade")
    {
        cout << "trade--------------------------------------------------------" << endl;
        Board board;
        Player player1("A");
        Player player2("B");
        Player player3("C");
        player1.setColor(RED);
        player2.setColor(BLUE);
        player3.setColor(GREEN);
        Catan catan(player1, player1, player1, board);
        player1.addResource(WOOD, 1);
        player1.addResource(BRICK, 1);
        player1.addResource(SHEEP, 0);
        player1.addResource(WHEAT, 0);
        player1.addResource(IRON, 0);

        player2.addResource(WOOD, 0);
        player2.addResource(BRICK, 0);
        player2.addResource(SHEEP, 0);
        player2.addResource(WHEAT, 0);
        player2.addResource(IRON, 1);

        // Save the original buffer of std::cin
        std::streambuf *cinBuffer = std::cin.rdbuf();
        // Create a new input stream with the input you want to test
        std::istringstream testInput("1\n1\n1\n0\n0\n0\n0\n0\n0\n0\n1\n1\n"); // Redirect std::cin to your input stream
        std::cin.rdbuf(testInput.rdbuf());

        // "1\n1\n1\n0\n0\n0\n0\n0\n0\n0\n1\n1\n"
        CHECK(catan.resourceTrade(player1, player2, player3) == true);
        CHECK(player1.getResources()[WOOD] == 0);
        CHECK(player1.getResources()[BRICK] == 0);
        CHECK(player1.getResources()[IRON] == 1);

        CHECK(player2.getResources()[WOOD] == 1);
        CHECK(player2.getResources()[BRICK] == 1);
        CHECK(player2.getResources()[IRON] == 0);
        cout << "---------------------------------------------------------" << endl;
    }

     SUBCASE("No player wants to trade")
    {
        cout << "trade--------------------------------------------------------" << endl;
        Board board;
        Player player1("A");
        Player player2("B");
        Player player3("C");
        player1.setColor(RED);
        player2.setColor(BLUE);
        player3.setColor(GREEN);
        Catan catan(player1, player1, player1, board);
        player1.addResource(WOOD, 1);
        player1.addResource(BRICK, 1);
        player1.addResource(SHEEP, 0);
        player1.addResource(WHEAT, 0);
        player1.addResource(IRON, 0);

        player2.addResource(WOOD, 0);
        player2.addResource(BRICK, 0);
        player2.addResource(SHEEP, 0);
        player2.addResource(WHEAT, 0);
        player2.addResource(IRON, 1);
       
        // Save the original buffer of std::cin
        std::streambuf *cinBuffer = std::cin.rdbuf();
        // Create a new input stream with the input you want to test
        std::istringstream testInput("1\n1\n1\n0\n0\n0\n0\n0\n0\n0\n1\n2\n"); // Redirect std::cin to your input stream
        std::cin.rdbuf(testInput.rdbuf());

        // "1\n1\n1\n0\n0\n0\n0\n0\n0\n0\n1\n1\n"
        CHECK(catan.resourceTrade(player1, player2, player3) == false);
        CHECK(player1.getResources()[WOOD] == 1);
        CHECK(player1.getResources()[BRICK] == 1);
        CHECK(player1.getResources()[IRON] == 0);
        cout << "---------------------------------------------------------" << endl;
    }

    SUBCASE("player2 doesn't have resources that player1 want")
    {
        cout << "trade--------------------------------------------------------" << endl;
        Board board;
        Player player1("A");
        Player player2("B");
        Player player3("C");
        player1.setColor(RED);
        player2.setColor(BLUE);
        player3.setColor(GREEN);
        Catan catan(player1, player1, player1, board);
        player1.addResource(WOOD, 1);
        player1.addResource(BRICK, 1);
        player1.addResource(SHEEP, 0);
        player1.addResource(WHEAT, 0);
        player1.addResource(IRON, 0);

        player2.addResource(WOOD, 0);
        player2.addResource(BRICK, 0);
        player2.addResource(SHEEP, 0);
        player2.addResource(WHEAT, 0);
        player2.addResource(IRON, 0);

         // Save the original buffer of std::cin
        std::streambuf *cinBuffer = std::cin.rdbuf();
        // Create a new input stream with the input you want to test
        std::istringstream testInput("1\n1\n1\n0\n0\n0\n0\n0\n0\n0\n1\n"); // Redirect std::cin to your input stream
        std::cin.rdbuf(testInput.rdbuf());

        CHECK(catan.resourceTrade(player1, player2, player3) == false);
        cout << "---------------------------------------------------------" << endl;
    }
    
}

TEST_CASE("Using dev cards")
{
    SUBCASE("Have no dev cards")
    {
        cout << "dev card--------------------------------------------------------" << endl;
        Board board;
        Player player1("A");
        Player player2("B");
        Player player3("C");
        vector<Player *> players;
        players.push_back(&player1);
        players.push_back(&player2);
        players.push_back(&player3);
        player1.setColor(RED);
        player2.setColor(BLUE);
        player3.setColor(GREEN);
        Catan catan(player1, player2, player3, board);
        CHECK(player1.playDevCard(board, players) == 0);
    }
    SUBCASE("player has 3 knight card")
    {
        cout << "dev card--------------------------------------------------------" << endl;
        Board board;
        Player player1("A");
        Player player2("B");
        Player player3("C");
        vector<Player *> players;
        players.push_back(&player1);
        players.push_back(&player2);
        players.push_back(&player3);
        player1.setColor(RED);
        player2.setColor(BLUE);
        player3.setColor(GREEN);
        Catan catan(player1, player2, player3, board);
        unique_ptr<DevCard> card1 = make_unique<Knight>();
        unique_ptr<DevCard> card2 = make_unique<Knight>();
        unique_ptr<DevCard> card3 = make_unique<Knight>();
        player1.addCard(move(card1));
        player1.addCard(move(card2));
        player1.addCard(move(card3));
        player1.printCards();
          // Save the original buffer of std::cin
        std::streambuf *cinBuffer = std::cin.rdbuf();
        // Create a new input stream with the input you want to test
        std::istringstream testInput("2\n"); // Redirect std::cin to your input stream
        std::cin.rdbuf(testInput.rdbuf());
        CHECK(player1.playDevCard(board, players) == 2); // 2 its the return value if play knight sucess
    }

    SUBCASE("player has less then 3 knight card")
    {
        cout << "dev card--------------------------------------------------------" << endl;
        Board board;
        Player player1("A");
        Player player2("B");
        Player player3("C");
        vector<Player *> players;
        players.push_back(&player1);
        players.push_back(&player2);
        players.push_back(&player3);
        player1.setColor(RED);
        player2.setColor(BLUE);
        player3.setColor(GREEN);
        Catan catan(player1, player2, player3, board);
        unique_ptr<DevCard> card1 = make_unique<Knight>();
        unique_ptr<DevCard> card2 = make_unique<Knight>();
        unique_ptr<DevCard> card3 = make_unique<Knight>();
        player1.addCard(move(card1));
        player1.addCard(move(card2));
        player1.printCards();
          // Save the original buffer of std::cin
        std::streambuf *cinBuffer = std::cin.rdbuf();
        // Create a new input stream with the input you want to test
        std::istringstream testInput("2\n"); // Redirect std::cin to your input stream
        std::cin.rdbuf(testInput.rdbuf());
        CHECK(player1.playDevCard(board, players) == 6); // return 6 if player has less then 3 knight card
    }

    SUBCASE ("Use victory point card")
    {
        Board board;
        Player player1("A");
        Player player2("B");
        Player player3("C");
        vector<Player *> players;
        players.push_back(&player1);
        players.push_back(&player2);
        players.push_back(&player3);
        player1.setColor(RED);
        player2.setColor(BLUE);
        player3.setColor(GREEN);
        Catan catan(player1, player2, player3, board);
        unique_ptr<DevCard> card1 = make_unique<VictoryPoint>();
        player1.addCard(move(card1));
        player1.printCards();
          // Save the original buffer of std::cin
        std::streambuf *cinBuffer = std::cin.rdbuf();
        // Create a new input stream with the input you want to test
        std::istringstream testInput("1\n"); // Redirect std::cin to your input stream
        std::cin.rdbuf(testInput.rdbuf());
        CHECK(player1.playDevCard(board, players) == 1); // return 3 if play victory point card
        CHECK(player1.getPoints() == 1);
    }

    SUBCASE("Use road building card")
    {
        cout << "dev card--------------------------------------------------------" << endl;
        Board board;
        Player player1("A");
        Player player2("B");
        Player player3("C");
        vector<Player *> players;
        players.push_back(&player1);
        players.push_back(&player2);
        players.push_back(&player3);
        player1.setColor(RED);
        player2.setColor(BLUE);
        player3.setColor(GREEN);
        player1.placeSettlementFirst(board, 0);
        Catan catan(player1, player2, player3, board);
        unique_ptr<DevCard> card1 = make_unique<RoadBuilding>();
        player1.addCard(move(card1));
        player1.printCards();
          // Save the original buffer of std::cin
        std::streambuf *cinBuffer = std::cin.rdbuf();
        // Create a new input stream with the input you want to test
        std::istringstream testInput("3\n0\n6\n"); // Redirect std::cin to your input stream
        std::cin.rdbuf(testInput.rdbuf());
        CHECK(player1.playDevCard(board, players) == 3); // return 3 if play road building card
        CHECK(board.getEdge(0)->getPlayerColor() == player1.getColor());
        CHECK(board.getEdge(6)->getPlayerColor() == player1.getColor());
    }

    SUBCASE( "Use year of plenty card")
    {
        cout << "dev card--------------------------------------------------------" << endl;
        Board board;
        Player player1("A");
        Player player2("B");
        Player player3("C");
        vector<Player *> players;
        players.push_back(&player1);
        players.push_back(&player2);
        players.push_back(&player3);
        player1.setColor(RED);
        player2.setColor(BLUE);
        player3.setColor(GREEN);
        Catan catan(player1, player2, player3, board);
        unique_ptr<DevCard> card1 = make_unique<YearOfPlenty>();
        player1.addCard(move(card1));
        player1.printCards();
          // Save the original buffer of std::cin
        std::streambuf *cinBuffer = std::cin.rdbuf();
        // Create a new input stream with the input you want to test
        std::istringstream testInput("4\n1\n2\n"); // Redirect std::cin to your input stream
        std::cin.rdbuf(testInput.rdbuf());
        CHECK(player1.getResources()[WOOD] == 0);
        CHECK(player1.getResources()[BRICK] == 0);
        CHECK(player1.getResources()[IRON] == 0);
        CHECK(player1.playDevCard(board, players) == 4); // return 4 if play year of plenty card
        CHECK(player1.getResources()[WOOD] == 1);
        CHECK(player1.getResources()[BRICK] == 1);
        CHECK(player1.getResources()[IRON] == 0);
    }

    SUBCASE("Use monopoly card")
    {
        Board board;
        Player player1("A");
        Player player2("B");
        Player player3("C");
        player1.setColor(RED);
        player2.setColor(BLUE);
        player3.setColor(GREEN);
        vector<Player *> players;
        players.push_back(&player1);
        players.push_back(&player2);
        players.push_back(&player3);
        Catan catan(player1, player1, player1, board);
        player1.addResource(WOOD, 1);
        player1.addResource(BRICK, 1);
        player1.addResource(SHEEP, 0);
        player1.addResource(WHEAT, 0);
        player1.addResource(IRON, 0);

        player2.addResource(WOOD, 0);
        player2.addResource(BRICK, 0);
        player2.addResource(SHEEP, 0);
        player2.addResource(WHEAT, 0);
        player2.addResource(IRON, 1);

        unique_ptr<DevCard> card1 = make_unique<Monopoly>();
        player1.addCard(move(card1));
        player1.printCards();
          // Save the original buffer of std::cin
        std::streambuf *cinBuffer = std::cin.rdbuf();
        // Create a new input stream with the input you want to test
        std::istringstream testInput("5\n5\n"); // Redirect std::cin to your input stream
        std::cin.rdbuf(testInput.rdbuf());
        CHECK(player1.getResources()[IRON] == 0);
        CHECK(player2.getResources()[IRON] == 1);
        CHECK(player1.playDevCard(board, players) == 5); // return 5 if play monopoly card
        CHECK(player1.getResources()[WOOD] == 1);
        CHECK(player1.getResources()[BRICK] == 1);
        CHECK(player1.getResources()[IRON] == 1);
        CHECK(player2.getResources()[IRON] == 0);

    }
}

//trade cards\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

//check if it needded vvvvvvvvvvvvvvvvvvvv

      











      

// SUBCASE("place near a settlement")
// {
//     Board board;
//     Player player1("A");
//     player1.setColor(RED);
//     Catan catan(player1, player1, player1, board);

//     // give player1 a resource to make him able to place a settlement
//     player1.addResource(WOOD, 3);
//     player1.addResource(BRICK, 3);
//     player1.addResource(SHEEP, 1);
//     player1.addResource(WHEAT, 1);
//     // cost of road is 1 wood and 1 brick
//     // cost of settlement is 1 wood, 1 brick, 1 sheep, 1 wheat

//     player1.placeSettlementFirst(board, 0);
//     // Save the original buffer of std::cin
//     std::streambuf *cinBuffer = std::cin.rdbuf();
//     // Create a new input stream with the input you want to test
//     std::istringstream testInput("0\n1\n"); // Redirect std::cin to your input stream
//     std::cin.rdbuf(testInput.rdbuf());
//     player1.printResources();

//     CHECK(player1.placeSettlementUtil(board) == true); // get input:0 ,check if player has enough resources to place a city
//     CHECK(player1.placeSettlementUtil(board) == true); // get input:1 , check if player has enough resources to place a city
//     CHECK(board.getVertex(1)->getColor() == player1.getColor());
//     CHECK(player1.getPoints() ==

TEST_CASE("place road")
{
    SUBCASE("place in first round")
    {
        Board board;
        Player player1("A");
        player1.setColor(RED);
        Player player2("B");
        player2.setColor(BLUE);
        Player player3("C");
        player3.setColor(GREEN);
        Catan catan(player1, player2, player3, board);
        CHECK(player1.placeSettlementFirst(board, 0) == true);
        CHECK(player1.placeRoad(board, 0) == true);
        CHECK(board.getEdge(0)->getPlayerColor() == player1.getColor());
        CHECK(player1.getPoints() == 1);
        CHECK(player2.placeRoad(board, 0) == false);
        CHECK(player3.placeRoad(board, 0) == false);
    }

    SUBCASE("place seconed road near the first one")
    {
        Board board;
        Player player1("A");
        player1.setColor(RED);
        Player player2("B");
        player2.setColor(BLUE);
        Player player3("C");
        player3.setColor(GREEN);
        Catan catan(player1, player2, player3, board);
        CHECK(player1.placeSettlementFirst(board, 0) == true);
        CHECK(player1.placeRoad(board, 0) == true);
        CHECK(player1.placeRoad(board, 6) == true); // 6 edge is neighbor to 0 edge
        CHECK(board.getEdge(6)->getPlayerColor() == player1.getColor());
    }

    SUBCASE("place player1 road near player2 road is not allowed")
    {
        Board board;
        Player player1("A");
        player1.setColor(RED);
        Player player2("B");
        player2.setColor(BLUE);
        Player player3("C");
        player3.setColor(GREEN);
        Catan catan(player1, player2, player3, board);
        CHECK(player1.placeSettlementFirst(board, 39) == true);
        CHECK(player1.placeRoad(board, 55) == true);
        CHECK(player2.placeRoad(board, 63) == false); // 55 edge is neighbor to 63 edge
        CHECK(board.getEdge(6)->getPlayerColor() == 0);
    }

    SUBCASE("place road without any settlements")
    {
        Board board;
        Player player1("A");
        player1.setColor(RED);
        Player player2("B");
        player2.setColor(BLUE);
        Player player3("C");
        player3.setColor(GREEN);
        Catan catan(player1, player2, player3, board);
        CHECK(player1.placeRoad(board, 0) == false);
    }

    SUBCASE("place near a road")
    {
        // Board board;
        // Player player1("A");
        // player1.setColor(RED);
        // Catan catan(player1, player1, player1, board);

        // // give player1 a resource to make him able to place a settlement
        // player1.addResource(WOOD, 3);
        // player1.addResource(BRICK, 3);
        // player1.addResource(SHEEP, 1);
        // player1.addResource(WHEAT, 1);
        // // cost of road is 1 wood and 1 brick
        // // cost of settlement is 1 wood, 1 brick, 1 sheep, 1 wheat

        // player1.placeSettlementFirst(board, 0);
        // // Save the original buffer of std::cin
        // std::streambuf *cinBuffer = std::cin.rdbuf();
        // // Create a new input stream with the input you want to test
        // std::istringstream testInput("0\n6\n7\n"); // Redirect std::cin to your input stream
        // std::cin.rdbuf(testInput.rdbuf());
        // player1.printResources();

        // CHECK(player1.placeRoadUtil(board) == true);       // get input:0 ,check if player has enough resources to place a city
        // CHECK(player1.placeSettlement(board, 7) == false); // there is 1 road between 0 and 7
        // CHECK(player1.placeRoadUtil(board) == true);       // get input:6 ,check if player has enough resources to place a city
        // CHECK(player1.placeSettlementUtil(board) == true); // get input:7 , check if player has enough resources to place a city
        // CHECK(board.getVertex(7)->getColor() == player1.getColor());
        // CHECK(player1.getPoints() == 2);
    }

    SUBCASE("place near a road that is not owned by the player")
    {
        //     Player player1(PlayerColor::RED);
        //     Player player2(PlayerColor::BLUE);
        //     Catan catan(player1, player2, player2);

        //     // give player2 a resource to make him able to place a settlement
        //     player2.add_resource(resource::WOOD, 1);
        //     player2.add_resource(resource::CLAY, 1);
        //     player2.add_resource(resource::SHEEP, 1);
        //     player2.add_resource(resource::WHEAT, 1);

        //     catan.place_settlement(34, player1, true);
        //     catan.place_road(41, player1, true);
        //     catan.place_road(40, player1, true);
        //     CHECK_THROWS(catan.place_settlement(33, player2));
    }

    SUBCASE("try to place in taken vertex")
    {
        //     Player player1(PlayerColor::RED);
        //     Player player2(PlayerColor::BLUE);
        //     Player player3(PlayerColor::YELLOW);
        //     Catan catan(player1, player2, player3);

        //     // give player2 a resource to make him able to place a settlement
        //     player2.add_resource(resource::WOOD, 1);
        //     player2.add_resource(resource::CLAY, 1);
        //     player2.add_resource(resource::SHEEP, 1);
        //     player2.add_resource(resource::WHEAT, 1);

        //     catan.place_settlement(8, player1, true);
        //     CHECK_THROWS(catan.place_settlement(8, player2));
        //     // check that the vertex is still owned by player1
        //     CHECK(catan.get_vertices()[8].get_owner() == &player1);
        //     // check that player2 still have the resources
        //     CHECK(player2.get_resource_count(resource::WOOD) == 1);
        //     CHECK(player2.get_resource_count(resource::CLAY) == 1);
        //     CHECK(player2.get_resource_count(resource::SHEEP) == 1);
        //     CHECK(player2.get_resource_count(resource::WHEAT) == 1);
    }

    SUBCASE("try to place near settlement")
    {
        //     Player player1(PlayerColor::RED);
        //     Player player2(PlayerColor::BLUE);
        //     Player player3(PlayerColor::YELLOW);
        //     Catan catan(player1, player2, player3);

        //     catan.place_settlement(8, player1, true);
        //     CHECK_THROWS(catan.place_settlement(4, player2, true));
        //     // check that the vertex is still owned by player1
        //     CHECK(catan.get_vertices()[8].get_owner() == &player1);
    }

    // SUBCASE("place without any resources") {
    //     Player player1(PlayerColor::RED);
    //     Player player2(PlayerColor::BLUE);
    //     Player player3(PlayerColor::YELLOW);
    //     Catan catan(player1, player2, player3);

    //     CHECK_THROWS(catan.place_settlement(8, player1));
    // }
}