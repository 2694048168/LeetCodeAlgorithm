/**
 * @File    : constructFromPrePost.cpp
 * @Brief   : 根据前序和后序遍历构造二叉树
 * @Link    : https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/
 * @Author  : Wei Li
 * @Date    : 2021-08-02
*/

#include <iostream>
#include <vector>
#include <unordered_map>

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

//根据前序遍历和后序遍历构建二叉树
class Solution
{
public:
    //前序遍历：[中，左，右]
    //后序遍历：[左，右，中]
    std::unordered_map<int, int> ump;
    TreeNode *pp(std::vector<int> &pre, std::vector<int> &post, int preleft, int preright, int postleft, int postright)
    {
        if (preleft > preright || postleft > postright)
        {
            return nullptr;
        }
        int val = pre[preleft];
        TreeNode *root = new TreeNode(val);
        int index = 0;
        if (preleft + 1 > preright)
        {
            return root;
        }
        for (int i = postleft; i < postright; i++)
        {
            if (pre[preleft + 1] == post[i])
            {
                index = i;
                break;
            }
        }
        int cnt = index - postleft + 1;
        root->left = pp(pre, post, preleft + 1, preleft + cnt, postleft, postleft + cnt - 1);
        root->right = pp(pre, post, preleft + cnt + 1, preright, postleft + cnt, postright - 1);
        return root;
    }
    TreeNode *constructFromPrePost(std::vector<int> &pre, std::vector<int> &post)
    {
        int len = post.size();
        for (int i = 0; i < post.size(); i++)
        {
            ump[post[i]] = i;
        }
        return pp(pre, post, 0, len - 1, 0, len - 1);
    }
};

// ----------------------------
int main(int argc, char **argv)
{
    // test on LeetCode online.

    return 0;
}
