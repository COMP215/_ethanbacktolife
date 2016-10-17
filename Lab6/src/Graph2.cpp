#include "Graph2.h"
#include <vector>
#include "Node2.h"
#include <iostream>
#include <fstream>
using namespace std;

Graph2::Graph2()
{
    all_nodes_ = {};
}

void Graph2::Add(string data, vector <edge> connections) // overload w/ bool
{

    for (int i = 0; i < all_nodes_.size(); i++)
    {
        for (int j = 0; j < connections.size(); j++)
        {
             if (all_nodes_.at(i).data_ == connections.at(j).name)
            {
                edge new_edge;
                new_edge.name = data
                new_edge.weight = connections.at(j).weight;
                all_nodes_.at(i).edges_.push_back(data_);
                break; // resolves issue of duplicate data_ nodes,
                       // still can't specify which of two nodes w/ identical data you want connected
            }

        }

    }

    Node2 to_add;
    to_add.data_ = add;

    to_add.edges_ = connections;

    all_nodes_.push_back(to_add); // doesn't make a deep copy right?
}

void Graph2::AddVertex(string data)
{
    Node2 to_add;
    to_add.data_ = data;
    all_nodes_.push_back()
}
void Graph2::AddEdge(string source_data, string target_data)
{
    Node2 source
          target;

    for (int i = 0; i < all_nodes_.size(); i++){
        if (all_nodes_.at(i).data_ == source_data){
            source = all_nodes.at(i);
            for (int j = 0; j < all_nodes_.size(); j++){
                if (all_nodes_.at(j) == target_data){
                    edge new_edge; // temporary variable since push_back makes a copy
                    new_edge.name = source_data;
                    source.edges_.push_back(new_edge);
                    new_edge.name = target_data;
                    target.edges_.push_back(new_edge);
                }
            }
        }

    }
}

void Graph2::AddEdge(string source_data, string target_data, short weight)
{
    Node2 source
          target;

    for (int i = 0; i < all_nodes_.size(); i++){
        if (all_nodes_.at(i).data_ == source_data){
            source = all_nodes.at(i);
            for (int j = 0; j < all_nodes_.size(); j++){
                if (all_nodes_.at(j) == target_data){
                    edge new_edge; // temporary variable since push_back makes a copy
                    new_edge.weight = weight;
                    new_edge.name = source_data;
                    source.edges_.push_back(new_edge);
                    new_edge.name = target_data;
                    target.edges_.push_back(new_edge);
                }
            }
        }

    }
}
void Graph2::ToGraphviz()
{
    ofstream FOUT;
    string file;

     file = "graph_viz.gz"
     FOUT.open(file.c_str());

        if ( FOUT.fail() ){				// but did the attempt to open fail?
            cout << "ERROR: file called " << file << " did NOT open." << endl;
            exit(-1);
        } // if
        else {
            short edges_size;
            Node2 node;
            FOUT << "graph things {" << endl;
            for (short i = 0; i < all_nodes_.size(); i++)
            {
                edges_size = all_nodes_.at(i).edges_.size();
                node = all_nodes_.at(i);
                for (short j = 0; j < edges_size; j++)
                {
                    FOUT << "   " << node.data_ << " -- " << node.edges_[j]. endl;
                }
                FOUT << ";" << endl;
            }
        }
}
