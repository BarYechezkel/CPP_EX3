#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <string>
#include <vector>
#include <iostream>
#include <map>
#include "Tile.hpp"
#include "Edge.hpp"

class Edge; // Forward declaration

class Vertex {
private:
    // Member variables
    int id_num;
    bool hasSettlement;
    bool hasCity;
    int player_color;
    std::map<int, int> resources;
    std::vector<Edge*> adjacencyEdges;

public:
    // Constructors
    Vertex(int id_num) : id_num(id_num), hasSettlement(false), hasCity(false), player_color(0) {
        resources[0] = 0; // wood
        resources[1] = 0; // brick
        resources[2] = 0; // sheep
        resources[3] = 0; // wheat
        resources[4] = 0; // iron
    }
    Vertex(){}; // Default constructor

    // Getters
    int getId() const;
    int getHasSettlement() const;
    int getHasCity() const;
    int getColor() const;
    std::map<int, int>& getResources();
    std::vector<Edge*>& getEdges();

    // Setters and modifiers
    void addResource(int resource);
    void addEdges(std::vector<Edge*> e);
    void buildSettlement(int color);
    void buildCity(int color);

    // Other methods
    void printVertex() const;
};

#endif // VERTEX_HPP
