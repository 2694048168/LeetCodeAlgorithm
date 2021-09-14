/**
 * @File    : exchange.cpp
 * @Brief   : 调整数组顺序使奇数位于偶数前面
 * @Link    : https://leetcode-cn.com/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof/ 
 * @Author  : Wei Li
 * @Date    : 2021-09-14
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    std::vector<int> exchange(std::vector<int> &nums)
    {
        int i = 0, j = nums.size() - 1;
        while (i < j)
        {
            while (i < j && (nums[i] & 1) == 1)
                ++i;
            while (i < j && (nums[j] & 1) == 0)
                --j;
            std::swap(nums[i], nums[j]);
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

// ---------------------------------
int main(int argc, char **argv)
{
    std::vector<int> nums{1, 2, 3, 4};

    Solution solution;
    auto exchange_even_odd = solution.exchange(nums);
    std::cout << "The solution of this problem is " << std::endl;
    DisplayElement(exchange_even_odd);

    return 0;
}
