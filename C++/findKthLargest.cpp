/**
 * @File    : findKthLargest.cpp
 * @Brief   : 数组中的第K个最大元素  快速选择 + 堆排序
 * @Link    : https://leetcode-cn.com/problems/kth-largest-element-in-an-array/
 * @Author  : Wei Li
 * @Date    : 2021-07-10
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <memory>

// 方法一：基于快速排序的选择方法
class Solution
{
public:
    int quickSelect(std::vector<int> &a, int l, int r, int index)
    {
        int q = randomPartition(a, l, r);
        if (q == index)
        {
            return a[q];
        }
        else
        {
            return q < index ? quickSelect(a, q + 1, r, index) : quickSelect(a, l, q - 1, index);
        }
    }

    inline int randomPartition(std::vector<int> &a, int l, int r)
    {
        int i = rand() % (r - l + 1) + l;
        std::swap(a[i], a[r]);
        return partition(a, l, r);
    }

    inline int partition(std::vector<int> &a, int l, int r)
    {
        int x = a[r], i = l - 1;
        for (int j = l; j < r; ++j)
        {
            if (a[j] <= x)
            {
                std::swap(a[++i], a[j]);
            }
        }
        std::swap(a[i + 1], a[r]);
        return i + 1;
    }

    int findKthLargest(std::vector<int> &nums, int k)
    {
        srand(time(0));
        return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
    }
};

// 方法二：基于堆排序的选择方法
class Solution
{
public:
    void maxHeapify(std::vector<int> &a, int i, int heapSize)
    {
        int l = i * 2 + 1, r = i * 2 + 2, largest = i;
        if (l < heapSize && a[l] > a[largest])
        {
            largest = l;
        }
        if (r < heapSize && a[r] > a[largest])
        {
            largest = r;
        }
        if (largest != i)
        {
            std::swap(a[i], a[largest]);
            maxHeapify(a, largest, heapSize);
        }
    }

    void buildMaxHeap(std::vector<int> &a, int heapSize)
    {
        for (int i = heapSize / 2; i >= 0; --i)
        {
            maxHeapify(a, i, heapSize);
        }
    }

    int findKthLargest(std::vector<int> &nums, int k)
    {
        int heapSize = nums.size();
        buildMaxHeap(nums, heapSize);
        for (int i = nums.size() - 1; i >= nums.size() - k + 1; --i)
        {
            std::swap(nums[0], nums[i]);
            --heapSize;
            maxHeapify(nums, 0, heapSize);
        }
        return nums[0];
    }
};

// -----------------------------
int main(int argc, char **argv)
{
    // std::vector<int> nums = {3, 2, 1, 5, 6, 4};
    // int k = 2;

    std::vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k = 4;

    // auto solution = Solution();
    // Solution solution;
    auto solution = std::make_unique<Solution>();
    // auto kth_largest = solution.findKthLargest(nums, k);
    auto kth_largest = solution->findKthLargest(nums, k);
    std::cout << "The solution of this problem is : " << kth_largest << std::endl;

    return 0;
}
