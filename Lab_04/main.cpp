
//  main.cpp
//  classbst
//
//  Created by Tom Armstrong on 9/19/16.
//  Copyright © 2016 tarmstro. All rights reserved.
//

#include <fstream>
#include "binarysearchtree.hpp"
#include "LinkedList.h" // stopped "multiple definitions" error when I changed from .cpp to .h
#include <stdlib.h>
using namespace std;

int main(int argc, const char * argv[]) {

    BinarySearchTree* people_names = new BinarySearchTree();
    people_names->Insert("gousie");
    people_names->Insert("bloch");
    people_names->Insert("armstrong");
    people_names->Insert("decoste");
    bool search_result_1 = people_names->Search("gousie");
    bool search_result_2 = people_names->Search("Ethan");
    cout << "Gousie is in the tree: " << search_result_1 << endl;
    cout << "Ethan is in the tree: " << search_result_2 <<endl;


    BinarySearchTree* random_words = new BinarySearchTree();
    LinkedList* words = new LinkedList();

    ifstream FIN;
    string file,
           word;

    bool isThere;

    file = "foowords.txt";
    FIN.open(file.c_str());

      if ( FIN.fail() )				// but did the attempt fail?
        {
            cout << "ERROR: file called " << file << " did NOT open." << endl;
            exit(-1);
        } // if

    while ( !FIN.eof() ){ // foowords.txt into BST
        getline(FIN, word);
        random_words->Insert(word);
    }

    FIN.close();
    FIN.open(file.c_str());

    while ( !FIN.eof() ){ // foowords.txt into LL
        getline(FIN, word);
        words->Insert(word);
    }

    cout << "good so far" << endl;

    FIN.close();
    file = "words.txt";
    FIN.open(file.c_str());

    if ( FIN.fail() ){
        cout << "ERROR: file called " << file << " did NOT open." << endl;
        exit(-1);

}

    while ( !FIN.eof() ){ // BST search for word from words.txt
        getline(FIN, word);
        isThere = random_words->Search(word);
        cout << word << ": Is it there? " << isThere << endl;
    }

    FIN.close();
    FIN.open(file.c_str());

    while ( !FIN.eof() ){ // LL search for word from randomwords.txt
        getline(FIN, word);
        isThere = words->Search(word);
        cout << word << ": Is it there? " << isThere << endl;
    }


    return 0;
}

