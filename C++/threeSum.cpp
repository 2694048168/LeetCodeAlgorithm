/**
 * @File    : threeSum.cpp
 * @Brief   : 三数之和
 * @Link    : https://leetcode-cn.com/problems/3sum/
 * @Author  : Wei Li
 * @Date    : 2021-08-10
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
    {
        size_t num_array = nums.size();
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> ans;

        // 枚举 第一个数字 a
        for (size_t first_number_idx = 0; first_number_idx < num_array; ++first_number_idx)
        {
            // 需要和上一次枚举的数字不相同(去重复)
            if (first_number_idx > 0 && nums[first_number_idx] == nums[first_number_idx - 1])
            {
                continue;
            }

            // 第三数字 c 对应的指针初始指向数组的最右端
            size_t third_number_idx = num_array - 1;
            // 利用双指针策略计算符合目标值的两个索引
            int target = -nums[first_number_idx];

            // 枚举 第二个数字 b
            for (size_t second_number_idx = first_number_idx + 1; second_number_idx < num_array; ++second_number_idx)
            {
                // 需要和上一次枚举的数字不相同(去重复)
                if (second_number_idx > first_number_idx + 1 && nums[second_number_idx] == nums[second_number_idx - 1])
                {
                    continue;
                }

                // 需要保证 b 的指针在 c 的指针的左侧 双指针策略
                while (second_number_idx < third_number_idx && nums[second_number_idx] + nums[third_number_idx] > target)
                {
                    --third_number_idx;
                }

                // 如果指针重合，随着 b 后续的增加
                // 就不会有满足 a+b+c=0 并且 b<c 的 c 了，可以退出循环
                if (second_number_idx == third_number_idx)
                {
                    break;
                }

                if (nums[second_number_idx] + nums[third_number_idx] == target)
                {
                    ans.push_back({nums[first_number_idx], nums[second_number_idx], nums[third_number_idx]});
                }
            }
        }
        return ans;
    }
};

template <typename T>
void DispalyElement(const T &container)
{
    for (auto element : container)
    {
        for (auto index : element)
        {
            std::cout << index << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// --------------------------------
int main(int argc, char **argv)
{
    std::vector<int> nums{-1, 0, 1, 2, -1, -4};

    Solution solution;
    auto three_sum_idx = solution.threeSum(nums);
    DispalyElement(three_sum_idx);

    return 0;
}
