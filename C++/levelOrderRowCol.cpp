/**
 * @File    : levelOrderRowCol.cpp
 * @Brief   : 从上到下打印二叉树 III
 * @Link    : https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-iii-lcof/
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
        std::vector<std::vector<int>> res;
        std::vector<int> temp;
        if (root == NULL)
            return res;
        std::queue<TreeNode *> q;
        q.emplace(root);
        while (!q.empty())
        {
            int len = q.size();
            while (len--)
            {
                TreeNode *node = q.front();
                q.pop();
                temp.emplace_back(node->val);
                if (node->left)
                    q.emplace(node->left);
                if (node->right)
                    q.emplace(node->right);
            }
            res.emplace_back(temp);
            temp.clear();
        }
        for (int i = 1; i < res.size(); i += 2)
            reverse(res[i].begin(), res[i].end());
        return res;
    }
};

class Solution {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        //1.双向队列
        /*
        if(!root) return vector<vector<int>>();
        int direc = 1;
        queue<TreeNode*> mydeque;
        vector<vector<int>> ans;

        mydeque.push(root);
        while(!mydeque.empty()){
            deque<int> nums;
            for(int count=mydeque.size();count>0;count--){
                TreeNode* top = mydeque.front();
                //不改变结点入mydeque的顺序，而应该改变结点入nums的顺序
                if(direc==1) 
                    nums.push_back(top->val);
                else
                    nums.push_front(top->val);
                if(top->left) mydeque.push(top->left);
                if(top->right) mydeque.push(top->right);
                mydeque.pop();
            }
            ans.push_back(move(vector<int>(nums.begin(),nums.end())));
            direc = -direc;
        }
        return ans;
        */
        //2.reverse函数
        if(!root) return std::vector<std::vector<int>>();
        int direc = 1;
        std::queue<TreeNode*> myqueue;
        std::vector<std::vector<int>> ans;
        
        myqueue.push(root);
        while(!myqueue.empty()){
            std::vector<int> nums;
            for(int count = myqueue.size();count>0;count--){
                TreeNode* top = myqueue.front();
                nums.push_back(top->val);
                if(top->left) myqueue.push(top->left);
                if(top->right) myqueue.push(top->right);
                myqueue.pop();
            }
            if(direc==-1) reverse(nums.begin(),nums.end()) ;
            ans.push_back(move(nums));            
            direc  = -direc;
        }
        return ans;

    }
    
};

// -----------------------------
int main(int argc, char **argv)
{
    // test on leetcode online.

    return 0;
}
