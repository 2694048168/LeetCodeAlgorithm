/**
 * @File    : common_sort_algorithms.cpp
 * @Brief   : 常用的排序算法
 * @Author  : Wei Li
 * @Date    : 2021-07-09
*/

#include <iostream>
#include <vector>
#include <algorithm>


// 快速排序
// 左闭右闭的二分写法
void quick_sort(std::vector<int>& nums, int left, int right)
{
    if (left + 1 >= right)
    {
        return;
    }

    int first = left, last = right - 1, key = nums[first];
    while (first < last)
    {
        while (first < last && nums[last] >= key)
        {
            --last;
        }
        nums[first] =nums[last];

        while (first < last && nums[first] <= key)
        {
            ++first;
        }
        nums[last] = nums[first];
    }

    nums[first] = key;
    quick_sort(nums, left, first);
    quick_sort(nums, first + 1, right);
}


// 归并排序
void merge_sort(std::vector<int>& nums, int left, int right, std::vector<int>& temp)
{
    if (left + 1 >= right)
    {
        return;
    }

    // divide
    int m = left + (right - left) / 2;
    merge_sort(nums, left, m, temp);
    merge_sort(nums, m, right, temp);

    // conquer
    int p = left, q = m, i = left;
    while (p < m || q < right)
    {
        if (q >= right || (p < m && nums[p] <= nums[q]))
        {
            temp[i++] = nums[p++];
        }
        else
        {
            temp[i++] = nums[q++];
        }
    }

    for (i = 1; i < right; ++i)
    {
        nums[i] = temp[i];
    }
}


// 插入排序
void insertion_sort(std::vector<int>& nums, int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j > 0 && nums[j] < nums[j-1]; --j)
        {
            std::swap(nums[j], nums[j-1]);
        }
    }
}


// 冒泡排序
void bubble_sort(std::vector<int>& nums, int n)
{
    bool swapped;
    for (int i = 0; i < n; ++i)
    {
        swapped = false;
        for (int j = 1; j < n - i + 1; ++j)
        {
            if (nums[j] < nums[j-1])
            {
                std::swap(nums[j], nums[j-1]);
                swapped = true;
            }
        }
        if (!swapped)
        {
            break;
        }
    }
}


// 选择排序
void selection_sort(std::vector<int>& nums, int n)
{
    int mid = 0;
    for (int i = 0; i < n; ++i)
    {
        mid = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (nums[j] < nums[mid])
            {
                mid = j;
            }
        }
        std::swap(nums[mid], nums[i]);
    }
}

// test case 辅助函数
template <typename T>
void DisplayElement(const T& container)
{
    for (auto element = container.begin(); element != container.end(); ++element)
    {
        std::cout << *element << ' ';
    }
    // std::cout << std::endl << container.size() << std::endl;
    std::cout << std::endl;
}


// ------------------------------
int main(int argc, char** argv)
{
    // test case
    std::vector<int> nums = {1,3,5,7,2,6,4,8,9,2,8,7,6,0,3,5,9,4,1,0};
    std::vector<int> temp(nums.size());

    std::cout << "----------------Before Sorting----------------" << std::endl;
    DisplayElement(nums);

    std::cout << "----------------After Sorting----------------" << std::endl;

    std::cout << "C++ Sort Algorithms: " << std::endl;
    // C++ sort algorithms
    std::sort(nums.begin(), nums.end());
    DisplayElement(nums);

    // ----------------Before Sorting----------------
    // 1 3 5 7 2 6 4 8 9 2 8 7 6 0 3 5 9 4 1 0
    // ----------------After Sorting----------------
    // C++ Sort Algorithms:
    // 0 0 1 1 2 2 3 3 4 4 5 5 6 6 7 7 8 8 9 9 

    std::cout << "Quick Sort Algorithms: " << std::endl;
    quick_sort(nums, 0, nums.size());
    DisplayElement(nums);

    // ----------------Before Sorting----------------
    // 1 3 5 7 2 6 4 8 9 2 8 7 6 0 3 5 9 4 1 0
    // ----------------After Sorting----------------
    // Quick Sort Algorithms:
    // 0 0 1 1 2 2 3 3 4 4 5 5 6 6 7 7 8 8 9 9

    std::cout << "Merge Sort Algorithms: " << std::endl;
    merge_sort(nums, 0, nums.size(), temp);
    DisplayElement(nums);

    // ----------------Before Sorting----------------
    // 1 3 5 7 2 6 4 8 9 2 8 7 6 0 3 5 9 4 1 0
    // ----------------After Sorting----------------
    // Merge Sort Algorithms:
    // 1 0 0 0 1 1 1 1 2 2 3 3 4 5 6 7 7 8 9 9

    std::cout << "Insertion Sort Algorithms: " << std::endl;
    insertion_sort(nums, nums.size());
    DisplayElement(nums);

    // ----------------Before Sorting----------------
    // 1 3 5 7 2 6 4 8 9 2 8 7 6 0 3 5 9 4 1 0
    // ----------------After Sorting----------------
    // Insertion Sort Algorithms:
    // 1 3 5 7 2 6 4 8 9 2 8 7 6 0 3 5 9 4 1 0

    std::cout << "Bubble Sort Algorithms: " << std::endl;
    bubble_sort(nums, nums.size());
    DisplayElement(nums);

    // ----------------Before Sorting----------------
    // 1 3 5 7 2 6 4 8 9 2 8 7 6 0 3 5 9 4 1 0
    // ----------------After Sorting----------------
    // Bubble Sort Algorithms:
    // 0 0 1 1 2 2 3 3 4 4 5 5 6 6 7 7 8 8 9 9

    std::cout << "Selection Sort Algorithms: " << std::endl;
    selection_sort(nums, nums.size());
    DisplayElement(nums);

    // ----------------Before Sorting----------------
    // 1 3 5 7 2 6 4 8 9 2 8 7 6 0 3 5 9 4 1 0 
    // ----------------After Sorting----------------
    // Selection Sort Algorithms:
    // 0 0 1 1 2 2 3 3 4 4 5 5 6 6 7 7 8 8 9 9
    
    return 0;
}
