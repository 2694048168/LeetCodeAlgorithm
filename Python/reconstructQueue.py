#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: reconstructQueue.py
@Function: 根据身高重建队列 贪心策略
@Link: https://leetcode-cn.com/problems/queue-reconstruction-by-height/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-06
"""


# ---------------------------
class Solution:
    def reconstructQueue(self, people):
        people.sort(key=lambda x: (x[0], -x[1]))
        n = len(people)
        ans = [[] for _ in range(n)]
        for person in people:
            spaces = person[1] + 1
            for i in range(n):
                if not ans[i]:
                    spaces -= 1
                    if spaces == 0:
                        ans[i] = person
                        break
        return ans



# -------------------------
if __name__ == "__main__":
    # people = [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
    people = [[6,0],[5,0],[4,0],[3,2],[2,2],[1,4]]

    solution = Solution()
    reconstruct_queue = solution.reconstructQueue(people)
    print(reconstruct_queue)