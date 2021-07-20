/**
 * @File    : majorityElement.cpp
 * @Brief   : 多数元素
 * @Link    : https://leetcode-cn.com/problems/majority-element/
 * @Author  : Wei Li
 * @Date    : 2021-07-20
*/

#include <iostream>
#include <vector>

class Solution
{
public:
    int majorityElement(std::vector<int> &nums)
    {
        int candidate = -1;
        int count = 0;
        for (int num : nums)
        {
            if (num == candidate)
                ++count;
            else if (--count < 0)
            {
                candidate = num;
                count = 1;
            }
        }
        return candidate;
    }
};

// --------------------------------
int main(int argc, char **argv)
{
    // std::vector<int> nums{3, 2, 3};
    std::vector<int> nums{2, 2, 1, 1, 1, 2, 2};

    Solution solution;
    auto majority_element = solution.majorityElement(nums);
    std::cout << "The solution of this problem is that " << majority_element << std::endl;

    return 0;
}
