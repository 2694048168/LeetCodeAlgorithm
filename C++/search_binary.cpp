/**
 * @file search_binary.cpp
 * @author Wei Li (weili_yzzcq@163.com)
 * @brief 二分法查找
 * @LeetCode Link https://leetcode.cn/problems/binary-search/
 * @version 0.1
 * @date 2022-09-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <vector>


class Solution 
{
public:
    int search(const std::vector<int>& nums, const int target) 
    {
        // 假设 nums 中的所有元素是不重复的, 而且是升序排列的
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int mid = (right - left) / 2 + left;
            int num = nums[mid];

            if (num == target)
            {
                return mid;
            }
            else if (num > target)
            {
                /* target at left, and binary-search */
                right = mid - 1;
            }
            else
            {
                /* target at right, and binary-search */
                left = mid + 1;
            }
        }

        return -1;
    }
};


// -------------------------------------
int main(int argc, char const *argv[])
{
    // const std::vector<int> nums {1, 3, 5, 6, 7, 9};
    // const int target = 3;

    // const std::vector<int> nums {-1,0,3,5,9,12};
    // const int target = 2;
    
    const std::vector<int> nums {-1,0,3,5,9,12};
    const int target = 9;

    Solution  solution;
    auto answer_index = solution.search(nums, target);
    std::cout << "The solution of this problem is " << answer_index << std::endl;

    return 0;
}
