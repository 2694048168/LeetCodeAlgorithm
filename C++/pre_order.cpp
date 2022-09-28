/**
 * @file pre_order.cpp
 * @author Wei Li (weili_yzzcq@163.com)
 * @brief N 叉树(二叉树)的前序遍历
 * @LeetCode Link https://leetcode.cn/problems/n-ary-tree-preorder-traversal/
 * @version 0.1
 * @date 2022-09-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <vector>


// Definition for a Node.
class Node {
public:
    int val;
    std::vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, std::vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution 
{
public:
    void helper(const Node* root, std::vector<int> & result)
    {
        if (root == nullptr)
        {
            return;
        }
        result.emplace_back(root->val);
        for (auto &ch : root->children)
        {
            helper(ch, result);
        }
    }

    std::vector<int> preorder(Node* root) 
    {
        std::vector<int> result;
        helper(root, result);

        return result;
    }
};


// -------------------------------------
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
