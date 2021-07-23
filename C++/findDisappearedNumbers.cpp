/**
 * @File    : findDisappearedNumbers.cpp
 * @Brief   : 找到所有数组中消失的数字  
 * @Link    : https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array/
 * @Author  : Wei Li
 * @Date    : 2021-07-23
*/

#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<int> findDisappearedNumbers(std::vector<int> &nums)
    {
        std::vector<int> ans;
        for (const int &num : nums)
        {
            int pos = abs(num) - 1;
            if (nums[pos] > 0)
            {
                nums[pos] = -nums[pos];
            }
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] > 0)
            {
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};

template <typename T>
void DisplayElement(const T& container)
{
    for (auto element : container)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

// --------------------------------
int main(int argc, char **argv)
{
    std::vector<int> nums{4, 3, 2, 7, 8, 2, 3, 1};

    Solution solution;
    auto disappeared_vec = solution.findDisappearedNumbers(nums);
    DisplayElement(disappeared_vec);

    return 0;
}
