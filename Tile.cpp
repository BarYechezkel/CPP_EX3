#include "Tile.hpp"

void Tile::printTile()
{
    cout << "Tile " << id_num << " has resource: " << resource << " number: " << number << endl;
    cout << "Vertices: " << endl;
    for (size_t i = 0; i < vertices.size(); i++)
    {
        vertices[i]->printVertex();
        
    }
    cout << "Edges: " << endl;
    for (size_t i = 0; i < edges.size(); i++)
    {
        edges[i]->printEdge();
    }
}
