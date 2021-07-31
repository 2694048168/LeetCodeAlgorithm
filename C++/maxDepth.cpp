/**
 * @File    : maxDepth.cpp
 * @Brief   : 二叉树的最大深度
 * @Link    : https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/
 * @Author  : Wei Li
 * @Date    : 2021-07-31
*/

#include <iostream>
#include <algorithm>

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
    int maxDepth(TreeNode *root)
    {
        return root ? 1 + std::max(maxDepth(root->left), maxDepth(root->right)): 0;
    }
};

// -----------------------------
int main(int argc, char **argv)
{
    // test on LeetCode online.

    return 0;
}
