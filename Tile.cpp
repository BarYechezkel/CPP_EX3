#include "Tile.hpp"
#include <iostream>



void Tile::setResource(int resource) {
    this->resource = resource;
}

void Tile::setNumber(int number) {
    this->number = number;
}

int Tile::getResource() const {
    return resource;
}

int Tile::getNumber() const{
    return number;
}

int Tile::getId() const {
    return id_num;
}

std::vector<Vertex*> Tile::getVertices()const {
    return vertices;
}

void Tile::printTile() const{
    std::cout << "Tile " << id_num << " has resource: " << resource << " number: " << number << std::endl;
    std::cout << "Vertices: " << std::endl;
    for (size_t i = 0; i < vertices.size(); i++) {
        vertices[i]->printVertex();
    }
    std::cout << "Edges: " << std::endl;
    for (size_t i = 0; i < edges.size(); i++) {
        edges[i]->printEdge();
    }
}
