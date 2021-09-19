/**
 * @File    : maxDepthTree.cpp
 * @Brief   : 二叉树的深度 
 * @Link    : https://leetcode-cn.com/problems/er-cha-shu-de-shen-du-lcof/
 * @Author  : Wei Li
 * @Date    : 2021-09-19
*/

#include <iostream>
#include <algorithm>

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
    }
};

// --------------------------------
int main(int argc, char **argv)
{
    // test on leetcode online.

    return 0;
}
