#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;
class Solution
{
public:
    int longestSubarray(vector<int> &nums, int limit)
    {
        deque<int> max_deque, min_deque;
        int left = 0, max_length = 0;
        for (int right = 0; right < nums.size(); ++right)
        {
            while (!max_deque.empty() && nums[max_deque.back()] <= nums[right])
                max_deque.pop_back();
            max_deque.push_back(right);
            while (!min_deque.empty() && nums[min_deque.back()] >= nums[right])
                min_deque.pop_back();
            min_deque.push_back(right);
            while (nums[max_deque.front()] - nums[min_deque.front()] > limit)
            {
                left++;
                if (max_deque.front() < left)
                    max_deque.pop_front();
                if (min_deque.front() < left)
                    min_deque.pop_front();
            }
            max_length = max(max_length, right - left + 1);
        }
        return max_length;
    }
};

/*
link: https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/
-> 1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
Medium

Given an array of integers nums and an integer limit, return the size of the longest non-empty subarray such that the absolute difference between any two elements of this subarray is less than or equal to limit.


Example 1:
Input: nums = [8,2,4,7], limit = 4
Output: 2
Explanation: All subarrays are:
[8] with maximum absolute diff |8-8| = 0 <= 4.
[8,2] with maximum absolute diff |8-2| = 6 > 4.
[8,2,4] with maximum absolute diff |8-2| = 6 > 4.
[8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.
[2] with maximum absolute diff |2-2| = 0 <= 4.
[2,4] with maximum absolute diff |2-4| = 2 <= 4.
[2,4,7] with maximum absolute diff |2-7| = 5 > 4.
[4] with maximum absolute diff |4-4| = 0 <= 4.
[4,7] with maximum absolute diff |4-7| = 3 <= 4.
[7] with maximum absolute diff |7-7| = 0 <= 4.
Therefore, the size of the longest subarray is 2.

Example 2:
Input: nums = [10,1,2,4,7,2], limit = 5
Output: 4
Explanation: The subarray [2,4,7,2] is the longest since the maximum absolute diff is |2-7| = 5 <= 5.

Example 3:
Input: nums = [4,2,2,2,4,4,2,2], limit = 0
Output: 3

Constraints:
    1 <= nums.length <= 105
    1 <= nums[i] <= 109
    0 <= limit <= 109
*/