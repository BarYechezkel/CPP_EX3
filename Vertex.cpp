
#include "Vertex.hpp"
#include <iostream>


/*
buildSettlement function
plyer builds a settlement at a vertex only if there is no settlement already built
@param color: the color of the player building the settlement
@returns: void

*/
// Vertex::Vertex()
// {
// }
void Vertex::buildSettlement(int color)
{
    // cout << "Building settlement at vertex " << id_num << endl;
    if (hasSettlement)
    {
        cout << "This vertex already has a settlement, color:"<<player_color<< endl;
        return;
    }
    hasSettlement = true;
    player_color = color;
    cout << "Settlement built at vertex " << id_num << " with color " << color << endl;
}
/*
buildCity function
player builds a city at a vertex only if there is a settlement already built
@param color: the color of the player building the city
@returns: void
*/
void Vertex::buildCity(int color)
{
    if (!hasSettlement)
    {
        cout << "This vertex does not have a settlement, cannot build a city" << endl;
        return;
    }
    if (hasCity)
    {
        cout << "This vertex already has a city, color:"<<player_color<< endl;
        return;
    }
    if (player_color != color)
    {
        cout << "This vertex has a settlement of a different color, cannot build a city" << endl;
        return;
    }
    hasCity = true;
    player_color = color;
    hasSettlement = false;
    cout << "City built at vertex " << id_num << " with color " << color << endl;   
}

void Vertex::printVertex()
{
    cout << "Vertex " << id_num << " has a settlement: " << hasSettlement << " and a city: " << hasCity << " with color: " << player_color <<endl;
    // cout << "Resources: "; 
    // for (int i = 0; i < resources.size(); i++){
    //     cout << resources[i] << " ";
    // }
    // cout << endl;
}

void Vertex::setSettlement(int color)
{
    hasSettlement = true;
    player_color = color;
    cout << "Settlement built at vertex " << id_num << " with color " << color << endl;
}

// void Vertex::setAdjacentTiles(vector<Tile *> tiles)
// {
//     adjacentTiles = tiles;
// }
