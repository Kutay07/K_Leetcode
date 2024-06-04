#include <vector>

using namespace std;
class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int size = s.size() - 1;
        char tmp = 0;
        for (int i = 0; i < size - i; i++)
        {
            tmp = s[i];
            s[i] = s[size - i];
            s[size - i] = tmp;
        }
    }
};

/*
-> 344. Reverse String
Easy

Write a function that reverses a string. The input string is given as an array of characters s.
You must do this by modifying the input array in-place with O(1) extra memory.

Example 1:
Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]

Example 2:
Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]

Constraints:
    1 <= s.length <= 105
    s[i] is a printable ascii character.
*/