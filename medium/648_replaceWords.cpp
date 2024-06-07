#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class TrieNode
{
public:
    unordered_map<char, TrieNode *> children;
    string word;

    TrieNode() {}
};

class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode *node = root;
        for (char c : word)
        {
            if (node->children.find(c) == node->children.end())
            {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->word = word;
    }

    string searchRoot(string word)
    {
        TrieNode *node = root;
        for (char c : word)
        {
            if (node->children.find(c) == node->children.end())
            {
                break;
            }
            node = node->children[c];
            if (!node->word.empty())
            {
                return node->word;
            }
        }
        return word;
    }
};

class Solution
{
public:
    string replaceWords(vector<string> &dictionary, string sentence)
    {
        Trie trie;
        for (string word : dictionary)
        {
            trie.insert(word);
        }

        string result;
        int start = 0;
        while (start < sentence.size())
        {
            int end = start;
            while (end < sentence.size() && sentence[end] != ' ')
            {
                end++;
            }
            string word = sentence.substr(start, end - start);
            if (!result.empty())
            {
                result += " ";
            }
            result += trie.searchRoot(word);
            start = end + 1;
        }

        return result;
    }
};

/*
-> 648. Replace Words
Medium

In English, we have a concept called root, which can be followed by some other word to form another longer word - let's call this word derivative. For example, when the root "help" is followed by the word "ful", we can form a derivative "helpful".

Given a dictionary consisting of many roots and a sentence consisting of words separated by spaces, replace all the derivatives in the sentence with the root forming it. If a derivative can be replaced by more than one root, replace it with the root that has the shortest length.

Return the sentence after the replacement.

Example 1:
Input: dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"

Example 2:
Input: dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
Output: "a a b c"

Constraints:
    1 <= dictionary.length <= 1000
    1 <= dictionary[i].length <= 100
    dictionary[i] consists of only lower-case letters.
    1 <= sentence.length <= 106
    sentence consists of only lower-case letters and spaces.
    The number of words in sentence is in the range [1, 1000]
    The length of each word in sentence is in the range [1, 1000]
    Every two consecutive words in sentence will be separated by exactly one space.
    sentence does not have leading or trailing spaces.
*/

/*
// class Solution
// {
// public:
//     string replaceWords(vector<string> &dictionary, string sentence)
//     {
//         int index = 0;
//         int begin = 0;
//         int end = k_strtok(sentence, begin);
//         int wordSize = 0;

//         string replace(sentence.size(), ' ');

//         while (begin < sentence.size() && end <= sentence.size())
//         {
//             wordSize = end - begin;
//             for (string word : dictionary)
//             {
//                 if (k_isexist(sentence.substr(begin, end - begin), word))
//                     if (wordSize > word.size())
//                         wordSize = word.size();
//             }
//             replace.replace(index, wordSize, sentence.substr(begin, begin + wordSize));
//             index += wordSize;
//             if (end < sentence.size())
//             {
//                 replace[index] = ' ';
//                 index++;
//             }
//             begin = end + 1;
//             end = k_strtok(sentence, begin);
//         }
//         return replace.substr(0, index);
//     }

//     int k_strtok(string str, int index)
//     {
//         for (int i = index; i < str.size(); i++)
//             if (str[i] == ' ')
//                 return i;
//         return str.size();
//     }

//     bool k_isexist(string str, string word)
//     {
//         if (word.size() > str.size())
//             return false;
//         for (int i = 0; i < word.size(); i++)
//             if (str[i] != word[i])
//                 return false;
//         return true;
//     }
// };
*/