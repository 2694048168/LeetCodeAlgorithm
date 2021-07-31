/**
 * @File    : diameterOfBinaryTree.cpp
 * @Brief   : 二叉树的直径
 * @Link    : https://leetcode-cn.com/problems/diameter-of-binary-tree/
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
    int diameterOfBinaryTree(TreeNode *root)
    {
        int diameter = 0;
        helper(root, diameter);
        return diameter;
    }
    // 辅函数
    int helper(TreeNode *node, int &diameter)
    {
        if (!node)
        {
            return 0;
        }
        int l = helper(node->left, diameter), r = helper(node->right, diameter);
        diameter = std::max(l + r, diameter);
        return std::max(l, r) + 1;
    }
};

// ------------------------------
int main(int argc, char **argv)
{
    // test on LeetCode online.

    return 0;
}
