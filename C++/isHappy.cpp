/**
 * @File    : isHappy.cpp
 * @Brief   : 快乐数
 * @Link    : https://leetcode-cn.com/problems/happy-number/
 * @Author  : Wei Li
 * @Date    : 2021-07-20
*/

#include <iostream>

// 快慢指针
class Solution
{
public:
    int bitSquareSum(int n)
    {
        int sum = 0;
        while (n > 0)
        {
            int bit = n % 10;
            sum += bit * bit;
            n = n / 10;
        }
        return sum;
    }

    bool isHappy(int n)
    {
        int slow = n, fast = n;
        do
        {
            slow = bitSquareSum(slow);
            fast = bitSquareSum(fast);
            fast = bitSquareSum(fast);
        } while (slow != fast);

        return slow == 1;
    }
};

// -------------------------------
int main(int argc, char **argv)
{
    // int number = 19;
    int number = 2;

    Solution solution;
    bool check_happy = solution.isHappy(number);
    std::cout << "The solution of this problem is " << std::boolalpha << check_happy << std::endl;

    return 0;
}
