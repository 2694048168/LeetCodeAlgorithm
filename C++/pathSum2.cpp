/**
 * @File    : pathSum2.cpp
 * @Brief   : 二叉树中和为某一值的路径
 * @Link    : https://leetcode-cn.com/problems/er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof/
 * @Author  : Wei Li
 * @Date    : 2021-09-16
*/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
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
    std::vector<std::vector<int>> ret;
    std::unordered_map<TreeNode *, TreeNode *> parent;

    void getPath(TreeNode *node)
    {
        std::vector<int> tmp;
        while (node != nullptr)
        {
            tmp.emplace_back(node->val);
            node = parent[node];
        }
        std::reverse(tmp.begin(), tmp.end());
        ret.emplace_back(tmp);
    }

    std::vector<std::vector<int>> pathSum(TreeNode *root, int target)
    {
        if (root == nullptr)
        {
            return ret;
        }

        std::queue<TreeNode *> que_node;
        std::queue<int> que_sum;
        que_node.emplace(root);
        que_sum.emplace(0);

        while (!que_node.empty())
        {
            TreeNode *node = que_node.front();
            que_node.pop();
            int rec = que_sum.front() + node->val;
            que_sum.pop();

            if (node->left == nullptr && node->right == nullptr)
            {
                if (rec == target)
                {
                    getPath(node);
                }
            }
            else
            {
                if (node->left != nullptr)
                {
                    parent[node->left] = node;
                    que_node.emplace(node->left);
                    que_sum.emplace(rec);
                }
                if (node->right != nullptr)
                {
                    parent[node->right] = node;
                    que_node.emplace(node->right);
                    que_sum.emplace(rec);
                }
            }
        }

        return ret;
    }
};

// -----------------------------
int main(int argc, char **argv)
{
    // test on leetcode online.

    return 0;
}
