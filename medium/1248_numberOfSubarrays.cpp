#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;
class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        unordered_map<int, int> countMap;
        countMap[0] = 1;
        int count = 0;
        int oddCount = 0;
        for (int num : nums)
        {
            oddCount += num % 2;
            if (countMap.find(oddCount - k) != countMap.end())
            {
                count += countMap[oddCount - k];
            }
            countMap[oddCount]++;
        }
        return count;
    }
    // bool isNice(vector<int> &nums, int k, int start, int end)
    // {
    //     int count = 0;
    //     for (int i = start; i <= end; i++)
    //         if (nums[i] % 2 == 1)
    //             count++;
    //     return count == k;
    // }
    // int numberOfSubarrays(vector<int> &nums, int k)
    // {
    //     int size = nums.size();
    //     int count = 0;
    //     for (int i = 0; i < size; i++)
    //     {
    //         for (int j = i; j < size; j++)
    //         {
    //             if (isNice(nums, k, i, j))
    //                 count++;
    //         }
    //     }
    //     return count;
    // }
};

/*
link: https://leetcode.com/problems/count-number-of-nice-subarrays/description/

-> 1248. Count Number of Nice Subarrays
Medium

Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.

Example 1:
Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].

Example 2:
Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There are no odd numbers in the array.

Example 3:
Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16

Constraints:
    1 <= nums.length <= 50000
    1 <= nums[i] <= 10^5
    1 <= k <= nums.length
*/