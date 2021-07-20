/**
 * @File    : minMoves2.cpp
 * @Brief   : 最少移动次数使数组元素相等 II
 * @Link    : https://leetcode-cn.com/problems/minimum-moves-to-equal-array-elements-ii/
 * @Author  : Wei Li
 * @Date    : 2021-07-20
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int minMoves2(std::vector<int> &nums)
    {
        int mid = static_cast<int>(nums.size()) / 2, ans = 0;
        std::nth_element(begin(nums), next(begin(nums), mid), end(nums));
        std::for_each(begin(nums), end(nums), [&](int num)
                 { ans += abs(num - nums[mid]); });

        return ans;
    }
};


template <typename T>
void DisplayElement(const T &container)
{
    std::cout << "[";
    for (auto element = container.begin(); element != container.end(); ++element)
    {
        std::cout << *element << ",";
    }
    std::cout << "]" << std::endl;
}

// -----------------------------
int main(int argc, char **argv)
{
    std::vector<int> nums{1, 2, 3};

    Solution solution;
    auto min_move_steps = solution.minMoves2(nums);
    DisplayElement(nums);
    std::cout << "The solution of this problem is " << min_move_steps << std::endl;

    return 0;
}
