#include "Vertex.hpp"
#include <iostream>

// Getters
int Vertex::getHasSettlement() const
{
    return hasSettlement;
}

int Vertex::getHasCity() const
{
    return hasCity;
}

std::map<int, int> &Vertex::getResources()
{
    return resources;
}

int Vertex::getId() const
{
    return id_num;
}

std::vector<Edge *> &Vertex::getEdges()
{
    return adjacencyEdges;
}

int Vertex::getColor() const
{
    return player_color;
}

// Setters and Modifiers
void Vertex::addResource(int resource)
{
    resources[resource]++;
}

void Vertex::addEdges(std::vector<Edge *> e)
{
    adjacencyEdges = e;
}

void Vertex::buildSettlement(int color)
{
    hasSettlement = true;
    player_color = color;
    std::cout << "Settlement built at vertex " << id_num << " with color " << color << std::endl;
}

void Vertex::buildCity(int color)
{
    hasCity = true;
    player_color = color;
    hasSettlement = false;
    std::cout << "City built at vertex " << id_num << " with color " << color << std::endl;
}

// Other methods
void Vertex::printVertex() const
{
    std::cout << "Vertex " << id_num << " has a settlement: " << hasSettlement << " and a city: " << hasCity << " with color: " << player_color << std::endl;
    // cout << "Resources: ";
    // for (int i = 0; i < resources.size(); i++){
    //     cout << resources[i] << " ";
    // }
    // cout << endl;
}
