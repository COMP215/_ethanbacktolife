#include <iostream>

using namespace std;

short findEuclidGCDRecursive(long smaller_num, long larger_num)
{
    short new_remainder;

    new_remainder = larger_num % smaller_num;

    if (new_remainder == 0)
    {
        return smaller_num;
    }
    else
    {
        findEuclidGCDRecursive(new_remainder, smaller_num); // "remainder" replaces "larger_num", remainder is smaller
                                                            // than "smaller_num", therefore "smaller_num" is the new larger num
    }

}

short findEuclidGCD(long num_1, long num_2)
{
    if (num_1 > num_2)
    {
        findEuclidGCDRecursive(num_2, num_1);
    }
    else
    {
        findEuclidGCDRecursive(num_1, num_2);
    }
}
short findBinaryGCDRecursive(long num_1, long num_2, short factors_of_2)
{
    if (num_1 == num_2) // if both even, GCD = 2 * GCD(x/2, y/2)
    {
        return num_1;
    }
    /*else if (num_1 == 0)
    {
        return num_2 * (2^factors_of_2);
    }
     else if (num_2 == 0)
    {
        return num_1 * (2^factors_of_2);
    }*/
    else if (num_1 % 2 == 0)
    {
        if (num_2 % 2 == 0) // if both even, then GCD(x,y) = 2GCD(x/2, y/2)
        {
            factors_of_2++;
            return findBinaryGCDRecursive(num_1 / 2, num_2 / 2, factors_of_2);
        }
        else // if num_1 even, num_2 odd
        {
            return findBinaryGCDRecursive(num_1 / 2, num_2, factors_of_2);
        }
    }
    else if (num_2 % 2 == 0) // if num_1 odd, num_2 even
    {
        return findBinaryGCDRecursive(num_1, num_2 / 2, factors_of_2);
    }
    else if (num_2 >= num_1) // if both odd, and num_2 greater
    {
        return findBinaryGCDRecursive(num_1, (num_2 - num_1) / 2, factors_of_2);
    }
    else // if both odd, and num_1 greater
    {
        return findBinaryGCDRecursive((num_1 - num_2) / 2, num_2, factors_of_2);
    }
}
short findBinaryGCD(long num_1, long num_2)
{
    short factors_of_2 = 0;

    return findBinaryGCDRecursive(num_1, num_2, factors_of_2);
}

int main()
{   const short GCD_TESTS_SIZE = 10;
    unsigned long test_GCDs[GCD_TESTS_SIZE];
    unsigned long actual_GCDs[GCD_TESTS_SIZE]; //from online GCD calculator

    actual_GCDs[0] = 4; //GCD(12, 8)
    actual_GCDs[1] = 8; //GCD(56, 72)
    actual_GCDs[2] = 2; //GCD(122, 240)
    actual_GCDs[3] = 20; //GCD(520, 340)
    actual_GCDs[4] = 1; //GCD(627, 340)
    actual_GCDs[5] = 2; //GCD(1234, 23456)
    actual_GCDs[6] = 4; //GCD(7252, 436)
    actual_GCDs[7] = 32; //GCD(123456, 23456)
    actual_GCDs[8] = 90; //GCD(34920, 43290)
    actual_GCDs[9] = 10; //GCD(123450, 500240)

    test_GCDs[0] = findEuclidGCD(12, 8);
    test_GCDs[1] = findEuclidGCD(56, 72);
    test_GCDs[2] = findEuclidGCD(122, 240);
    test_GCDs[3] = findEuclidGCD(520, 340);
    test_GCDs[4] = findEuclidGCD(627, 340);
    test_GCDs[5] = findEuclidGCD(1234, 23456);
    test_GCDs[6] = findEuclidGCD(7252, 436);
    test_GCDs[7] = findEuclidGCD(123456, 23456);
    test_GCDs[8] = findEuclidGCD(34920, 43290);
    test_GCDs[9] = findEuclidGCD(123450, 500240);

    cout << "-----------------------------------------------------------------------------" << endl
    << "Euclid's Algorithm" << endl << endl;

    for (short i = 0; i < GCD_TESTS_SIZE; i++)
    {
        cout << "Function: " << test_GCDs[i] << ", Actual: " << actual_GCDs[i] << endl;
        cout << "Test " << i + 1 << ": ";

        if (actual_GCDs[i] == test_GCDs[i])
        {
            cout << "Passed" << endl;
        }
        else
        {
            cout << "Failed" << endl;
        }
    }
    test_GCDs[0] = findBinaryGCD(12, 8);
    test_GCDs[1] = findBinaryGCD(56, 72);
    test_GCDs[2] = findBinaryGCD(122, 240);
    test_GCDs[3] = findBinaryGCD(520, 340);
    test_GCDs[4] = findBinaryGCD(627, 340);
    test_GCDs[5] = findBinaryGCD(1234, 23456);
    test_GCDs[6] = findBinaryGCD(7252, 436);
    test_GCDs[7] = findBinaryGCD(123456, 23456);
    test_GCDs[8] = findBinaryGCD(34920, 43290);
    test_GCDs[9] = findBinaryGCD(123450, 500240);

    cout << "-----------------------------------------------------------------------------" << endl <<
    "Binary GCD Algorithm" << endl << endl;

    for (short i = 0; i < GCD_TESTS_SIZE; i++)
    {
        cout << "Function: " << test_GCDs[i] << ", Actual: " << actual_GCDs[i] << endl;
        cout << "Test " << i + 1 << ": ";

        if (actual_GCDs[i] == test_GCDs[i])
        {
            cout << "Passed" << endl;
        }
        else
        {
            cout << "Failed" << endl;
        }
    }
}
