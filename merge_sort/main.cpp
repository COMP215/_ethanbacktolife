#include <iostream>
#include <vector>
/*
bugs: condition was i, but I was trying to increment j -> infinite loop
*/
using namespace std;

void selectionSort(vector<short>& unsorted_array)
{
    short min_index; // ultimately holds the index of the array subset with the minimum value

    for (short i = 0; i < unsorted_array.size(); i++)
    {

        min_index = i;
        for (short j = i; j < unsorted_array.size(); j++)
        {
            if (unsorted_array.at(min_index) > unsorted_array.at(j))
            {
                min_index = j;
            }

        }

        //cout << "Found a minimum! " << unsorted_array[min_index] << endl;
        swap(unsorted_array.at(min_index), unsorted_array.at(i));

    }
}

void bubbleSort(vector<short>& unsorted_array)
{
    bool swapped = true; // lying to yourself
    while(swapped)
    {
        swapped = false;

        for (short i = 0; i < unsorted_array.size() - 1; i++)
        {
            if (unsorted_array[i] > unsorted_array[i + 1])
            {
                swap(unsorted_array[i], unsorted_array[i + 1]);
                swapped = true; // less efficient to  have second if statement
            }
        }
    }
}

short findMidpoint(vector<short> numbers) // returns the index of numbers which, if numbers were split down the middle into two arrays,
{   short index;                    // would contain the first element of the "right-hand" array
    if (numbers.size() % 2 == 0)
    {
        index = numbers.size() / 2;
    }
    else
    {
        index = (numbers.size() + 1) / 2; //"left-hand" array is one larger than "right-hand" array
    }
}

vector<short> mergeSortRecursive(vector<short> new_array)
{
    if (new_array.size() == 1)
    {
        return new_array;
    }
    else
    {
        short array2_start,//holds the "midpoint", specifically the index which will contain the first value of array2 once divided
              sorted_array1_size,
              sorted_array2_size,
              new_sorted_array_size,
              index1,
              index2;
        vector<short> array1,
                      array2,
                      sorted_array1,
                      sorted_array2,
                      new_sorted_array;
        array2_start = findMidpoint(new_array);

        for (short i = 0; i < array2_start; i++)
        {
            array1.push_back(new_array.at(i));
        }
        for (short i = array2_start; i < new_array.size(); i++)
        {
            array2.push_back(new_array.at(i));
        }

        sorted_array1 = mergeSortRecursive(array1);
        sorted_array2 = mergeSortRecursive(array2);
        sorted_array1_size = sorted_array1.size();
        sorted_array2_size = sorted_array2.size();
        new_sorted_array_size =  sorted_array1.size() + sorted_array2.size();
        while (index1 != sorted_array1_size && index2 != sorted_array2_size)
        {
            if (sorted_array1.at(index1) < sorted_array2.at(index2))
            {
                new_sorted_array.push_back(sorted_array1.at(index1));
                index1++;
            }
            else
            {
                new_sorted_array.push_back(sorted_array2.at(index2));
                index2++;
            }
        }
        return new_sorted_array;
    }
}

void mergeSort(vector<short>& unsorted_array) //
{
    unsorted_array = mergeSortRecursive(unsorted_array);
}

int main()
{
    vector<short> numbers;
    numbers.push_back(3);
    numbers.push_back(2);
    numbers.push_back(1);
    numbers.push_back(7);
    numbers.push_back(6);
    numbers.push_back(6);
    numbers.push_back(10);
    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);

    cout << "unsorted list: " << endl;
    for (short i = 0; i < numbers.size(); i++)
    {
        cout << numbers.at(i) << " ";
    }
    mergeSort(numbers);
    cout << endl << "sorted list:" << endl;
    for (short i = 0; i < numbers.size(); i++)
    {
        cout << numbers.at(i) << " ";
    }
    return 0;
}
