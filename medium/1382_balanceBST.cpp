#include <vector>
#include <iostream>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

using namespace std;
class Solution
{
public:
    void inorderTraversal(TreeNode *root, vector<int> &nodes)
    {
        if (root == nullptr)
            return;
        inorderTraversal(root->left, nodes);
        nodes.push_back(root->val);
        inorderTraversal(root->right, nodes);
    }

    TreeNode *sortedArrayToBST(vector<int> &nodes, int start, int end)
    {
        if (start > end)
            return nullptr;
        int mid = start + (end - start) / 2;
        TreeNode *node = new TreeNode(nodes[mid]);
        node->left = sortedArrayToBST(nodes, start, mid - 1);
        node->right = sortedArrayToBST(nodes, mid + 1, end);
        return node;
    }

    TreeNode *balanceBST(TreeNode *root)
    {
        vector<int> nodes;
        inorderTraversal(root, nodes);
        return sortedArrayToBST(nodes, 0, nodes.size() - 1);
    }
};

/*
link: https://leetcode.com/problems/balance-a-binary-search-tree/
1382. Balance a Binary Search Tree
Medium

Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.

A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.



Example 1:

Input: root = [1,null,2,null,3,null,4,null,null]
Output: [2,1,3,null,null,null,4]
Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct.

Example 2:

Input: root = [2,1,3]
Output: [2,1,3]



Constraints:

    The number of nodes in the tree is in the range [1, 104].
    1 <= Node.val <= 105


*/