#include "Node2.h"
#include <iostream>
#include <vector>

Node2::Node2()
{
    data_ = "";
    edges_ = {};


}

/*Node2::Node2(string data)
{
    data_ = data;
    edges_ = {};
}
*/
Node2::~Node2()
{

}

Node2& Node2::operator=(/*in*/const Node2& node)
{
    this->data_ = node.data_;
    this->edges_ = node.edges_;

    return *this;
}
