#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
class Solution
{
public:
    int minIncrementForUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int move = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] <= nums[i - 1])
            {
                int prev = nums[i];
                nums[i] = nums[i - 1] + 1;
                move += nums[i] - prev;
            }
        }
        return move;
    }
};

// using namespace std;
// class Solution
// {
// public:
//     int minIncrementForUnique(vector<int> &nums)
//     {
//         int ret = 0;
//         // sort(nums.begin(), nums.end());
//         unordered_map<int, int> count;
//         for (int num : nums)
//         {
//             count[num]++;
//             cout << num << " ";
//         }
//         cout << endl;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             int num = nums[i];
//             for (const auto &pair : count)
//                 cout << pair.first << " ";
//             cout << " --- ";
//             for (const auto &pair : count)
//                 cout << pair.second << " ";
//             cout << endl;
//             if (count[num] > 1)
//             {
//                 ret++;
//                 count[num + 1]++;
//                 count[num]--;
//                 i--;
//                 cout << "ret: " << ret << endl;
//             }
//         }
//         return ret;
//     }
// };

// int main()
// {
//     Solution solution;
//     vector<int> nums = {3, 2, 1, 2};
//     int result = solution.minIncrementForUnique(nums);
//     cout << "Minimum increment to make array unique: " << result << endl;
//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <unordered_map>

// using namespace std;
// class Solution
// {
// public:
//     int minIncrementForUnique(vector<int> &nums)
//     {
//         int ret = 0;
//         sort(nums.begin(), nums.end());
//         unordered_map<int, int> count;
//         for (int num : nums)
//             count[num]++;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             int num = nums[i];
//             if (count[num] > 1)
//             {
//                 ret++;
//                 count[num + 1]++;
//                 count[num]--;
//                 i--;
//             }
//         }
//         return ret;
//     }
// };

/*
-> 945. Minimum Increment to Make Array Unique
Medium

You are given an integer array nums. In one move, you can pick an index i where 0 <= i < nums.length and increment nums[i] by 1.

Return the minimum number of moves to make every value in nums unique.

The test cases are generated so that the answer fits in a 32-bit integer.

Example 1:
Input: nums = [1,2,2]
Output: 1
Explanation: After 1 move, the array could be [1, 2, 3].

Example 2:
Input: nums = [3,2,1,2,1,7]
Output: 6
Explanation: After 6 moves, the array could be [3, 4, 1, 2, 5, 7].
It can be shown with 5 or less moves that it is impossible for the array to have all unique values.

Constraints:
    1 <= nums.length <= 105
    0 <= nums[i] <= 105
*/