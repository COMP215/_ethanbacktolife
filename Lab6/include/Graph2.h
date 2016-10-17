#include <iostream>
#include <vector> // must be defined in .cpp as well?
#include "Node2.h"

#ifndef GRAPH2_H
#define GRAPH2_H

class Graph2
{
    public:
        std::vector<Node2> all_nodes_;
        Graph2();
        ~Graph2();
        void Add(std::string add, std::vector <edge> connections);
        void AddVertex(std::string data); // adds a single vertex
        void AddEdge(std::string source_data, std::string target_data); // adds an undirected edge between source and target vertices
        void ToGraphviz(); // exports a DOT language file for the graph

};

#endif // GRAPH2_H
