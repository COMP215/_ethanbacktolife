#include <iostream>
#include <Graph2.h>
#include <Node2.h>
#include <vector>

using namespace std;

int main()
{
  Graph2 graph;
  graph.AddVertex("A");
  graph.AddVertex("B");
  graph.AddVertex("C");
  graph.AddVertex("D");
  graph.AddVertex("E");
  graph.AddVertex("F");
  graph.AddEdge("A", "B", 6);
  graph.AddEdge("B", "C", 5);
  graph.AddEdge("C", "D", 4);
  graph.AddEdge("D", "E", 3);
  graph.AddEdge("E", "F", 2);
  graph.AddEdge("F", "A", 1);


  Graph2 new_graph;
  new_graph = graph.KruskalMST();
  new_graph.ToGraphviz();
/*
  vector<edge> neighbors;
  edge new_edge;
  new_edge.name = "A";
  new_edge.weight = 10;
  neighbors.push_back(new_edge);
  new_edge.name = "B";
  new_edge.weight = 11;
  neighbors.push_back(new_edge);
  new_edge.name = "C";
  new_edge.weight = 12;
  neighbors.push_back(new_edge);
  graph.Add("G", neighbors);
*/

/*
  vector<short> numbers;
  short a = 4;
  short b = 3;
  numbers.push_back(a);
  numbers.push_back(b);
  a = a + 1;
  cout << a << " = " << numbers.at(0);
*/
}
