/**
 * @File    : levelOrder.cpp
 * @Brief   : 从上到下打印二叉树
 * @Link    : https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-lcof/
 * @Author  : Wei Li
 * @Date    : 2021-09-07
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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    std::vector<int> levelOrder(TreeNode *root)
    {
        std::vector<int> res;
        if (root == NULL)
            return res;
        std::queue<TreeNode *> q;
        q.emplace(root);
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            res.emplace_back(node->val);
            if (node->left)
                q.emplace(node->left);
            if (node->right)
                q.emplace(node->right);
        }
        return res;
    }
};

// ---------------------------------
int main(int argc, char **argv)
{
    // test on leetcode online.

    return 0;
}
