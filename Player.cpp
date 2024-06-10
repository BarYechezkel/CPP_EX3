#include "Player.hpp"
#include <string>
#include <vector>
#include "Board.hpp"
using namespace std;

int Player::rollDice(Board &board)
{
    // return number between 2 and 12
    int dice = rand() % 11 + 2;
    playerDice = dice;
    cout << "Dice rolled: " << dice << endl;
    for (int i = 0; i < board.getTiles()->size(); i++)
    {
        if (board.getTiles()->at(i).getNumber() == dice)
        {
            int resource = board.getTiles()->at(i).getResource();
            //cout << "Resource: " << resource << endl;
            for (int j = 0; j < board.getTiles()->at(i).getVertices().size(); j++)
            {
                if (board.getTiles()->at(i).getVertices()[j]->getHasSettlement() == 1)
                {
                    //cout << "Player " << board.getTiles()->at(i).getVertices()[j]->getColor() << " gets a resource" << endl;
                    addResource(resource, 1);
                }
            }
        }
    }
    return dice;
}

void Player::trade(Player p2, string give, string take, int giveNum, int takeNum)
{
}

void Player::endTurn()
{
}

void Player::printPoints()
{
}

string Player::getColor()
{
    if (color == 1)
    {
        return "RED";
    }
    else if (color == 2)
    {
        return "BLUE";
    }
    else if (color == 3)
    {
        return "GREEN";
    }
    else
    {
        return "No color";
    }
}

int Player::placeSettlementFirst(Board &board, int vertexNum)
{

    // place settlement on the board
    //  cout << "Placing settlement on vertex " << vertexNum << endl;
    for (int i = 0; i < board.getVertex(vertexNum)->getEdges().size(); i++)
    {
        // print the edges of the vertex
        cout << "Edge " << i << " of vertex " << vertexNum << " has id " << board.getVertex(vertexNum)->getEdges()[i]->getId() << endl;
        // board.getVertex(vertexNum)->getEdges()[i]->getId()
    }
    if (isValidPlaceFirst(board, vertexNum) == 0)
    {
        return 0;
    }
    board.getVertex(vertexNum)->buildSettlement(color);
    for (int i = 0; i < board.getVertex(vertexNum)->getResources().size(); i++)
    {
        addResource(board.getVertex(vertexNum)->getResources()[i], 1);
    }
    points++;
    return 1;
}

int Player::placeRoad(Board &board, int edgeNum)
{

    // place road on the board
    //  cout << "Placing road on edge " << edgeNum << endl;
    if (board.getEdge(edgeNum)->getHasRoad() == 1)
    {
        cout << "This edge already has a road, color:" << board.getEdge(edgeNum)->getPlayerColor() << endl;
        return 0;
    }
    if (board.getEdge(edgeNum)->getVertex1()->getColor() == color && board.getEdge(edgeNum)->getVertex2()->getColor() == color)
    {
        cout << "This edge is already adjacent to your settlements" << endl;
        return 0;
    }
    int isValid = 0;
    if (board.getEdge(edgeNum)->getVertex1()->getColor() == color)
    {
        if (board.getEdge(edgeNum)->getVertex2()->getHasSettlement() == 0)
        {
            // cout << "This edge is adjacent to a settlement of the same color, you can build a road here" << endl;
            isValid = 1;
        }
        else
        {
            // cout << "This edge is not adjacent to a settlement of the same color, you cannot build a road here" << endl;
            isValid = 0;
        }
    }
    if (board.getEdge(edgeNum)->getVertex2()->getColor() == color)
    {
        if (board.getEdge(edgeNum)->getVertex1()->getHasSettlement() == 0)
        {
            // cout << "This edge is adjacent to a settlement of the same color, you can build a road here" << endl;
            isValid = 1;
        }
        else
        {
            // cout << "This edge is not adjacent to a settlement of the same color, you cannot build a road here" << endl;
            isValid = 0;
        }
    }
    if (board.getEdge(edgeNum)->getVertex1()->getColor() == 0 && board.getEdge(edgeNum)->getVertex2()->getColor() == 0)
    {
        // cout << "This edge is not adjacent to any settlements, you cannot build a road here" << endl;
        for (int i = 0; i < board.getEdge(edgeNum)->getVertex1()->getEdges().size(); i++)
        {
            if (board.getEdge(edgeNum)->getVertex1()->getEdges()[i]->getPlayerColor() == color)
            {
                isValid = 1;
            }
        }
        for (int i = 0; i < board.getEdge(edgeNum)->getVertex2()->getEdges().size(); i++)
        {
            if (board.getEdge(edgeNum)->getVertex2()->getEdges()[i]->getPlayerColor() == color)
            {
                isValid = 1;
            }
        }
    }
    if (isValid == 0)
    {
        cout << "This edge is not adjacent to any of your settlements" << endl;
        return 0;
    }
    board.getEdge(edgeNum)->buildRoad(color);
    return 1;
}

int Player::isValidPlaceFirst(Board &board, int vertexNum)
{
    if (vertexNum < 0 || vertexNum > 53)
    {
        cout << "Invalid vertex number" << endl;
        return 0;
    }
    if (board.getVertex(vertexNum)->getHasSettlement() == 1)
    {
        cout << "This vertex already has a settlement, color:" << board.getVertex(vertexNum)->getColor() << endl;
        return 0;
    }
    int isValid = 1;
    for (int i = 0; i < board.getVertex(vertexNum)->getEdges().size(); i++)
    {
        if (board.getVertex(vertexNum)->getEdges()[i]->getVertex1()->getId() != vertexNum)
        {
            if (board.getVertex(vertexNum)->getEdges()[i]->getVertex1()->getColor() != 0)
            {
                isValid = 0;
            }
        }
        if (board.getVertex(vertexNum)->getEdges()[i]->getVertex2()->getId() != vertexNum)
        {
            if (board.getVertex(vertexNum)->getEdges()[i]->getVertex2()->getColor() != 0)
            {
                isValid = 0;
            }
        }
    }
    if (isValid == 0)
    {
        cout << "This vertex is not adjacent to any of your settlements" << endl;
        return 0;
    }
    return 1;
}
