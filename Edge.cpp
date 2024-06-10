#include "Edge.hpp"



void Edge::buildRoad(int color)
{
    if (hasRoad)
    {
        cout << "This edge already has a road, color:"<<player_color<< endl;
        return;
    }
    hasRoad = true;
    player_color = color;
    cout << "Road built at edge " << id_num << " with color " << color << endl;
}

void Edge::printEdge()
{
    cout << "Edge " << id_num << " has a road: " << hasRoad << " player color: " << player_color << endl;
    // cout << "Vertex 1: ";
    // vertex1->printVertex();
    // cout << "Vertex 2: ";
    // vertex2->printVertex();
}

