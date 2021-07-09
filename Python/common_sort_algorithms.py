#!/usr/bin/env python3
# encoding: utf-8

"""
@Filename: common_sort_algorithms.py
@Function: 常用的排序算法
@Python Version: 3.8
@Author: Wei Li
@Date：2021-07-09
"""

# 快速排序
# 左闭右闭的二分写法
def quick_sort(nums, left, right):
    if left + 1 >= right:
        return

    first, last = left, right - 1
    key = nums[first]
    while first < last:
        while first < last and nums[last] >= key:
            last -= 1
        nums[first] = nums[last]

        while first < last and nums[first] <= key:
            first += 1
        nums[last] = nums[first]

    nums[first] = key
    quick_sort(nums, left, first)
    quick_sort(nums, first + 1, right)


# 归并排序
def merge_sort(seq):
    """归并排序"""
    if len(seq) <= 1:
        return seq
    mid = len(seq) // 2  # 将列表分成更小的两个列表
    # 分别对左右两个列表进行处理，分别返回两个排序好的列表
    left = merge_sort(seq[:mid])
    right = merge_sort(seq[mid:])
    # 对排序好的两个列表合并，产生一个新的排序好的列表
    return merge(left, right)

def merge(left, right):
    """合并两个已排序好的列表，产生一个新的已排序好的列表"""
    result = []  # 新的已排序好的列表
    i = 0  # 下标
    j = 0
    # 对两个列表中的元素 两两对比。
    # 将最小的元素，放到result中，并对当前列表下标加1
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1
    result += left[i:]
    result += right[j:]

    return result


# 插入排序
def insertion_sort(nums):
    for i in range(1, len(nums)): 
        key = nums[i] 
  
        j = i - 1
        while j >= 0 and key < nums[j] : 
                nums[j+1] = nums[j] 
                j -= 1
        nums[j+1] = key 


# 冒泡排序
def bubble_sort(nums):
    n = len(nums)
 
    # 遍历所有数组元素
    for i in range(n):
        # Last i elements are already in place
        for j in range(0, n - i - 1):
            if nums[j] > nums[j+1]:
                # swap operator
                nums[j], nums[j+1] = nums[j+1], nums[j]


# 选择排序
def selection_sort(nums):
    for i in range(len(nums)):
        min_idx = i 
        for j in range(i+1, len(nums)): 
            if nums[min_idx] > nums[j]: 
                min_idx = j 
                
        nums[i], nums[min_idx] = nums[min_idx], nums[i] 


# ------------------------------
if __name__ == "__main__":
    #  test case
    nums = [1,3,5,7,2,6,4,8,9,2,8,7,6,0,3,5,9,4,1,0]
    # temp = [0]*len(nums)

    print("----------------Before Sorting----------------")
    print(nums)

    print("----------------After Sorting----------------")

    print("Python Sort Algorithm:")
    nums_sorted_python = sorted(nums)
    print(nums_sorted_python)

    # ----------------Before Sorting----------------
    # [1, 3, 5, 7, 2, 6, 4, 8, 9, 2, 8, 7, 6, 0, 3, 5, 9, 4, 1, 0]
    # ----------------After Sorting----------------
    # Python Sort Algorithm:
    # [0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9]


    print("Quick Sort Algorithm:")
    quick_sort(nums, 0, len(nums))
    print(nums)

    # ----------------Before Sorting----------------
    # [1, 3, 5, 7, 2, 6, 4, 8, 9, 2, 8, 7, 6, 0, 3, 5, 9, 4, 1, 0]
    # ----------------After Sorting----------------
    # Quick Sort Algorithm:
    # [0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9]


    print("Merge Sort Algorithm:")
    merge_sort_result = merge_sort(nums)
    print(merge_sort_result)

    # ----------------Before Sorting----------------
    # [1, 3, 5, 7, 2, 6, 4, 8, 9, 2, 8, 7, 6, 0, 3, 5, 9, 4, 1, 0]
    # ----------------After Sorting----------------
    # Merge Sort Algorithm:
    # [0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9]


    print("Insertion Sort Algorithm:")
    insertion_sort(nums)
    print(nums)

    # ----------------Before Sorting----------------
    # [1, 3, 5, 7, 2, 6, 4, 8, 9, 2, 8, 7, 6, 0, 3, 5, 9, 4, 1, 0]
    # ----------------After Sorting----------------
    # Insertion Sort Algorithm:
    # [0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9]


    print("Bubble Sort Algorithm:")
    bubble_sort(nums)
    print(nums)

    # ----------------Before Sorting----------------
    # [1, 3, 5, 7, 2, 6, 4, 8, 9, 2, 8, 7, 6, 0, 3, 5, 9, 4, 1, 0]
    # ----------------After Sorting----------------
    # Bubble Sort Algorithm:
    # [0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9]


    print("Selection Sort Algorithm:")
    selection_sort(nums)
    print(nums)

    # ----------------Before Sorting----------------
    # [1, 3, 5, 7, 2, 6, 4, 8, 9, 2, 8, 7, 6, 0, 3, 5, 9, 4, 1, 0]
    # ----------------After Sorting----------------
    # Selection Sort Algorithm:
    # [0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9]