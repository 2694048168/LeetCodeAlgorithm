/**
 * @File    : findTarget2.cpp
 * @Brief   : 两数之和 IV - 输入 BST
 * @Link    : https://leetcode-cn.com/problems/two-sum-iv-input-is-a-bst/
 * @Author  : Wei Li
 * @Date    : 2021-08-02
*/

#include <iostream>
#include <vector>

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
private:
    void InOrder(TreeNode *root, std::vector<int> &res)
    {
        if (root != nullptr)
        {
            InOrder(root->left, res);
            res.push_back(root->val);
            InOrder(root->right, res);
        }
    }

public:
    bool findTarget(TreeNode *root, int k)
    {
        std::vector<int> res;
        InOrder(root, res);

        int l = 0;
        int r = res.size() - 1;
        while (l < r)
        {
            int sum = res[l] + res[r];
            if (sum == k)
            {
                return true;
            }
            else if (sum < k)
            {
                ++l;
            }
            else
            {
                --r;
            }
        }

        return false;
    }
};

// ================================
int main(int argc, char **argv)
{

    return 0;
}
