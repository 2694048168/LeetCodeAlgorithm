#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: permute.py
@Function: 全排列 回溯算法
@Link: https://leetcode-cn.com/problems/permutations/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-11
"""

"""
/**
 * 回溯法（backtracking）是优先搜索的一种特殊情况，又称为试探法，常用于需要记录节点状态的深度优先搜索。
 * 通常来说，排列、组合、选择类问题使用回溯法比较方便。
 * 顾名思义，回溯法的核心是回溯。在搜索到某一节点的时候，如果发现目前的节点（及其子节点）并不是需求目标时，
 * 回退到原来的节点继续搜索，并且把在目前节点修改的状态还原。
 * 这样的好处是我们可以始终只对图的总状态进行修改，而非每次遍历时新建一个图来储存状态。
 * 
 * 在具体的写法上，它与普通的深度优先搜索一样，都有 [修改当前节点状态]![递归子节点] 的步骤，
 * 只是多了回溯的步骤，变成了 [修改当前节点状态]![递归子节点]![回改当前节点状态]。
 * 
 * 可以记住两个小诀窍， 一是按引用传状态， 二是所有的状态修改在递归完成后回改。
 * 回溯法修改一般有两种情况，一种是修改最后一位输出，比如排列组合；一种是修改访问标记，比如矩阵里搜字符串
 */
"""


class Solution:
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        def backtrack(first=0):
            # 所有数都填完了
            if first == n:
                res.append(nums[:])
            for i in range(first, n):
                # 动态维护数组
                nums[first], nums[i] = nums[i], nums[first]
                # 继续递归填下一个数
                backtrack(first + 1)
                # 撤销操作
                nums[first], nums[i] = nums[i], nums[first]

        n = len(nums)
        res = []
        backtrack()
        return res


# -------------------------
if __name__ == "__main__":
    nums = [1, 2, 3]

    solution = Solution()
    permute_list = solution.permute(nums=nums)
    print(f"The solution of this problem is : {permute_list}")
