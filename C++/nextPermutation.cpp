/**
 * @File    : nextPermutation.cpp
 * @Brief   : 下一个排列
 * @Link    : https://leetcode-cn.com/problems/next-permutation/
 * @Author  : Wei Li
 * @Date    : 2021-08-27
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    void nextPermutation(std::vector<int> &nums)
    {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1])
        {
            --i;
        }
        if (i >= 0)
        {
            int j = nums.size() - 1;
            while (j >= 0 && nums[i] >= nums[j])
            {
                --j;
            }
            std::swap(nums[i], nums[j]);
        }
        std::reverse(nums.begin() + i + 1, nums.end());
    }
};

template <typename T>
void DisplayElement(const T &container)
{
    for (auto element : container)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

// -----------------------------
int main(int argc, char **argv)
{
    std::vector<int> nums{1, 1, 5};

    Solution solution;
    std::cout << "Processing before: " << std::endl;
    DisplayElement(nums);
    solution.nextPermutation(nums);
    std::cout << "Processing after: " << std::endl;
    DisplayElement(nums);

    return 0;
}
