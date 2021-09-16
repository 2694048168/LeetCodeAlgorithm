/**
 * @File    : kthLargest.cpp
 * @Brief   : 二叉搜索树的第k大节点
 * @Link    : https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof/
 * @Author  : Wei Li
 * @Date    : 2021-09-16
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
    int res;
    int kthLargest(TreeNode *root, int k)
    {
        dfs(root, k);
        return res;
    }
    void dfs(TreeNode *root, int &k) //传引用 这里需要保证所有dfs函数共用一个k
    {
        if (!root)
            return;
        dfs(root->right, k); //右
        k--;
        if (!k)
            res = root->val; //根
        dfs(root->left, k);  //左
    }
};

// -------------------------------
int main(int argc, char **argv)
{
    // test on leetcode online.

    return 0;
}
