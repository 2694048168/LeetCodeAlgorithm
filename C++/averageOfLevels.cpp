/**
 * @File    : averageOfLevels.cpp
 * @Brief   : 二叉树的层平均值
 * @Link    : https://leetcode-cn.com/problems/average-of-levels-in-binary-tree/
 * @Author  : Wei Li
 * @Date    : 2021-07-31
*/

#include <iostream>
#include <vector>
#include <queue>

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
    std::vector<double> averageOfLevels(TreeNode *root)
    {
        std::vector<double> ans;
        if (!root)
        {
            return ans;
        }
        std::queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int count = q.size();
            double sum = 0;
            for (int i = 0; i < count; ++i)
            {
                TreeNode *node = q.front();
                q.pop();
                sum += node->val;
                if (node->left)
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }
            }
            ans.push_back(sum / count);
        }
        return ans;
    }
};

// ----------------------------
int main(int argc, char **argv)
{
    // test on LeetCode online.

    return 0;
}
