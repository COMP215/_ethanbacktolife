#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include "constants.h"

using namespace std;

int main()
{
    char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
                       'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
                      };

    srand(time(NULL));

    short randInd;

    string temp = ""; // abbreviation ok because conventional?


    ofstream FOUT;
    ifstream FIN;
    string file = "RandStrings.txt";

    struct node
    {
        string str;

        node *next;
    };

    node *randNode,
         *initNode,
         *tempNode;

    for ( int i = 0; i < 3; i++) // creates three distinct sets of strings
    {

        FOUT.open(file.c_str());

        if ( FOUT.fail() )				// but did the attempt to open fail?
        {
            cout << "ERROR: file called " << file << " did NOT open." << endl;
            exit(-1);
        } // if

        for (int i = 1; i <= STRINGMAX; i++)
        {
            for (int i = 1; i <= CHARMAX; i++)
            {
                randInd = rand() % ALPHASIZE;

                temp = temp + alphabet[randInd];
            }

            FOUT << temp << endl;

            temp = "";
        }


        FIN.open(file.c_str());

        if ( FIN.fail() )				// but did the attempt fail?
        {
            cout << "ERROR: file called " << file << " did NOT open." << endl;
            exit(-1);
        } // if

        node *initNode = new node;

        getline(FIN, temp);

        initNode->str = temp;
        initNode->next = 0;

        for ( int i = 1; i <= STRINGMAX - 1; i++)
        {
            getline(FIN, temp); // why is the file input object accepted as an argument. Shouldn't getline be a function of the
            // file input class?
            randNode = new node;
            randNode->str = temp;
            randNode->next = initNode;

            if (randNode->str.compare(initNode->str) < 0)
            {
                initNode = randNode; // if less than the first string in list
            }
            else while (randNode->str.compare(randNode->next->str) >= 0)// if new string is greater than the string in front
                {
                    // of it
                    tempNode = randNode->next;
                    randNode->next = randNode->next->next; // moves new string ahead by one in the list
                    if (randNode->str.compare(initNode->str) < 0)
                        tempNode->next = randNode;// connects beginning of list to the added string after added
                    // string is sorted
                }
        }//end for
    }
    cout << endl << "Process Complete";





}



