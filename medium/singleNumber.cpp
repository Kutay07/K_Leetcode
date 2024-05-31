#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        unordered_map<int, int> count;
        vector<int> ret;
        for (int num : nums)
        {
            count[num]++;
        }
        for (const auto &pair : count)
        {
            if (pair.second == 1)
            {
                ret.push_back(pair.first);
            }
        }
        return ret;
    }
};
