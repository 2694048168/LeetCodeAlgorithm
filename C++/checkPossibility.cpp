/**
 * @File    : checkPossibility.cpp
 * @Brief   : 非递减数列 贪心策略各种情况下是否依然是最优解
 * @Link    : https://leetcode-cn.com/problems/non-decreasing-array/
 * @Author  : Wei Li
 * @Date    : 2021-07-06
*/

#include <iostream>
#include <vector>


class Solution
{
public:
    bool checkPossibility(std::vector<int>& nums)
    {
        int cnt = 0;
        for (size_t i = 0; i < nums.size() - 1; ++i)
        {
            int x = nums[i], y = nums[i+1];
            if (x > y)
            {
                cnt++;
                if (cnt > 1)
                {
                    return false;
                }
                if (i > 0 && y < nums[i-1])
                {
                    nums[i + 1] = x;
                }
            }
        }
        return true;        
    }
};


// ------------------------------
int main(int argc, char** argv)
{
    // std::vector<int> vec_nums = {4, 2, 3};
    std::vector<int> vec_nums = {4, 2, 1};

    auto solution = Solution();
    bool check_ok = solution.checkPossibility(vec_nums);
    std::cout << "The solution of this problem is : " << std::boolalpha << check_ok << std::endl;
    
    return 0;
}
