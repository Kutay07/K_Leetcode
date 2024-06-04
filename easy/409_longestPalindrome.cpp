#include <iostream>
#include <unordered_map>

using namespace std;
class Solution
{
public:
    int longestPalindrome(string s)
    {
        int ret = 0;
        bool single = false;
        unordered_map<char, int> charcount;

        for (char c : s)
            charcount[c]++;
        for (auto it : charcount)
        {
            if (!single && it.second % 2 == 1)
                single = true;
            ret += (it.second / 2) * 2;
        }
        if (single)
            ret++;
        return ret;
    }
};

/*
-> 409. Longest Palindrome
Easy

Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.
Letters are case sensitive, for example, "Aa" is not considered a palindrome.

Example 1:
Input: s = "abccccdd"
Output: 7
Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.

Example 2:
Input: s = "a"
Output: 1
Explanation: The longest palindrome that can be built is "a", whose length is 1.

Constraints:
    1 <= s.length <= 2000
    s consists of lowercase and/or uppercase English letters only.
*/