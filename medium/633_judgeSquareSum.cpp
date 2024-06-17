#include <cmath>

using namespace std;
class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        for (long a = 0; a * a <= c; a++)
        {
            double b = sqrt(c - a * a);
            if (b == (int)b)
                return true;
        }
        return false;
    }
};

/*
-> 633. Sum of Square Numbers
Medium

Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.

Example 1:
Input: c = 5
Output: true
Explanation: 1 * 1 + 2 * 2 = 5

Example 2:
Input: c = 3
Output: false

Constraints:
    0 <= c <= 231 - 1
*/