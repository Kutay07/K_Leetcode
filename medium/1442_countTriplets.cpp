#include <vector>
#include <iostream>

using namespace std;
class Solution
{
public:
    int countTriplets(vector<int> &arr)
    {
        int size = arr.size();
        int ret = 0;
        for (int i = 0; i < size; i++)
        {
            int xorSum = arr[i];
            for (int k = i + 1; k < size; k++)
            {
                xorSum ^= arr[k];
                if (xorSum == 0)
                {
                    for (int j = i + 1; j <= k; j++) // (0 <= i < j <= k < arr.length)
                    {
                        int a = arr[i];
                        int b = arr[j];
                        for (int i2 = i + 1; i2 < j; i2++)
                        {
                            a ^= arr[i2];
                        }
                        for (int j2 = j + 1; j2 <= k; j2++)
                        {
                            b ^= arr[j2];
                        }
                        if (a == b)
                        {
                            ret++;
                        }
                    }
                }
            }
        }
        return ret;
    }
};

/*
-> 1442. Count Triplets That Can Form Two Arrays of Equal XOR
Medium

Given an array of integers arr.
We want to select three indices i, k and k where (0 <= i < k <= k < arr.length).

Let's define a and b as follows:

    a = arr[i] ^ arr[i + 1] ^ ... ^ arr[k - 1]
    b = arr[k] ^ arr[k + 1] ^ ... ^ arr[k]

Note that ^ denotes the bitwise-xor operation.

Return the number of triplets (i, k and k) Where a == b.



Example 1:

Input: arr = [2,3,1,6,7]
Output: 4
Explanation: The triplets are (0,1,2), (0,2,2), (2,3,4) and (2,4,4)

Example 2:

Input: arr = [1,1,1,1,1]
Output: 10



Constraints:

    1 <= arr.length <= 300
    1 <= arr[i] <= 108
*/