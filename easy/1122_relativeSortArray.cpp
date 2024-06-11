#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        unordered_map<int, int> m;
        for (int num : arr1)
            m[num]++;
        vector<int> ret;
        for (int num : arr2)
        {
            for (int i = 0; i < m[num]; i++)
                ret.push_back(num);
            m.erase(num);
        }
        int forsize = arr1.size() - ret.size();
        for (int i = 0; i < forsize; i++)
        {
            int temp = 2147483647;
            for (auto it = m.begin(); it != m.end(); it++)
            {
                temp = (it->first < temp) ? it->first : temp;
            }
            for (int i = 0; i < m[temp]; i++)
                ret.push_back(temp);
            m.erase(temp);
        }
        return ret;
    }
};

/*
-> 1122. Relative Sort Array
Easy

Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.

Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2. Elements that do not appear in arr2 should be placed at the end of arr1 in ascending order.

Example 1:
Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
Output: [2,2,2,1,4,3,3,9,6,7,19]

Example 2:
Input: arr1 = [28,6,22,8,44,17], arr2 = [22,28,8,6]
Output: [22,28,8,6,17,44]

Constraints:
    1 <= arr1.length, arr2.length <= 1000
    0 <= arr1[i], arr2[i] <= 1000
    All the elements of arr2 are distinct.
    Each arr2[i] is in arr1.
*/