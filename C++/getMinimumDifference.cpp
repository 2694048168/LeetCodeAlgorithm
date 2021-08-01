/**
 * @File    : getMinimumDifference.cpp
 * @Brief   : 二叉搜索树的最小绝对差
 * @Link    : https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst/
 * @Author  : Wei Li
 * @Date    : 2021-08-01
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
    void dfs(TreeNode *root, int &pre, int &ans)
    {
        if (root == nullptr)
        {
            return;
        }
        dfs(root->left, pre, ans);
        if (pre == -1)
        {
            pre = root->val;
        }
        else
        {
            ans = std::min(ans, root->val - pre);
            pre = root->val;
        }
        dfs(root->right, pre, ans);
    }
    int getMinimumDifference(TreeNode *root)
    {
        int ans = INT_MAX, pre = -1;
        dfs(root, pre, ans);
        return ans;
    }
};

// ----------------------------
int main(int argc, char **argv)
{
    // test on LeetCode online.

    return 0;
}
