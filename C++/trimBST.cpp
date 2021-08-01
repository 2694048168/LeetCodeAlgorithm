/**
 * @File    : trimBST.cpp
 * @Brief   : 修剪二叉搜索树
 * @Link    : https://leetcode-cn.com/problems/trim-a-binary-search-tree/
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
    TreeNode *trimBST(TreeNode *root, int L, int R)
    {
        if (!root)
        {
            return root;
        }
        if (root->val > R)
        {
            return trimBST(root->left, L, R);
        }
        if (root->val < L)
        {
            return trimBST(root->right, L, R);
        }
        root->left = trimBST(root->left, L, R);
        root->right = trimBST(root->right, L, R);
        return root;
    }
};

// -----------------------------
int main(int argc, char **argv)
{
    // test on LeetCode online.

    return 0;
}
