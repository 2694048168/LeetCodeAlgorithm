/**
 * @File    : removeDuplicates.cpp
 * @Brief   : 删除有序数组中的重复项
 * @Link    : https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/
 * @Author  : Wei Li
 * @Date    : 2021-08-04
*/

#include <iostream>
#include <vector>

class Solution
{
public:
    int removeDuplicates(std::vector<int> &nums)
    {
        size_t size_array = nums.size();
        if (!size_array)
        {
            return 0;
        }

        // 双指针策略
        size_t fast = 1, slow = 1;
        while (fast < size_array)
        {
            if (nums[fast] != nums[fast - 1])
            {
                nums[slow] = nums[fast];
                ++slow;
            }
            ++fast;
        }

        return slow;
    }
};

// ------------------------------
int main(int argc, char **argv)
{
    // std::vector<int> nums{1, 1, 2};
    std::vector<int> nums{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    Solution solution;
    size_t num_duplicates = solution.removeDuplicates(nums);
    std::cout << "The size of original array: " << nums.size() << std::endl;
    std::cout << "The size of remove duplicates array: " << num_duplicates << std::endl;

    return 0;
}
