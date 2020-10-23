#
# LeetCodeLink： https://leetcode-cn.com/problems/non-overlapping-intervals/
#
# 435. 无重叠区间
#

class Solution:
    """
    在选择要保留区间时，区间的结尾十分重要：
    选择的区间结尾越小，余留给其它区间的空间就越大，就越能保留更多的区间。
    因此，采取的贪心策略，优先保留结尾小且不相交的区间。

    具体实现方法为，先把区间按照结尾的大小进行增序排序，每次选择结尾最小且和前一个选择的区间不重叠的区间。
    这里使用Lambda，结合 sort() 函数进行自定义排序。
    """
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        if intervals:
            intervals.sort(key = lambda x:[x[0]])
            res = 0
            pre = 0
            for i in range(1, len(intervals)):
                if intervals[pre][1] > intervals[i][0]:
                    res += 1
                    if intervals[pre][1] > intervals[i][1]:
                        pre = i # 丢弃旧的前置位
                else:
                    pre = i # 直接更新前置位
            return res
        else:
            return 0

        


if __name__ == "__main__":
    pass
