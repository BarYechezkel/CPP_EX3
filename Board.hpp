#ifndef BOARD_HPP
#define BOARD_HPP
#include <iostream>
#include <vector>
#include <string>
#include "Tile.hpp"
using namespace std;

class Board{

private:
    vector<Tile> tiles;
    vector<Vertex> vertices; 
    vector<Edge> edges;
    
public:
// empty constructor
    Board();
    
   
    void Init_Board();
    void InitResourcesAndNumbers();
    void InitVerticesResources();
    void InitVerticesAdjacencyEdges();


    vector<Tile>& getBoard(){
        return tiles;
    }

    void printBoard();


    Vertex* getVertex(int id_num);
    Edge* getEdge(int id_num);

    vector<Vertex>& getVertices(){
        return vertices;
    }

    vector<Tile>* getTiles(){
        return &tiles;
    }
    

};

#endif // BOARD_HPP