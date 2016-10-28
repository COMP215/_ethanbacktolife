#include "Graph2.h"
#include <vector>
#include "Node2.h"
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;




Graph2::Graph2()
{
    all_nodes_ = {};
}

Graph2::Graph2(vector<Node2> all_nodes)
{
    all_nodes_ = all_nodes;
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
                new_edge.name = data;
                new_edge.weight = connections.at(j).weight;
                all_nodes_.at(i).edges_.push_back(new_edge);
               // resolves issue of duplicate data_ nodes,
                       // still can't specify which of two nodes w/ identical data you want connected
                break;
            }
        undirected_edge new_edge; // adds a new undirected_edge to the vector all_undirected_edges
        new_edge.vertex_1 = data;
        new_edge.vertex_2 = connections.at(j).name;
        new_edge.weight = connections.at(j).weight;
        all_undirected_edges.push_back(new_edge);
        }

    }


    Node2 to_add;
    to_add.data_ = data;
    to_add.edges_ = connections;
    all_nodes_.push_back(to_add);
}

void Graph2::AddVertex(string data)
{
    Node2 to_add;
    to_add.data_ = data;
    all_nodes_.push_back(to_add);
}
void Graph2::AddEdge(string source_data, string target_data)
{
    edge new_edge;
    for (int i = 0; i < all_nodes_.size(); i++){
        if (all_nodes_.at(i).data_ == source_data){
            new_edge.name = target_data;
            all_nodes_.at(i).edges_.push_back(new_edge);
        }
        if (all_nodes_.at(i).data_ == target_data){
                     // temporary variable since push_back makes a copy
            new_edge.name = source_data;
            all_nodes_.at(i).edges_.push_back(new_edge); // lengthy but only way to change element contents w/out reference
        }
    }
     undirected_edge new_und_edge; // adds a new undirected_edge to the vector all_undirected_edges
     new_und_edge.vertex_1 = source_data;
     new_und_edge.vertex_2 = target_data;
     all_undirected_edges.push_back(new_und_edge);
}

void Graph2::AddEdge(string source_data, string target_data, short weight)
{
    edge new_edge;
    new_edge.weight = weight;
    for (int i = 0; i < all_nodes_.size(); i++){
        if (all_nodes_.at(i).data_ == source_data){
            new_edge.name = target_data;
            all_nodes_.at(i).edges_.push_back(new_edge);
        }
        if (all_nodes_.at(i).data_ == target_data){
            new_edge.name = source_data;
            all_nodes_.at(i).edges_.push_back(new_edge); // lengthy but only way to change element contents w/out reference
        }
    }
     undirected_edge new_und_edge; // adds a new undirected_edge to the vector all_undirected_edges
     new_und_edge.vertex_1 = source_data;
     new_und_edge.vertex_2 = target_data;
     new_und_edge.weight = weight;
     all_undirected_edges.push_back(new_und_edge);
}

void Graph2::ToGraphviz()
{
    ofstream FOUT;
    string file;

     file = "graph_viz.txt";
     FOUT.open(file.c_str());

        if ( FOUT.fail() ){				// but did the attempt to open fail?
            cout << "ERROR: file called " << file << " did NOT open." << endl; // couldn't do exit(-1);
        } // if
        else {
            short edges_size;
            Node2 node;
            edge neighbor;

            FOUT << "graph things {" << endl;
            for (short i = 0; i < all_nodes_.size(); i++)
            {
                edges_size = all_nodes_.at(i).edges_.size();
                node = all_nodes_.at(i);
                if (edges_size == 0)
                {
                    FOUT << "   " << node.data_ << ";" << endl;
                }
                else
                {
                    for (short j = 0; j < edges_size; j++)
                    {
                        neighbor = node.edges_[j];
                        FOUT << "   " << node.data_ << " -- " << neighbor.name << ";" << endl;
                    }
                }
            }
            FOUT << "}";

        }
}

Graph2 Graph2::PrimMST()
{
    Node2 curr_node,
          added_node, // node already in tree
          toBeAdded_node; // node neighboring added_node that is about to be added

    vector<Node2> tree; // (closed structure)
    vector<Node2> graph;// (open structure)
    vector<edge> neighbors; // each node's edges

    edge temp, // used to add new edges at the end
         curr_neighbor; //holds edge of each node in graph

    short lowest_weight, //weight of lowest found edge
          closest_neighbor_index,
          closest_vertex_index,
          curr_neighbor_index,
          curr_vertex_index;

    const short INITIAL_GRAPH_SIZE = graph.size();

    graph = all_nodes_;
    tree = {};
    closest_neighbor_index = 0;
    closest_vertex_index = 0;

    toBeAdded_node = graph.back(); // initial node must be added outside while because chosen arbitrarily
    graph.pop_back();
    toBeAdded_node.edges_ = {};
    tree.push_back(toBeAdded_node);

    while (tree.size() != INITIAL_GRAPH_SIZE) // algorithm ends when tree contains all nodes
    {
        for (short i = 0; i < graph.size(); i++) // for each node
        {
            curr_node = graph.at(i);
            neighbors = curr_node.edges_;
            for (short j = 0; j < neighbors.size(); j++) // for edges of each node
            {
                curr_neighbor = neighbors.at(j);
                for (short k = 0; k < tree.size(); k++) // examines each tree node to find smallest weight
                                                        // edge between tree nodes and graph nodes
                {
                    added_node = tree.at(k);
                    if (added_node.data_ == curr_neighbor.name && curr_neighbor.weight < lowest_weight)
                    {
                        lowest_weight = curr_neighbor.weight;
                        closest_neighbor_index = curr_neighbor_index; // closest_neighbor_index = i; can't do because i is a reference to a node
                        closest_vertex_index = curr_vertex_index; // closest_vertex_index = k; can't do
                    }
                    curr_vertex_index++;
                }
                curr_vertex_index = 0;
            }
            curr_neighbor_index++;
        }
        curr_neighbor_index = 0;
        toBeAdded_node = graph.at(closest_neighbor_index); // tree node and graph node sharing smallest edge accessed
        graph.erase(graph.begin() + (closest_neighbor_index));
        toBeAdded_node.edges_ = {};
        added_node = tree.at(closest_vertex_index);

        temp.name = toBeAdded_node.data_; // toBeAdded_node connected to added_node, removed from graph
        temp.weight = lowest_weight;      // and added to tree
        tree.at(closest_vertex_index).edges_.push_back(temp);
        temp.name = added_node.data_;
        toBeAdded_node.edges_.push_back(temp);
        tree.push_back(toBeAdded_node);

    }
     Graph2 tree_graph(tree);
     return tree; // MST returned
}

Graph2 Graph2::KruskalMST()
{
vector<undirected_edge> sorted_edges;
vector<string> forest; // (open structure) string clever or confusing?
vector<Node2> final_tree; // (closed structure)

Node2 temp_node,
      curr_node, // for different context
      curr_node_1,
      curr_node_2;

undirected_edge next_edge; // stores next smallest edge from sorted_edges
edge temp_edge;// used to add edges to nodes

string vertex; // stores forest vertices

curr_node_1.data_ = "";
curr_node_2.data_ = "";
sorted_edges = all_undirected_edges;
sort(sorted_edges.begin(), sorted_edges.end() - 1, comp); // all edges sorted by weight in ascending order

for (short i = 0; i < all_nodes_.size(); i++) // forest populated
{
    curr_node = all_nodes_.at(i);
    vertex = curr_node.data_;
    forest.push_back(vertex);
}
for (short i = 0; i < sorted_edges.size(); i++) // for each edge
{
    next_edge = sorted_edges.back();
    sorted_edges.pop_back();
    temp_edge.weight = next_edge.weight; // will putting before for loop improve efficiency? yes.
    for (short j = 0; j < forest.size(); j++) // if next_edge has vertex in forest, remove it and store it
    {
        if (next_edge.vertex_2 == forest.at(j))
        {
            curr_node_2.data_ = forest.at(j);
            forest.erase(forest.begin() + j);
        }
        else if (next_edge.vertex_1 == forest.at(j))
        {
            curr_node_1.data_ = forest.at(j);
            forest.erase(forest.begin() + j);
        }
    }

    if ((curr_node_1.data_ == "" || curr_node_2.data_ == "") // if either but not both of the vertices are already in the tree
        && !(curr_node_1.data_ == "" && curr_node_2.data_ == "")) // (if neither vertex in forest, then already part of tree
        {
                                                                     // -> edge can't be added, nothing more to be done)
        if (curr_node_1.data_ != "") // if this vertex was found in forest connect neighbor and add it to tree
        {                            //no need to say more in if statement because of initial if statement (line 261)
            temp_edge.name = next_edge.vertex_2;
            curr_node_1.edges_.push_back(temp_edge);
            final_tree.push_back(curr_node_1);
        }
        else // if the other vertex was already found
        {
            temp_edge.name = next_edge.vertex_1;
            curr_node_2.edges_.push_back(temp_edge);
            final_tree.push_back(curr_node_2);
        }

        for (short j = 0; j < final_tree.size(); j++) // for each vertex in forest
        {
            if (next_edge.vertex_1 == final_tree.at(j).data_) // if vertex of next_edge, make the vertex in the forest a neighbor of the vertex in the tree
            {
                temp_edge.name = next_edge.vertex_2;
                final_tree.at(j).edges_.push_back(temp_edge);
            }
            else if (next_edge.vertex_2 == final_tree.at(j).data_)
            {
                temp_edge.name = next_edge.vertex_1;
                final_tree.at(j).edges_.push_back(temp_edge);
            }

        }


    }

    else if (curr_node_1.data_ != "" && curr_node_2.data_ != "") // if both found in forest, make each the neighbor of the other
    {                                                            // and add both to tree
        temp_edge.name = next_edge.vertex_1;
        curr_node_2.edges_.push_back(temp_edge);
        temp_edge.name = next_edge.vertex_2;
        curr_node_1.edges_.push_back(temp_edge);
        final_tree.push_back(curr_node_1);
        final_tree.push_back(curr_node_2);
    }
}

Graph2 tree_graph(final_tree);
return tree_graph; // return MST (would it pass the compiler if no return statement, behavior suggests yes)

}



