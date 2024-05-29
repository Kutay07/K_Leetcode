#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {

        //printSubsets(flagNums);
        vector<vector<int>> flagNums = FlagNums(nums, k);
        return bSubsets(nums, flagNums);
    }

    int bSubsets(vector<int>& nums, vector<vector<int>>& search) {
        int count = 0;
        int n = nums.size();
        for (int i = 1; i < (1 << n); i++) {
            vector<int> subset;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    subset.push_back(nums[j]);
                }
            }
            count += existingCount(subset, search);
        }
        return count;
    }

    void printSubsets(vector<vector<int>>& subsets) {
        for (const auto& subset : subsets) {
            cout << "{ ";
            for (const auto& num : subset) {
                cout << num << " ";
            }
            cout << "}\n";
        }
    }

    int existingCount(vector<int>& nums, vector<vector<int>> search){
        int count = 0;
        int len = search.size();
        for (int i = 0; i < len; i++){
            if (isExist(nums, search[i][0])){
                if (isExist(nums, search[i][1])){
                    return (0);
                }
            }
        }
        return (1);
    }

    int isExist (vector<int>& nums, int k){
        int len = nums.size();
        for (int i = 0; i < len; i++){
            if (k == nums[i]){
                return (1);
            }
        }
        return (0);
    }

    vector<vector<int>> FlagNums(vector<int>& nums, int k){
        int n = nums.size();
        vector<vector<int>> flagNums;
        int diff = 0;
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                diff = nums[i] - nums[j];
                if (diff < 0){
                    diff*= -1;
                }
                if (diff == k){
                    flagNums.push_back({nums[i], nums[j]});
                }
            }
        }
        return flagNums;
    }

};


/*

-> 2597. The Number of Beautiful Subsets
Medium

You are given an array nums of positive integers and a positive integer k.

A subset of nums is beautiful if it does not contain two integers with an absolute difference equal to k.

Return the number of non-empty beautiful subsets of the array nums.

A subset of nums is an array that can be obtained by deleting some (possibly none) elements from nums. Two subsets are different if and only if the chosen indices to delete are different.

 

Example 1:

Input: nums = [2,4,6], k = 2
Output: 4
Explanation: The beautiful subsets of the array nums are: [2], [4], [6], [2, 6].
It can be proved that there are only 4 beautiful subsets in the array [2,4,6].
Example 2:

Input: nums = [1], k = 1
Output: 1
Explanation: The beautiful subset of the array nums is [1].
It can be proved that there is only 1 beautiful subset in the array [1].
 

Constraints:

1 <= nums.length <= 20
1 <= nums[i], k <= 1000

*/