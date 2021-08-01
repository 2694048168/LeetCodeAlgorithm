/**
 * @File    : lowestCommonAncestor.cpp
 * @Brief   : 二叉搜索树的最近公共祖先
 * @Link    : https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        TreeNode *ancestor = root;
        while (true)
        {
            if (p->val < ancestor->val && q->val < ancestor->val)
            {
                ancestor = ancestor->left;
            }
            else if (p->val > ancestor->val && q->val > ancestor->val)
            {
                ancestor = ancestor->right;
            }
            else
            {
                break;
            }
        }
        return ancestor;
    }
};

// -------------------------------
int main(int argc, char **argv)
{
    // test on LeetCode online.

    return 0;
}
