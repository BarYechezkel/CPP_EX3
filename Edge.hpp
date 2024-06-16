#ifndef EDGE_HPP
#define EDGE_HPP
#include "Vertex.hpp"
#include <vector>
#include <iostream>

using namespace std;

class Vertex;


class Edge {

    private:
        int id_num = 0;
        Vertex* vertex1;
        Vertex* vertex2;
        bool hasRoad = false;
        int player_color= 0;
        

    public:
    Edge(int id_num, Vertex* v1, Vertex* v2) : id_num(id_num), vertex1(v1), vertex2(v2), hasRoad(false), player_color(0) {}
    Edge(){};

  
    void buildRoad(int color);
    void printEdge();
    int getId() const;
    Vertex* getVertex1() const;
    Vertex* getVertex2() const;
    bool getHasRoad() const;
    int getPlayerColor() const;
};

#endif // EDGE_HPP