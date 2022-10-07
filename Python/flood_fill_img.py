#!/usr/bin/env python3
# -*- coding: utf-8 -*-
'''
@File: flood_fill_img.py
@Funciton Description: 图像渲染
@Cite https://leetcode.cn/problems/flood-fill/
@Python Version: 3.10.4
@Platform: PyTorch 1.12.1+cu113
@Author: Wei Li
@Contact: weili_yzzcq@163.com
@Time: 2022/10/07 23:38:14
@Version: 0.1
@License: Apache License Version 2.0, January 2004
'''

import collections

# 详细解题思路查阅 C++ 版本实现 'flood_fill_img.cpp'
class Solution:
    def floodFill(self, image, sr, sc, color):
        currColor = image[sr][sc]
        if currColor == color:
            return image
        
        num_rows, num_cols = len(image), len(image[0])
        que = collections.deque([(sr, sc)])
        image[sr][sc] = color
        while que:
            x, y = que.popleft()
            # top-bottom-left-right
            for mx, my in [(x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1)]:
                if 0 <= mx < num_rows and 0 <= my < num_cols and image[mx][my] == currColor:
                    que.append((mx, my))
                    image[mx][my] = color
        
        return image


# --------------------------
if __name__ == "__main__":
    image = [[1,1,1],[1,1,0],[1,0,1]]
    sr = 1
    sc = 1
    newColor = 2

    # image = [[0,0,0],[0,0,0]]
    # sr = 0
    # sc = 0
    # newColor = 2

    print(image)
    solution = Solution()
    colored_img = solution.floodFill(image, sr, sc, newColor)
    print(colored_img)
