#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: twoSum.py
@Function: 两数之和
@Link: https://leetcode-cn.com/problems/two-sum/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-04
"""

# --------------------------------------
class Solution1:
    """
    暴力穷举法，使用两个 for 循环即可实现
    遍历每个元素 x，并查找是否存在一个值与 target - x 相等的目标元素
    时间复杂度：big O(n**2)
    空间复杂度：big O(1)

    仔细观察，时间复杂度和空间复杂度权衡
    时间复杂度的提升是以空间复杂度为代价的
    """

    def twoSum(self, nums, target):
        index = []
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                if nums[i] + nums[j] == target:
                    return [i,j]
    

# ---------------------------------
class Solution2:
    """
    元素和下标，键值对方式储存,字典数据结构
    遍历键值对的键 key，并查找是否存在一个值与 target - key 相等的键值对应的value即为所求下标
    时间复杂度：big O(n)
    空间复杂度：big O(1)

    仔细观察，时间复杂度和空间复杂度权衡
    时间复杂度的提升是以空间复杂度为代价的
    """

    def twoSum(self, nums, target):
        map_dict = dict()
        ret = list()
        for item in range(len(nums)):
            map_dict[nums[item]] = item
        
        for i in range(len(nums)):
            temp = target - nums[i]
            if temp in map_dict.keys() and map_dict[temp] != i:
                ret.append(i)
                ret.append(map_dict[temp])
                break;

        return ret


# ------------------------------
class Solution3:
    """
    enumerate 遍历 list，
    将一个可遍历的数据对象(如列表、元组或字符串)
    组合为一个索引序列，同时列出数据和数据下标，一般用在 for 循环当中 
    
    组合数据和数据下标思想！！！
    算法核心思想与 solution2 一致，只不过使用Python 内置函数 enumerate 实现
    """
    def twoSum(self, nums, target):
        dict = {}
        # enumerate 内置函数，常用 for 循环遍历一个容器/迭代器
        # 参数 sequence -- 一个序列、迭代器或其他支持迭代对象
        # 参数 start -- 下标起始位置
        # 返回值 返回 enumerate(枚举) 对象
        for i,n in enumerate(nums,0):
            if target - n in dict:
                return [dict[target-n],i]
            dict[n] = i
             
# -----------------------------------------------------
# The key to the problem is that there is ALWAYS only 1 pair of numbers that satisfy the condition of adding together to be the target value.
# We can assume that for all the numbers in the list (x1, x2, ... xn) that there exists a pair such that xa + xb = target
# To solve this with a single pass of the list we can change the equation above to xa = target - xb and since we know the target as long as we maintain a record of all previous values in the list we can compare the current value (xa) to it's ONLY pair, if it exists, in record of all previous values (xb)

# To keep a record of the previous values and their indices I have used a dictionary. Commonly known as a map in other languages. This allows me to record each previous number in the dictionary alongside the indice as a key value pair (target-number, indice).
# -----------------------------------------------------
# https://leetcode.com/problems/can-place-flowers/
# https://leetcode-cn.com/problems/can-place-flowers/
# 可以查看高手的解答，学习，(中文的-cn/), 国外的高手解答，选择【 Most Votes 】
# -----------------------------------------------------


# --------------------------------
if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 9
    # solution = Solution1()
    # solution = Solution2()
    solution = Solution3()
    print(solution.twoSum(nums, target))