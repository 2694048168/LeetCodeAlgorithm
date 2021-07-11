#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: exist.py
@Function: 单词搜索 回溯算法
@Link: https://leetcode-cn.com/problems/word-search/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-11
"""


class Solution:
    def exist(self, board, word):
        directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]

        def check(i: int, j: int, k: int) -> bool:
            if board[i][j] != word[k]:
                return False
            if k == len(word) - 1:
                return True

            visited.add((i, j))
            result = False
            for di, dj in directions:
                newi, newj = i + di, j + dj
                if 0 <= newi < len(board) and 0 <= newj < len(board[0]):
                    if (newi, newj) not in visited:
                        if check(newi, newj, k + 1):
                            result = True
                            break

            visited.remove((i, j))
            return result

        h, w = len(board), len(board[0])
        visited = set()
        for i in range(h):
            for j in range(w):
                if check(i, j, 0):
                    return True

        return False


# -------------------------
if __name__ == "__main__":
    board = [["A", "B", "C", "E"], ["S", "F", "C", "S"], ["A", "D", "E", "E"]]
    # word = "ABCCED"
    word = "ABCB"

    solution = Solution()
    check = solution.exist(board=board, word=word)
    print(f"The solution of this problem is : {check}")
