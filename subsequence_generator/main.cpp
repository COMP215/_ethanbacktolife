#include <iostream>
#include <vector>
using namespace std;

int main()
{

   string new_subsequence,
          next_char;
   vector<string> sequence,
                  all_subsequences,
                  new_subsequences;
   sequence.push_back("B");
   sequence.push_back("A");
   sequence.push_back("C");
   sequence.push_back("B");
   sequence.push_back("A");
   sequence.push_back("D");
   new_subsequence = sequence.at(0);
   all_subsequences.push_back(new_subsequence);
   for (short i = 1; i < sequence.size(); i++)
   {
       next_char = sequence.at(i);

       for (short j = 0; j < all_subsequences.size(); j++)
       {
           new_subsequence = all_subsequences.at(j) + next_char;
           new_subsequences.push_back(new_subsequence);
       }
       for (short j = 0; j < new_subsequences.size(); j++)
       {
           all_subsequences.push_back(new_subsequences.at(j));
       }
       new_subsequences.clear();
       new_subsequence = sequence.at(i);
       all_subsequences.push_back(new_subsequence);
   }
   for (short i = 0; i < all_subsequences.size(); i++)
   {
       cout << all_subsequences.at(i) << endl;
   }
   cout << "Maximum number of distinct subsequences: " << all_subsequences.size() << endl;
}
