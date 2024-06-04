#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isNumber(string s)
    {
        bool e = false;
        int i = 0;
        while (s[i])
        {
            if (s[i] == 'e' || s[i] == 'E')
            {
                e = true;
                break;
            }
            i++;
        }
        if (e)
        {
            if (exponentControl(s, 0, s.size()))
                return true;
            else
                return false;
        }
        else
        {
            if (decimalControl(s, 0, s.size()))
                return true;
            else if (numberControl(s, 0, s.size()))
                return true;
        }
        return false;
    }

    bool numberControl(string s, int start, int end)
    {
        int i = start;
        if (s[i] == '-' || s[i] == '+')
            i++;
        if (i >= end)
            return false;
        while (i < end)
        {
            if (s[i] < '0' || s[i] > '9')
                return false;
            i++;
        }
        return true;
    }

    bool decimalControl(string s, int start, int end)
    {
        int i = start;
        int dot = -1;
        if (s[i] == '-' || s[i] == '+')
            i++;
        while (i < end)
        {
            if (s[i] == '.')
            {
                if (dot == 1)
                    return false;
                dot++;
            }
            i++;
        }
        if (dot == -1)
            return false;
        if (numberControl(s, start, dot) || numberControl(s, dot + 1, end))
            return true;
        return false;
    }

    bool exponentControl(string s, int start, int end)
    {
        int i = start;
        int e = 0;
        int whereIs_e = -1;
        while (i < end)
        {
            if (s[i] == 'e' || s[i] == 'E')
            {
                if (e == 1)
                    return false;
                whereIs_e = i;
                e++;
            }
            i++;
        }
        if (whereIs_e == -1)
            return false;
        if (numberControl(s, start, whereIs_e) || decimalControl(s, start, whereIs_e))
        {
            if (numberControl(s, whereIs_e + 1, end))
                return true;
            else
                return false;
        }
        else
            return false;
        return true;
    }
};

int main()
{
    Solution solution;

    vector<string> validnumbers = {"2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"};
    vector<string> invalidnumbers = {"abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"};
    vector<string> testCases = {
        "2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3",
        "3e+7", "+6e-1", "53.5e93", "-123.456e789", "abc", "1a",
        "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53", " ", " 3 ", " 3.5e10 ", "3e-10"};

    for (const string &test : validnumbers)
    {
        cout << "Test case: \"" << test << "\" is ";
        if (solution.isNumber(test))
        {
            cout << "a valid number." << endl;
        }
        else
        {
            cout << "not a valid number." << endl;
        }
    }
    cout << "-----------------------------------" << endl;
    for (const string &test : invalidnumbers)
    {
        cout << "Test case: \"" << test << "\" is ";
        if (solution.isNumber(test))
        {
            cout << "a valid number." << endl;
        }
        else
        {
            cout << "not a valid number." << endl;
        }
    }

    return 0;
}

/*
-> 65. Valid Number
Hard

Given a string s, return whether s is a valid number.

For example, all the following are valid numbers: "2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789", while the following are not valid numbers: "abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53".

Formally, a valid number is defined using one of the following definitions:

    An integer number followed by an optional exponent.
    A decimal number followed by an optional exponent.

An integer number is defined with an optional sign '-' or '+' followed by digits.
A decimal number is defined with an optional sign '-' or '+' followed by one of the following definitions:

    Digits followed by a dot '.'.
    Digits followed by a dot '.' followed by digits.
    A dot '.' followed by digits.

An exponent is defined with an exponent notation 'e' or 'E' followed by an integer number.
The digits are defined as one or more digits.

Example 1:
Input: s = "0"
Output: true

Example 2:
Input: s = "e"
Output: false

Example 3:
Input: s = "."
Output: false


Constraints:
    1 <= s.length <= 20
    s consists of only English letters (both uppercase and lowercase), digits (0-9), plus '+', minus '-', or dot '.'.
*/