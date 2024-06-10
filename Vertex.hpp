#ifndef VERTEX_HPP
#define VERTEX_HPP
#include <string>
#include <vector>
#include <iostream>
#include "Tile.hpp"
#include "Edge.hpp"
#include <map>
using namespace std;

class Edge;

class Vertex{

private:
    int id_num;
    bool hasSettlement;
    bool hasCity;
    int player_color;
    map <int, int> resources;
    vector<Edge*> adjancyEdges;
    


public:
Vertex(int id_num) : id_num(id_num), hasSettlement(false), hasCity(false), player_color(0) {
    resources[1] = 0; // wood
    resources[2] = 0; // brick
    resources[3] = 0; // sheep
    resources[4] = 0; // wheat
    resources[5] = 0; // iron
}
Vertex(){};

void buildSettlement(int color);
void buildCity(int color);
void printVertex();
void setSettlement(int color);
//void setAdjacentTiles(vector<Tile*> tiles);
void addResource(int resource){
    resources[resource]++;
}
int getHasSettlement(){
    return hasSettlement;
}
int getHasCity(){
    return hasCity;
}

map<int,int>& getResources(){
    return resources;
}

///////////////////////////////////continue here colors

int getId(){
    return id_num;
}

void addEdges(vector<Edge*> e){
    adjancyEdges = e;
}

vector<Edge*>& getEdges(){
    return adjancyEdges;
}

int getColor(){
    return player_color;
}

};

#endif // VERTEX_HPP