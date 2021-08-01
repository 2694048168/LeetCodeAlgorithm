/**
 * @File    : invertTree.cpp
 * @Brief   : 翻转二叉树
 * @Link    : https://leetcode-cn.com/problems/invert-binary-tree/
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
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        TreeNode *left = invertTree(root->left);
        TreeNode *right = invertTree(root->right);
        root->left = right;
        root->right = left;
        return root;
    }
};

// -----------------------------
int main(int argc, char **argv)
{
    // test on LeetCode online.

    return 0;
}
