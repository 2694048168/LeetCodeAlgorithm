/**
 * @File    : running_sum.cpp
 * @Brief   : 一维数组的动态和
 * @Link    : https://leetcode.cn/problems/running-sum-of-1d-array/
 * @Author  : Wei Li (weili_yzzcq@163.com)
 * @Date    : 2022-09-23
*/

#include <iostream>
#include <vector>


class Solution
{
public:
    std::vector<int> runningSum(std::vector<int>& nums) 
    {
        for (int idx = 0; idx < nums.size(); ++idx)
        {
            if (idx == 0)
            {
                continue;
            }
            nums[idx] += nums[idx - 1];
        }

        return nums;
    }
};

class Solution2 
{
public:
    std::vector<int> runningSum(std::vector<int>& nums) 
    {
        for (int idx = 1; idx < nums.size(); ++idx)
        {
            nums[idx] += nums[idx - 1];
        }

        return nums;
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
    std::vector<int> nums = {1, 2, 3, 4};
    DisplayElement(nums);

    Solution solution;
    auto running_sum = solution.runningSum(nums);
    std::cout << "The solution of this problem is " << std::endl;
    DisplayElement(nums);

    return 0;
}
