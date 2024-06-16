
#include "Edge.hpp"

void Edge::buildRoad(int color)
{
    if (hasRoad)
    {
        std::cout << "This edge already has a road, color: " << player_color << std::endl;
        return;
    }
    hasRoad = true;
    player_color = color;
    std::cout << "Road built at edge " << id_num << " with color " << color << std::endl;
}

void Edge::printEdge()
{
    std::cout << "Edge " << id_num << " has a road: " << hasRoad << " player color: " << player_color << std::endl;
    // cout << "Vertex 1: ";
    // vertex1->printVertex();
    // cout << "Vertex 2: ";
    // vertex2->printVertex();
}

int Edge::getId() const
{
    return id_num;
}

Vertex *Edge::getVertex1() const
{
    return vertex1;
}

Vertex *Edge::getVertex2() const
{
    return vertex2;
}

bool Edge::getHasRoad() const
{
    return hasRoad;
}

int Edge::getPlayerColor() const
{
    return player_color;
}
