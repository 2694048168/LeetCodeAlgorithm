/**
 * LeetCodeLink ： https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/
 * 
 * 111. 二叉树的最小深度
 * 给定一个二叉树，找出其最小深度。
 * 最小深度是从根节点到最近叶子节点的最短路径上的节点数量
 * 
 * 说明: 叶子节点是指没有子节点的节点
 * 
 * 示例:
 * 给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
 
 * 返回它的最小深度 2
 */

//![include]
#include <iostream>
#include <algorithm>
#include <queue>

//![include]

//![TreeNode class]
// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//![TreeNode class]

//![solution]

/**
 * solution 1：深度优先搜索 DFS
 * 首先可以想到使用深度优先搜索的方法，遍历整棵树，记录最小深度
 * 对于每一个非叶子节点，只需要分别计算其左右子树的最小叶子节点深度,
 * 这样就将一个大问题转化为了小问题，可以递归地解决该问题
 * 
 * 时间复杂度：T(n) = big O(N)，其中 N 是树的节点数,对每个节点访问一次
 * 空间复杂度：S(n) = big O(H)，其中 H 是树的高度
 * 空间复杂度主要取决于递归时栈空间的开销，最坏情况下，树呈现链状，空间复杂度为 S(n) = O(N);
 * 平均情况下树的高度与节点数的对数正相关，空间复杂度为 S(n) = O(log(N))
 */
class Solution1
{
public:
    int minDepth(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        if (root->left == nullptr && root->right == nullptr)
        {
            return 1;
        }

        int min_depth = INT_MAX;
        if (root->left != nullptr)
        {
            min_depth = std::min(minDepth(root->left), min_depth);
        }
        if (root->right != nullptr)
        {
            min_depth = std::min(minDepth(root->right), min_depth);
        }

        return min_depth + 1;
    }
};

/**
 * solution 2：广度优先搜索 BFS
 * 可以想到使用广度优先搜索的方法，遍历整棵树
 * 当找到一个叶子节点时，直接返回这个叶子节点的深度
 * 广度优先搜索的性质保证了最先搜索到的叶子节点的深度一定最小
 * 
 * 时间复杂度：T(n) = big O(N)，其中 N 是树的节点数,对每个节点访问一次
 * 空间复杂度：S(n) = big O(N)，其中 N 是树的节点数
 * 空间复杂度主要取决于队列的开销，队列中的元素个数不会超过树的节点数
 */
class Solution2
{
public:
    int minDepth(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        std::queue<std::pair<TreeNode *, int>> que;
        que.emplace(root, 1);
        while (!que.empty())
        {
            TreeNode *node = que.front().first;
            int depth = que.front().second;
            que.pop();
            if (node->left == nullptr && node->right == nullptr)
            {
                return depth;
            }
            if (node->left != nullptr)
            {
                que.emplace(node->left, depth + 1);
            }
            if (node->right != nullptr)
            {
                que.emplace(node->right, depth + 1);
            }
        }

        return 0;
    }
};
//![solution]

/**
 * @function Main function
 */
int main(int argc, char **argv)
{
    // [test]

    return 0;
}
