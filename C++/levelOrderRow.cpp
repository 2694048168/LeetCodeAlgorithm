/**
 * @File    : levelOrderRow.cpp
 * @Brief   : 从上到下打印二叉树 II
 * @Link    : https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof/
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
    std::vector<std::vector<int>> levelOrder(TreeNode *root)
    {
        if (!root)
            return std::vector<std::vector<int>>();
        std::queue<TreeNode *> myqueue;
        std::vector<std::vector<int>> ans;

        myqueue.push(root);
        while (!myqueue.empty())
        {
            std::vector<int> nums;
            for (int count = myqueue.size(); count > 0; count--)
            {
                TreeNode *top = myqueue.front();
                nums.push_back(top->val);
                if (top->left)
                    myqueue.push(top->left);
                if (top->right)
                    myqueue.push(top->right);
                myqueue.pop();
            }
            ans.push_back(move(nums));
        }
        return ans;
    }
};

// -------------------------------
int main(int argc, char **argv)
{
    // test on leetcode online.

    return 0;
}
