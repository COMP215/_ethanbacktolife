#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<short>&);
int main()
{
    vector<short> numbers;
    numbers.push_back(3);
    cout << "unsorted list: " << endl;
    for (short i = 0; i < numbers.size(); i++)
    {
        cout << numbers.at(i) << endl;
    }

    selectionSort(numbers);
    cout << "sorted list:" << endl;
    for (short i = 0; i < numbers.size(); i++)
    {
        cout << numbers.at(i) << endl;
    }
    return 0;
}

void selectionSort(vector<short>& unsorted_array)
{
    short min_index;

    for (short i = 0; i < unsorted_array.size(); i++)
    {
        min_index = i;
        for (short j = i; i < unsorted_array.size(); j++)
        {
            if (unsorted_array[min_index] > unsorted_array[j])
            {
                min_index = j;
            }
        }

        //cout << "Found a minimum! " << unsorted_array[min_index] << endl;
        swap(unsorted_array[min_index], unsorted_array[i]);
    }
}
void selectionSort(vector<short>& unsorted_array)
{
    short min_index;

    for (short i = 0; i < unsorted_array.size(); i++)
    {
        min_index = i;
        for (short j = i; i < unsorted_array.size(); j++)
        {
            if (unsorted_array[min_index] > unsorted_array[j])
            {
                min_index = j;
            }
        }

        //cout << "Found a minimum! " << unsorted_array[min_index] << endl;
        swap(unsorted_array[min_index], unsorted_array[i]);
    }
}

void bubbleSort(vector<short>& unsorted_array[])
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


void mergeSort(vector<short>& unsorted_array) //
{
    unsorted_array = mergeSortRecursive(unsorted_array);
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
                new_sorted_array.push_back(sorted_array1.at(index1))
                index1++;
            }
            else
            {
                new_sorted_array.push_back(sorted_array2.at(index2))
                index2++;
            }
        }
        return new_sorted_array;
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

