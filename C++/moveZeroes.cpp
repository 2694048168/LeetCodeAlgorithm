/**
 * @File    : moveZeroes.cpp
 * @Brief   : 移动零
 * @Link    : https://leetcode-cn.com/problems/move-zeroes/
 * @Author  : Wei Li
 * @Date    : 2021-08-26
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    void moveZeroes(std::vector<int> &nums)
    {
        int n = nums.size(), left = 0, right = 0;
        while (right < n)
        {
            if (nums[right])
            {
                std::swap(nums[left], nums[right]);
                ++left;
            }
            ++right;
        }
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

// ------------------------------
int main(int argc, char **argv)
{
    std::vector<int> nums{0, 1, 0, 3, 12};

    Solution solution;
    std::cout << "----Processing before: " << std::endl;
    DisplayElement(nums);
    std::cout << "----Processing after: " << std::endl;
    solution.moveZeroes(nums);
    DisplayElement(nums);

    return 0;
}
