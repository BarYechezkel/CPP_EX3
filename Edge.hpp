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
    int getId(){
        return id_num;
    }

    Vertex* getVertex1(){
        return vertex1;
    }

    Vertex* getVertex2(){
        return vertex2;
    }

    bool getHasRoad(){
        return hasRoad;
    }

    int getPlayerColor(){
        return player_color;
    }




};

#endif //EDGE_HPP