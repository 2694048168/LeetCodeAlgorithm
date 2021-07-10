/**
 * @File    : sortColors.cpp
 * @Brief   : 颜色分类
 * @Link    : https://leetcode-cn.com/problems/sort-colors/
 * @Author  : Wei Li
 * @Date    : 2021-07-10
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    void sortColors(std::vector<int> &nums)
    {
        int n = nums.size();
        int p0 = 0, p2 = n - 1;
        for (int i = 0; i <= p2; ++i)
        {
            while (i <= p2 && nums[i] == 2)
            {
                std::swap(nums[i], nums[p2]);
                --p2;
            }
            if (nums[i] == 0)
            {
                std::swap(nums[i], nums[p0]);
                ++p0;
            }
        }
    }
};

template <typename T>
void DisplayElement(const T &container)
{
    for (auto element = container.begin(); element != container.end(); ++element)
    {
        std::cout << *element << " ";
    }
}

// ------------------------------
int main(int argc, char **argv)
{
    std::vector<int> nums = {2, 0, 2, 1, 1, 0};

    auto solution = Solution();
    solution.sortColors(nums);
    DisplayElement(nums);

    return 0;
}
