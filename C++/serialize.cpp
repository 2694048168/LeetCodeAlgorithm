/**
 * @File    : serialize.cpp
 * @Brief   : 序列化二叉树
 * @Link    : https://leetcode-cn.com/problems/xu-lie-hua-er-cha-shu-lcof/
 * @Author  : Wei Li
 * @Date    : 2021-09-29
*/

#include <iostream>
#include <string>
#include <list>

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
public:
    void rserialize(TreeNode *root, std::string &str)
    {
        if (root == nullptr)
        {
            str += "None,";
        }
        else
        {
            str += std::to_string(root->val) + ",";
            rserialize(root->left, str);
            rserialize(root->right, str);
        }
    }

    std::string serialize(TreeNode *root)
    {
        std::string ret;
        rserialize(root, ret);
        return ret;
    }

    TreeNode *rdeserialize(std::list<std::string> &dataArray)
    {
        if (dataArray.front() == "None")
        {
            dataArray.erase(dataArray.begin());
            return nullptr;
        }

        TreeNode *root = new TreeNode(std::stoi(dataArray.front()));
        dataArray.erase(dataArray.begin());
        root->left = rdeserialize(dataArray);
        root->right = rdeserialize(dataArray);
        return root;
    }

    TreeNode *deserialize(std::string data)
    {
        std::list<std::string> dataArray;
        std::string str;
        for (auto &ch : data)
        {
            if (ch == ',')
            {
                dataArray.push_back(str);
                str.clear();
            }
            else
            {
                str.push_back(ch);
            }
        }
        if (!str.empty())
        {
            dataArray.push_back(str);
            str.clear();
        }
        return rdeserialize(dataArray);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
// -----------------------------
int main(int argc, char **argv)
{
    // test on leetcode online.

    return 0;
}
