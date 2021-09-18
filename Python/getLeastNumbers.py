#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: getLeastNumbers.py
@Function: 最小的k个数
@Link: https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-09-18
"""

from typing import List
import heapq


class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        if k == 0:
            return list()

        hp = [-x for x in arr[:k]]
        heapq.heapify(hp)
        for i in range(k, len(arr)):
            if -hp[0] > arr[i]:
                heapq.heappop(hp)
                heapq.heappush(hp, -arr[i])
        ans = [-x for x in hp]
        return ans


# ----------------------------------
if __name__ == "__main__":
    arr = [3,2,1]
    k = 2

    solution = Solution()
    get_leaest_number = solution.getLeastNumbers(arr, k)
    print(f"The solution of this problem is {get_leaest_number}")
