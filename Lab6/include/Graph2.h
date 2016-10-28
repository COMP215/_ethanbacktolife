#include <iostream>
#include <vector> // must be defined in .cpp as well?
#include "Node2.h"

#ifndef GRAPH2_H
#define GRAPH2_H

class Graph2
{
    public:

        struct undirected_edge{//for Kruskal Algorithm, better to keep track of edges as added
            std::string vertex_1;
            std::string vertex_2;
            short weight;
        };
        struct compare_edges { // structs must be included in .h?
            bool operator()(undirected_edge a, undirected_edge b)
        {
            return (a.weight > b.weight);
        }
        } comp;

        std::vector<Node2> all_nodes_;
        std::vector<undirected_edge> all_undirected_edges;
        Graph2();
        Graph2(std::vector<Node2> all_nodes);
        //~Graph2();
        bool CompareEdges(undirected_edge a, undirected_edge b);
        void Add(std::string add, std::vector <edge> connections);
        void AddVertex(std::string data); // adds a single vertex
        void AddEdge(std::string source_data, std::string target_data);
        void AddEdge(std::string source_data, std::string target_data, short weight); // adds an undirected edge between source and target vertices
        void ToGraphviz(); // exports a DOT language file for the graph
        Graph2 PrimMST();
        Graph2 KruskalMST();
};

#endif // GRAPH2_H
