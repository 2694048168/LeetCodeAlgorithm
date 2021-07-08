#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: search.py
@Function: 搜索旋转排序数组 II
@Link: https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii/
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-08
"""

"""
# 即使数组被旋转过，仍然可以利用这个数组的递增性，使用二分查找。
# 对于当前的中点，如果它指向的值小于等于右端，那么说明右区间是排好序的；反之，那么说明左区间是排好序的。
# 如果目标值位于排好序的区间内，可以对这个区间继续二分查找；反之，对于另一半区间继续二分查找。
# 注意，因为数组存在重复数字，如果中点和左端的数字相同，并不能确定是左区间全部相同，还是右区间完全相同。
# 在这种情况下，我们可以简单地将左端点右移一位，然后继续进行二分查找
"""
class Solution:
    def search(self, nums, target):
        # 二分查找，搜索左右边界
        start, end = 0, len(nums) - 1
        while start <= end:
            mid = (start + end) // 2
            if nums[mid] == target:
                return True
            
            if nums[start] == nums[end]:
                # 无法判断哪个区间是增序的
                start += 1
            elif nums[mid] <= nums[end]:
                # 右区间是增序的
                if (target > nums[mid] and target <= nums[end]):
                    start = mid + 1
                else:
                    end = mid - 1
            else:
                # 左区间是增序的
                if (target >= nums[start] and target < nums[mid]):
                    end = mid - 1
                else:
                    start = mid + 1

        return False


# -------------------------
if __name__ == "__main__":
    # nums = [2,5,6,0,0,1,2]
    # target = 0

    nums = [2,5,6,0,0,1,2]
    target = 3

    solution = Solution()
    check_target = solution.search(nums=nums, target=target)
    print(check_target)