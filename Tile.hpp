#ifndef TILE_HPP
#define TILE_HPP
#include <string>
#include "Edge.hpp"
#include "Vertex.hpp"
#include <vector>
using namespace std;

#define WOOD 1
#define BRICK 2
#define SHEEP 3
#define WHEAT 4
#define IRON 5
#define DESERT 0

class Vertex;
class Edge;

class Tile {

private:
int number;
int id_num;
int resource;
vector<Vertex*> vertices;
vector<Edge*> edges;

public:
Tile(int num, vector<Vertex*> ver, vector<Edge*> edg) : id_num(num), vertices(ver), edges(edg) {
    resource = 0;
    number = 0;
}


void setResource(int resource){
    this->resource = resource;
}

void setNumber(int number){
    this->number = number;
}

int getResource(){
    return resource;
}

int getNumber(){
    return number;
}

int getId(){
    return id_num;
}

// void setVerticesResources(){
//     for (int i = 0; i < vertices.size(); i++){
//         vertices[i]->setResource(resource);
//     }
// }

vector<Vertex*> getVertices(){
    return vertices;
}

void printTile();



};

#endif //TILE_HPP