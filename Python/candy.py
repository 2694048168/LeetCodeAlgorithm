#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: candy.py
@Function: 分发糖果 贪心策略
@Link: https://leetcode-cn.com/problems/candy/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-04
"""

# --------------------------------------------------------------
class Solution2:
    """0、只需要简单的两次遍历即可：把所有孩子的糖果数初始化为 1；
    1、先从左往右遍历一遍，如果右边孩子的评分比左边的高，
       则右边孩子的糖果数更新为左边孩子的糖果数加 1；
    2、再从右往左遍历一遍，如果左边孩子的评分比右边的高，且左边孩子当前的糖果数不大于右边孩子的糖果数，
       则左边孩子的糖果数更新为右边孩子的糖果数加 1。
    3、通过这两次遍历，分配的糖果就可以满足题目要求了。

   这里的贪心策略即为，在每次遍历中，只考虑并更新相邻一侧的大小关系。
    """
    def candy(self, ratings):
        # 若只有一个人，则最少需要一个糖果
        if len(ratings) < 2:
            return len(ratings)
        
        # 初始化每个人一个糖果   
        left = [1 for _ in range(len(ratings))]
        right = left[:]

        # 第一次遍历，从左往右
        for i in range(1, len(ratings)):
            if ratings[i] > ratings[i - 1]:
                # 如果右边的评分高于左边，则其糖果数量等于其左边的糖果数量 + 1
                left[i] = left[i - 1] + 1
        
        # 计算需要的最小糖果数量
        # 因为后面累加计算时索引不到最后一个
        count = left[-1]

        # 第二次遍历，从右往左
        for i in range(len(ratings) - 2, -1, -1):
            # 如果左边的评分高于右边，则左边孩子的糖果数更新为右边孩子的糖果数 + 1
            if ratings[i] > ratings[i + 1]:
                right[i] = right[i + 1] + 1
            
            # 不断累加需要的最小糖果数量
            # 每次具体位置的值，取从左往右遍历 和 从右往左遍历 的最大值
            count += max(left[i], right[i])
        return count

# --------------------------------------------------------------
class Solution:
    def candy(self, ratings):
        # 初始化每个人一个糖果 
        nums = [1] * len(ratings)

        # 第一次遍历，从左往右
        for i in range(0, len(ratings)-1):
            # 如果右边的评分高于左边，则其糖果数量等于其左边的糖果数量 + 1
            if ratings[i] < ratings[i+1]:
                nums[i+1] = nums[i] + 1

        # 第二次遍历，从右往左        
        for i in range(len(ratings)-1, 0, -1):
            # 如果左边的评分高于右边，
            if ratings[i] < ratings[i-1]:
                # 且左边孩子当前的糖果数不大于右边孩子的糖果数
                if nums[i] > nums[i-1] or nums[i] == nums[i-1]:
                    # 左边孩子的糖果数更新为右边孩子的糖果数 + 1
                    nums[i-1] = nums[i] + 1
        return sum(nums)


if __name__ == "__main__":
    ratings = [1, 0, 2]
    # ratings = [1, 2, 2]

    solution = Solution()
    num_candy = solution.candy(ratings)
    print(f"The solution of this problem is : {num_candy}")