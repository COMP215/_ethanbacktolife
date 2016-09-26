#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED


//

//  binarysearchtree.hpp

//  demo

//

//  Created by Tom Armstrong on 9/19/16.

//  Copyright © 2016 tarmstro. All rights reserved.

//



#ifndef linkedlist_hpp

#define linkedlist_hpp



#include <stdio.h>

#include <string>

#include <iostream>



class NodeL {

public:

    std::string data_;

    NodeL* next_;



public:

    NodeL(std::string);

};





class LinkedList {

    NodeL* root_;

    NodeL* tail_;



public:

    LinkedList();

    bool Insert(std::string);

    bool Search(std::string);

    bool Delete(std::string);

    void Display();

};





#endif /* binarysearchtree_hpp */


#endif // LINKEDLIST_H_INCLUDED
