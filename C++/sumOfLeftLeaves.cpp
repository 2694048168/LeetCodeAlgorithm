/**
 * @File    : sumOfLeftLeaves.cpp
 * @Brief   : 左叶子之和
 * @Link    : https://leetcode-cn.com/problems/sum-of-left-leaves/
 * @Author  : Wei Li
 * @Date    : 2021-08-01
*/

#include <iostream>

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool isLeafNode(TreeNode *node)
    {
        return !node->left && !node->right;
    }

    int dfs(TreeNode *node)
    {
        int ans = 0;
        if (node->left)
        {
            ans += isLeafNode(node->left) ? node->left->val : dfs(node->left);
        }
        if (node->right && !isLeafNode(node->right))
        {
            ans += dfs(node->right);
        }
        return ans;
    }

    int sumOfLeftLeaves(TreeNode *root)
    {
        return root ? dfs(root) : 0;
    }
};

// --------------------------------
int main(int argc, char **argv)
{
    // test on LeetCode online.

    return 0;
}
