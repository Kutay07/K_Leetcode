#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution
{
public:
    vector<string> commonChars(vector<string> &words)
    {
        vector<string> ret;
        unordered_map<char, int> m;
        for (char c : words[0])
            m[c]++;
        for (auto c : m)
        {
            int count = c.second;
            for (string s : words)
            {
                int _count = commonCount(s, c.first);
                if (count > _count)
                    count = _count;
            }
            if (count > 0)
                for (int i = 0; i < count; i++)
                    ret.push_back(string(1, c.first));
        }
        return ret;
    }

    int commonCount(string &word, char c)
    {
        int count = 0;
        for (char ch : word)
            if (ch == c)
                count++;

        return count;
    }
};

/*
-> 1002. Find Common Characters
Easy

Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). You may return the answer in any order.

Example 1:
Input: words = ["bella","label","roller"]
Output: ["e","l","l"]

Example 2:
Input: words = ["cool","lock","cook"]
Output: ["c","o"]

Constraints:
    1 <= words.length <= 100
    1 <= words[i].length <= 100
    words[i] consists of lowercase English letters.
*/
