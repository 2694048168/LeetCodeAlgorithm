/**
 * @File    : isSubtree.cpp
 * @Brief   : 另一棵树的子树
 * @Link    : https://leetcode-cn.com/problems/subtree-of-another-tree/
 * @Author  : Wei Li
 * @Date    : 2021-08-01
*/

#include <iostream>
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

class Solution
{
public:
    static constexpr int MAX_N = 1000 + 5;
    static constexpr int MOD = int(1E9) + 7;

    bool vis[MAX_N];
    int p[MAX_N], tot;
    void getPrime()
    {
        vis[0] = vis[1] = 1;
        tot = 0;
        for (int i = 2; i < MAX_N; ++i)
        {
            if (!vis[i])
                p[++tot] = i;
            for (int j = 1; j <= tot && i * p[j] < MAX_N; ++j)
            {
                vis[i * p[j]] = 1;
                if (i % p[j] == 0)
                    break;
            }
        }
    }

    struct Status
    {
        int f, s; // f 为哈希值 | s 为子树大小
        Status(int f_ = 0, int s_ = 0)
            : f(f_), s(s_) {}
    };

    std::unordered_map<TreeNode *, Status> hS, hT;

    void dfs(TreeNode *o, std::unordered_map<TreeNode *, Status> &h)
    {
        h[o] = Status(o->val, 1);
        if (!o->left && !o->right)
            return;
        if (o->left)
        {
            dfs(o->left, h);
            h[o].s += h[o->left].s;
            h[o].f = (h[o].f + (31LL * h[o->left].f * p[h[o->left].s]) % MOD) % MOD;
        }
        if (o->right)
        {
            dfs(o->right, h);
            h[o].s += h[o->right].s;
            h[o].f = (h[o].f + (179LL * h[o->right].f * p[h[o->right].s]) % MOD) % MOD;
        }
    }

    bool isSubtree(TreeNode *s, TreeNode *t)
    {
        getPrime();
        dfs(s, hS);
        dfs(t, hT);

        int tHash = hT[t].f;
        for (const auto &[k, v] : hS)
        {
            if (v.f == tHash)
            {
                return true;
            }
        }

        return false;
    }
};

// ----------------------------
int main(int argc, char **argv)
{
    // test on LeetCode online.

    return 0;
}
