/**
 * @File    : mirrorTree.cpp
 * @Brief   : 二叉树的镜像
 * @Link    : https://leetcode-cn.com/problems/er-cha-shu-de-jing-xiang-lcof/
 * @Author  : Wei Li
 * @Date    : 2021-09-08
*/

#include <iostream>

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
    TreeNode *mirrorTree(TreeNode *root)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        TreeNode *left = mirrorTree(root->left);
        TreeNode *right = mirrorTree(root->right);
        root->left = right;
        root->right = left;
        return root;
    }
};

// ------------------------------
int main(int argc, char **argv)
{
    // test on leetcode online.

    return 0;
}
