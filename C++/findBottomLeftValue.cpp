/**
 * @File    : findBottomLeftValue.cpp
 * @Brief   : 找树左下角的值
 * @Link    : https://leetcode-cn.com/problems/find-bottom-left-tree-value/
 * @Author  : Wei Li
 * @Date    : 2021-08-01
*/

#include <iostream>
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
    int findBottomLeftValue(TreeNode *root)
    {
        std::queue<TreeNode *> que;
        if (root != NULL)
            que.push(root);
        int result = 0;
        while (!que.empty())
        {
            int size = que.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = que.front();
                que.pop();
                if (i == 0)
                    result = node->val; // 记录最后一行第一个元素
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
            }
        }
        return result;
    }
};

int main(int argc, char **argv)
{
    // test on LeetCode online.

    return 0;
}
