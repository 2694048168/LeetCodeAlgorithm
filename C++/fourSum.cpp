/**
 * @File    : fourSum.cpp
 * @Brief   : 四数之和
 * @Link    : https://leetcode-cn.com/problems/4sum/
 * @Author  : Wei Li
 * @Date    : 2021-08-27
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    std::vector<std::vector<int>> fourSum(std::vector<int> &nums, int target)
    {
        std::vector<std::vector<int>> ans;
        int n = nums.size();
        std::sort(nums.begin(), nums.end());
        int num1, num2, num3, num4;
        for (num1 = 0; num1 < n - 3; num1++)
        {
            if (num1 > 0 && nums[num1] == nums[num1 - 1])
                continue;
            if ((long long)nums[num1] + nums[num1 + 1] + nums[num1 + 2] + nums[num1 + 3] > target)
                break;
            if ((long long)nums[num1] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target)
                continue;
            for (num2 = num1 + 1; num2 < n - 2; num2++)
            {
                if (num2 > num1 + 1 && nums[num2] == nums[num2 - 1])
                    continue;
                if ((long long)nums[num1] + nums[num2] + nums[num2 + 1] + nums[num2 + 2] > target)
                    break;
                if ((long long)nums[num1] + nums[num2] + nums[n - 2] + nums[n - 1] < target)
                    continue;
                num3 = num2 + 1;
                num4 = n - 1;
                while (num3 < num4)
                {
                    long long sum = nums[num1] + nums[num2] + nums[num3] + nums[num4];
                    if (sum == target)
                    { //找到一组满足条件的数组，则左右都要移动
                        ans.push_back({nums[num1], nums[num2], nums[num3], nums[num4]});
                        while (num3 < num4 && nums[num3] == nums[num3 + 1])
                        { //判断下一个数跟当前数是否一样，若不同则结束
                            num3++;
                        }
                        num3++;
                        while (num3 < num4 && nums[num4] == nums[num4 - 1])
                        {
                            num4--;
                        }
                        num4--;
                    }
                    else if (sum > target)
                    {
                        num4--;
                    }
                    else
                    {
                        num3++;
                    }
                }
            }
        }
        return ans;
    }
};

template <typename T>
void DisplayElement(const T &container)
{
    for (auto element : container)
    {
        for (auto value : element)
        {
            std::cout << value << " ";
        }
        std::cout << "; ";
    }
    std::cout << std::endl;
}

// -------------------------------
int main(int argc, char **argv)
{
    std::vector<int> nums{1, 0, -1, 0, -2, 2};
    int target = 0;
    // std::vector<int> nums{2, 2, 2, 2, 2};
    // int target = 8;

    Solution solution;
    auto four_sum = solution.fourSum(nums, target);
    DisplayElement(four_sum);

    return 0;
}
