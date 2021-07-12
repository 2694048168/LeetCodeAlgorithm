/**
 * @File    : binaryTreePaths.cpp
 * @Brief   : 二叉树的所有路径
 * @Link    : https://leetcode-cn.com/problems/binary-tree-paths/
 * @Author  : Wei Li
 * @Date    : 2021-07-12
*/

#include <iostream>
#include <vector>
#include <string>
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

// 方法一：深度优先搜索
class Solution
{
public:
    void construct_paths(TreeNode *root, std::string path, std::vector<std::string> &paths)
    {
        if (root != nullptr)
        {
            path += std::to_string(root->val);
            if (root->left == nullptr && root->right == nullptr)
            {                          // 当前节点是叶子节点
                paths.push_back(path); // 把路径加入到答案中
            }
            else
            {
                path += "->"; // 当前节点不是叶子节点，继续递归遍历
                construct_paths(root->left, path, paths);
                construct_paths(root->right, path, paths);
            }
        }
    }

    std::vector<std::string> binaryTreePaths(TreeNode *root)
    {
        std::vector<std::string> paths;
        construct_paths(root, "", paths);
        return paths;
    }
};

// 方法二：广度优先搜索
class Solution
{
public:
    std::vector<std::string> binaryTreePaths(TreeNode *root)
    {
        std::vector<std::string> paths;
        if (root == nullptr)
        {
            return paths;
        }
        std::queue<TreeNode *> node_queue;
        std::queue<std::string> path_queue;

        node_queue.push(root);
        path_queue.push(std::to_string(root->val));

        while (!node_queue.empty())
        {
            TreeNode *node = node_queue.front();
            std::string path = path_queue.front();
            node_queue.pop();
            path_queue.pop();

            if (node->left == nullptr && node->right == nullptr)
            {
                paths.push_back(path);
            }
            else
            {
                if (node->left != nullptr)
                {
                    node_queue.push(node->left);
                    path_queue.push(path + "->" + std::to_string(node->left->val));
                }

                if (node->right != nullptr)
                {
                    node_queue.push(node->right);
                    path_queue.push(path + "->" + std::to_string(node->right->val));
                }
            }
        }
        return paths;
    }
};

// --------------------------------
int main(int argc, char **argv)
{
    // test on LeetCode online.

    return 0;
}
