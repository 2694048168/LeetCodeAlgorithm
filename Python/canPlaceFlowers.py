#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: canPlaceFlowers.py
@Function: 种花问题 贪心策略
@Link: https://leetcode-cn.com/problems/can-place-flowers/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-05
"""

# ------------------
class Solution:
    def canPlaceFlowers(self, flowerbed, n):
        count, prev = 0, -1
        for i in range(len(flowerbed)):
            if flowerbed[i] == 1:
                if prev < 0:
                    count += i // 2
                else:
                    count += (i - prev -2) // 2
                
                if count >= n:
                    return True

                prev = i

        if prev < 0:
            count += (len(flowerbed) + 1) // 2
        else:
            count += (len(flowerbed) - prev - 1) // 2

        return count >= n


# ---------------------------
if __name__ == "__main__":
    flowerbed = [1,0,0,0,1]
    # n = 1
    n = 2

    solution = Solution()
    placed = solution.canPlaceFlowers(flowerbed=flowerbed, n=n)
    print(f"The solution of this problem is : {placed}")