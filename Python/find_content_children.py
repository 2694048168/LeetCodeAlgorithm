#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: find_content_children.py
@Function: 分发饼干 贪心策略(每个局部之间要求独立，不相关)
@Link: https://leetcode-cn.com/problems/assign-cookies/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-04
"""

# ---------------------------------------------
class Solution:
    """solution 贪心算法或贪心思想采用贪心的策略

    至于具体实现，因为需要获得大小关系，一个便捷的方法就是把孩子和饼干分别排序。
    这样就可以从饥饿度最小的孩子和大小最小的饼干出发，计算有多少个对子可以满足条件。
    """
    def findContentChildren(self, children, cookies):
        children = sorted(children, reverse=False)
        cookies = sorted(cookies,reverse=False)

        child = 0
        cookie = 0
        while (child != len(children) and cookie != len(cookies)):
            # 满足条件的情况
            if children[child] <= cookies[cookie]:
                child += 1
            
            cookie += 1
        
        return child


# --------------------------------
if __name__ == "__main__":
    # children = [1, 32, 2, 5, 6]
    # cookies = [1, 2, 3, 30, 6]

    children = [1, 3, 2]
    cookies = [1, 1]

    solution = Solution()
    num_child = solution.findContentChildren(children, cookies)
    print(f"The solution of this problem is : {num_child}")