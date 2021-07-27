/**
 * @File    : containsDuplicate.cpp
 * @Brief   : 存在重复元素  
 * @Link    : https://leetcode-cn.com/problems/contains-duplicate/
 * @Author  : Wei Li
 * @Date    : 2021-07-27
*/

#include <iostream>
#include <unordered_set>
#include <vector>

class Solution
{
public:
    bool containsDuplicate(std::vector<int> &nums)
    {
        std::unordered_set<int> s;
        for (int x : nums)
        {
            if (s.find(x) != s.end())
            {
                return true;
            }
            s.insert(x);
        }
        return false;
    }
};

// ---------------------------
int main(int argc, char **argv)
{
    // std::vector<int> nums{1, 2, 3, 4};
    std::vector<int> nums{1, 1, 1, 3, 3, 4, 3, 2, 4, 2, 1, 2, 3, 4};

    Solution solution;
    bool check_duplicate = solution.containsDuplicate(nums);
    std::cout << "The solution of this problem is " << std::boolalpha << check_duplicate << std::endl;

    return 0;
}
