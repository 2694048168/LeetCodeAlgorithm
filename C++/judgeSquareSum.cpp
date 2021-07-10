/**
 * @File    : judgeSquareSum.cpp
 * @Brief   : 平方数之和
 * @Link    : https://leetcode-cn.com/problems/sum-of-square-numbers/
 * @Author  : Wei Li
 * @Date    : 2021-07-07
*/

#include <iostream>
#include <cmath>
#include <memory>

class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        long left = 0;
        long right = std::sqrt(c);
        while (left <= right)
        {
            long sum = left * left + right * right;
            if (sum == c)
            {
                return true;
            }
            else if (sum > c)
            {
                right--;
            }
            else
            {
                left++;
            }
        }
        return false;
    }
};


// -----------------------------
int main(int argc, char** argv)
{
    // int c = 5;
    // int c = 4;
    int c = 3;
    // int c = 2;
    // int c = 1;

    // auto solution = Solution();
    // Solution solution;
    auto solution = std::make_unique<Solution>();
    bool check = solution->judgeSquareSum(c);
    // bool check = solution.judgeSquareSum(c);
    std::cout << "The solution of this problem is : " << std::boolalpha << check << std::endl;
    
    return 0;
}
