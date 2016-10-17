#ifndef NODE2_H
#define NODE2_H
#include <iostream>
#include <vector>


struct edge{
std::string name = "";
short weight;
};

class Node2
{
    public:
        Node2();
        Node2(std::string data);
       ~Node2();
       std::string data_;
       std::vector<edge> edges_;
};


#endif // NODE2_H
