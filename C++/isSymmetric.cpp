/**
 * @File    : isSymmetric.cpp
 * @Brief   : 对称二叉树
 * @Link    : https://leetcode-cn.com/problems/symmetric-tree/
 * @Author  : Wei Li
 * @Date    : 2021-07-31
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
    // 主函数
    bool isSymmetric(TreeNode *root)
    {
        return root ? isSymmetric(root->left, root->right) : true;
    }
    // 辅函数
    bool isSymmetric(TreeNode *left, TreeNode *right)
    {
        if (!left && !right)
        {
            return true;
        }
        if (!left || !right)
        {
            return false;
        }
        if (left->val != right->val)
        {
            return false;
        }
        return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
    }
};

// --------------------------------
int main(int argc, char **argv)
{
    // test on LeetCode online.

    return 0;
}
