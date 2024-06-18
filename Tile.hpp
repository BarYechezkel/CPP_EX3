#ifndef TILE_HPP
#define TILE_HPP

#include <string>
#include "Edge.hpp"
#include "Vertex.hpp"
#include <vector>

#define WOOD 0
#define BRICK 1
#define SHEEP 2
#define WHEAT 3
#define IRON 4
#define DESERT 5

class Vertex;
class Edge;

class Tile {
private:
    int number;
    int id_num;
    int resource;
    std::vector<Vertex*> vertices;
    std::vector<Edge*> edges;

public:
Tile(int num, std::vector<Vertex*> ver, std::vector<Edge*> edg) : id_num(num), vertices(ver), edges(edg) {
    resource = 0;
    number = 0;
}

    void setResource(int resource);
    void setNumber(int number);
    int getResource() const;
    int getNumber() const;
    int getId() const;
    std::vector<Vertex*> getVertices() const;
    void printTile() const;
};

#endif // TILE_HPP
