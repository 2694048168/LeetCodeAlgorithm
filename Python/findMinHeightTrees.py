#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: findMinHeightTrees.py
@Function: 最小高度树
@Link: https://leetcode-cn.com/problems/minimum-height-trees/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-12
"""

import collections
from typing import List


class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        # 简单无向图：套路是建图并遍历
        # 建图：邻接表
        # 邻接表为map,其值为list,它的size就是入度数
        if n == 2:
            return [0, 1]
        if n == 1:
            return [0]

        adjs = collections.defaultdict(list)  # defaultdict写法很有用
        for x in edges:  # 图的邻接表表示法,基本是模板
            adjs[x[0]].append(x[1])  # 1:{2}
            adjs[x[1]].append(x[0])  # 2:{1}

        # BFS队列: 初始队列放入初始元素,size=1的为叶子,入队
        queue = collections.deque()  # 固定写法
        for key, value in adjs.items():
            if len(value) == 1:
                queue.append(key)

        # BFS两个大循环
        while(queue):  # 固定写法
            size = len(queue)  # 固定写法
            n = n - size

            for _ in range(size):
                v = queue.popleft()
                v_adj = adjs[v].pop()  # v的邻接仅一个,弹出即删除
                adjs[v_adj].remove(v)  # 在v的邻接元素的邻接列表里删除v
                if len(adjs[v_adj]) == 1:
                    queue.append(v_adj)

            if n == 1:
                return [queue.popleft()]
            if n == 2:
                return [queue.popleft(), queue.popleft()]


# --------------------------
if __name__ == "__main__":
    # test on LeetCode online.
    pass
