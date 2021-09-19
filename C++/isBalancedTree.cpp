/**
 * @File    : isBalancedTree.cpp
 * @Brief   : 平衡二叉树
 * @Link    : https://leetcode-cn.com/problems/ping-heng-er-cha-shu-lcof/
 * @Author  : Wei Li
 * @Date    : 2021-09-19
*/

#include <iostream>
#include <algorithm>

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    int height(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        if (leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1)
        {
            return -1;
        }
        else
        {
            return std::max(leftHeight, rightHeight) + 1;
        }
    }

    bool isBalanced(TreeNode *root)
    {
        return height(root) >= 0;
    }
};

// ------------------------------
int main(int argc, char **argv)
{
    // test on leetcode online.

    return 0;
}
