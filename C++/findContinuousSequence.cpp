/**
 * @File    : findContinuousSequence.cpp
 * @Brief   : 和为s的连续正数序列   
 * @Link    : https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/
 * @Author  : Wei Li
 * @Date    : 2021-09-25
*/

#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<std::vector<int>> findContinuousSequence(int target)
    {
        std::vector<std::vector<int>> vec;
        std::vector<int> res;
        for (int l = 1, r = 2; l < r;)
        {
            int sum = (l + r) * (r - l + 1) / 2;
            if (sum == target)
            {
                res.clear();
                for (int i = l; i <= r; ++i)
                {
                    res.emplace_back(i);
                }
                vec.emplace_back(res);
                l++;
            }
            else if (sum < target)
            {
                r++;
            }
            else
            {
                l++;
            }
        }
        return vec;
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
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// -----------------------------
int main(int argc, char **argv)
{
    int target = 9;

    Solution solution;
    auto find_continuous_sequence = solution.findContinuousSequence(target);
    std::cout << "The solution of this problem is " << std::endl;
    DisplayElement(find_continuous_sequence);

    return 0;
}
