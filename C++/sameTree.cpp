/**
 * LeetCodeLink ： https://leetcode-cn.com/problems/same-tree/
 * 
 * 100. 相同的树
 * 给定两个二叉树，编写一个函数来检验它们是否相同
 * 如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
 * 
 * 示例 1:
 * 输入:       1         1
             / \       / \
            2   3     2   3

            [1,2,3],   [1,2,3]
 * 输出: true
 * 
 * 示例 2:
输入:      1          1
          /           \
         2             2

        [1,2],     [1,null,2]

 * 输出: false
 */

//![include]
#include <iostream>
// 队列 数据结构
#include <queue>

using std::queue;
//![include]

//![TreeNode class]
// Definition for a binary tree node.
// struct has the public priority authority of Class
struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;

    // 三种默认构造函数
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//![TreeNode class]

//![solution]

/**
 * solution 1：深度优先搜索  Depth First Search, DFS
 * 0、如果两个二叉树都为空，则两个二叉树相同
 * 1、如果两个二叉树中有且只有一个为空，则两个二叉树一定不相同
 * 2、如果两个二叉树都不为空，那么首先判断它们的根节点的值是否相同，若不相同则两个二叉树一定不同，
 *   若相同，再分别判断两个二叉树的左子树是否相同以及右子树是否相同
 * 这是一个递归的过程，因此可以使用深度优先搜索，递归地判断两个二叉树是否相同
 * 
 * 复杂度分析：
 * 时间复杂度：T(n) = big O(min(m,n))，其中 m 和 n 分别是两个二叉树的节点数
 * 对两个二叉树同时进行深度优先搜索，只有当两个二叉树中的对应节点都不为空时才会访问到该节点，
 * 因此被访问到的节点数不会超过较小的二叉树的节点数
 * 
 * 空间复杂度：S(n) = big O(min(m,n))，其中 m 和 n 分别是两个二叉树的节点数
 * 空间复杂度取决于递归调用的层数，递归调用的层数不会超过较小的二叉树的最大高度，
 * 最坏情况下，二叉树的高度等于节点数
 */
class Solution1
{
public:
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        // 两棵树都为空，则一定相等
        if (p == nullptr && q == nullptr)
        {
            return true;
        } 
        // 仅有其中一棵树为空，则一定不相等
        else if (p == nullptr || q == nullptr) 
        {
            return false;
        }
        // 根root 节点的值不相等，则两棵树一定不相等
        else if (p->val != q->val) 
        {
            return false;
        } 
        // 进行递归判断左右子树，左右子树同时相等，则两棵树相等
        // DFS 的核心思想
        else 
        {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
    }
};


/**
 * solution 2：广度优先搜索  Breadth First Search, BFS
 * 0、首先判断两个二叉树是否为空，如果两个二叉树都不为空，则从两个二叉树的根节点开始广度优先搜索
 * 1、使用两个队列分别存储两个二叉树的节点。
 *   初始时将两个二叉树的根节点分别加入两个队列。
 *  每次从两个队列各取出一个节点，进行如下比较操作：
 *    0、比较两个节点的值，如果两个节点的值不相同则两个二叉树一定不同；
 *    1、如果两个节点的值相同，则判断两个节点的子节点是否为空，如果只有一个节点的左子节点为空，
 *       或者只有一个节点的右子节点为空，则两个二叉树的结构不同，因此两个二叉树一定不同；
 *    2、如果两个节点的子节点的结构相同，则将两个节点的非空子节点分别加入两个队列，
 *       子节点加入队列时需要注意顺序，如果左右子节点都不为空，则先加入左子节点，后加入右子节点
 * 2、如果搜索结束时两个队列同时为空，则两个二叉树相同。
 * 3、如果只有一个队列为空，则两个二叉树的结构不同，因此两个二叉树不同。
 * 
 * 复杂度分析：
 * 时间复杂度：T(n) = big O(min(m,n))，其中 m 和 n 分别是两个二叉树的节点数
 * 对两个二叉树同时进行广度优先搜索，只有当两个二叉树中的对应节点都不为空时才会访问到该节点，
 * 因此被访问到的节点数不会超过较小的二叉树的节点数。
 * 
 * 空间复杂度：S(n) = big O(min(m,n))，其中 m 和 n 分别是两个二叉树的节点数
 * 空间复杂度取决于队列中的元素个数，队列中的元素个数不会超过较小的二叉树的节点数
 */
class Solution2
{
public:
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        // 两棵树都为空，则一定相等
        if (p == nullptr && q == nullptr) 
        {
            return true;
        }
        // 仅有其中一棵树为空，则一定不相等
        else if (p == nullptr || q == nullptr) 
        {
            return false;
        }
        queue <TreeNode*> queue1, queue2;
        queue1.push(p);
        queue2.push(q);
        // 两棵树同时非空，则进行广度搜索
        while (!queue1.empty() && !queue2.empty()) 
        {
            auto node1 = queue1.front();
            queue1.pop();
            auto node2 = queue2.front();
            queue2.pop();
            // root 节点的值不相等，则两棵树一定不相等
            if (node1->val != node2->val) 
            {
                return false;
            }
            auto left1 = node1->left, right1 = node1->right, left2 = node2->left, right2 = node2->right;
            // ^ 位运算操作，异或；相同则为 0；不同则为 1
            // 仅有其中一棵树为左子树为空，则两棵树结构不同，一定不相等
            if ((left1 == nullptr) ^ (left2 == nullptr)) 
            {
                return false;
            }
            // ^ 位运算操作，异或；相同则为 0；不同则为 1
            // 仅有其中一棵树为右子树为空，则两棵树结构不同，一定不相等
            if ((right1 == nullptr) ^ (right2 == nullptr)) 
            {
                return false;
            }
            // 如果左子树不为空，则进行递归操作
            if (left1 != nullptr) 
            {
                queue1.push(left1);
            }
            // 如果右子树不为空，则进行递归操作
            if (right1 != nullptr) 
            {
                queue1.push(right1);
            }
            // 如果左子树不为空，则进行递归操作
            if (left2 != nullptr) 
            {
                queue2.push(left2);
            }
            // 如果右子树不为空，则进行递归操作
            if (right2 != nullptr) 
            {
                queue2.push(right2);
            }
        }
        // 搜索结束后，同时为空，则一定相等
        return queue1.empty() && queue2.empty();
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

