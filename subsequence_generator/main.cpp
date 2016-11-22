#include <iostream>
#include <vector>
using namespace std;

int main()
{
   string sequence,
          new_subsequence;
   char next_char;
   vector<string> all_subsequences,
                  new_subsequences;
   sequence = "BACBAD";
   all_subsequences.push_back(sequence[0]);
   for (short i = 1; i < sequence.length(); i++)
   {
       next_char = sequence[i];

       for (short i = 0; i < all_subsequences.size(); i++)
       {
           new_subsequence = all_subsequences.at(i) + next_char;
           new_subsequences.push_back(new_subsequence);
       }
       for (short i = 0; i < new_subsequences.size(); i++)
       {
           all_subsequences.push_back(new_subsequences.at(i));
       }
       all_subsequences.push_back(i);
   }
   for (short i = 0; i < all_subsequences.size(); i++)
   {
       cout << all_subsequences.at(i) << endl;
   }
}
