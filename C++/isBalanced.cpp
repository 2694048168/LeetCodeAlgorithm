/**
 * @File    : isBalanced.cpp
 * @Brief   : 平衡二叉树
 * @Link    : https://leetcode-cn.com/problems/balanced-binary-tree/
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
    // 主函数
    bool isBalanced(TreeNode *root)
    {
        return helper(root) != -1;
    }
    // 辅函数
    int helper(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        int left = helper(root->left), right = helper(root->right);
        if (left == -1 || right == -1 || abs(left - right) > 1)
        {
            return -1;
        }
        return 1 + std::max(left, right);
    }
};

// ------------------------------
int main(int argc, char **argv)
{
    // test on LeetCode online.

    return 0;
}
