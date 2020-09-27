#
# LeetCodeLink ： https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/
#
# 111. 二叉树的最小深度
#  给定一个二叉树，找出其最小深度。
#  最小深度是从根节点到最近叶子节点的最短路径上的节点数量
#  
#  说明: 叶子节点是指没有子节点的节点
#  
#  示例:
#  给定二叉树 [3,9,20,null,null,15,7],
#
#     3
#    / \
#   9  20
#     /  \
#    15   7
#
# 返回它的最小深度 2
#

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution1:
    """
    solution 1：深度优先搜索 DFS
    # 首先可以想到使用深度优先搜索的方法，遍历整棵树，记录最小深度
    # 对于每一个非叶子节点，只需要分别计算其左右子树的最小叶子节点深度,
    # 这样就将一个大问题转化为了小问题，可以递归地解决该问题
    # 
    # 时间复杂度：T(n) = big O(N)，其中 N 是树的节点数,对每个节点访问一次
    # 空间复杂度：S(n) = big O(H)，其中 H 是树的高度
    # 空间复杂度主要取决于递归时栈空间的开销，最坏情况下，树呈现链状，空间复杂度为 S(n) = O(N);
    # 平均情况下树的高度与节点数的对数正相关，空间复杂度为 S(n) = O(log(N))
    """

    def minDepth(self, root):
        if not root:
            return 0
        
        if not root.left and not root.right:
            return 1
        
        min_depth = 10**9
        if root.left:
            min_depth = min(self.minDepth(root.left), min_depth)
        if root.right:
            min_depth = min(self.minDepth(root.right), min_depth)
        
        return min_depth + 1


class Solution2:
    """
    solution 2：广度优先搜索 BFS
    # 可以想到使用广度优先搜索的方法，遍历整棵树
    # 当找到一个叶子节点时，直接返回这个叶子节点的深度
    # 广度优先搜索的性质保证了最先搜索到的叶子节点的深度一定最小
    #  
    # 时间复杂度：T(n) = big O(N)，其中 N 是树的节点数,对每个节点访问一次
    # 空间复杂度：S(n) = big O(N)，其中 N 是树的节点数
    # 空间复杂度主要取决于队列的开销，队列中的元素个数不会超过树的节点数
    """
    def minDepth(self, root):
        if not root:
            return 0

        que = collections.deque([(root, 1)])
        while que:
            node, depth = que.popleft()
            if not node.left and not node.right:
                return depth
            if node.left:
                que.append((node.left, depth + 1))
            if node.right:
                que.append((node.right, depth + 1))
        
        return 0


if __name__ == "__main__":
    pass