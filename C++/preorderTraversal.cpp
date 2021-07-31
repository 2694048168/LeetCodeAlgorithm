/**
 * @File    : preorderTraversal.cpp
 * @Brief   : 二叉树的前序遍历
 * @Link    : https://leetcode-cn.com/problems/binary-tree-preorder-traversal/
 * @Author  : Wei Li
 * @Date    : 2021-07-31
*/

#include <iostream>
#include <vector>
#include <stack>

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
    std::vector<int> preorderTraversal(TreeNode *root)
    {
        std::vector<int> ret;
        if (!root)
        {
            return ret;
        }
        std::stack<TreeNode *> s;
        s.push(root);
        while (!s.empty())
        {
            TreeNode *node = s.top();
            s.pop();
            ret.push_back(node->val);
            if (node->right)
            {
                s.push(node->right); // 先右后左， 保证左子树先遍历
            }
            if (node->left)
            {
                s.push(node->left);
            }
        }
        return ret;
    }
};

// -------------------------------
int main(int argc, char **argv)
{
    // test on LeetCode online.

    return 0;
}
