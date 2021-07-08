/**
 * @File    : mySqrt.cpp
 * @Brief   : 非负整数 x 的平方根 二分查找算法
 * @Link    : https://leetcode-cn.com/problems/sqrtx/
 * @Author  : Wei Li
 * @Date    : 2021-07-08
*/

#include <iostream>

class Solution
{
public:
    int mySqrt(int x)
    /**
     * 注意，在以下的代码里，为了防止除以 0，把 x = 0 的情况单独考虑，
     * 然后对区间 [1; a]进行二分查找。使用了左闭右闭的写法
     */
    {
        if (x == 0)
        {
            return x;
        }

        int left = 1, right = x, mid, sqrt;
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            sqrt = x / mid;
            if (sqrt == mid)
            {
                return mid;
            }
            else if (mid > sqrt)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return right;
    }
};

class Solution
{
public:
    int mySqrt(int a)
    /**
     * 更快的算法 — 牛顿迭代法
     * 为了防止 int 超上界，使用 long 来存储乘法结果。
     */
    {
        long x = a;
        while (x * x > a)
        {
            x = (x + a / x) / 2;
        }
        return x;
    }
};


// --------------------------------
int main(int argc, char **argv)
{
    // int x = 5;
    // int x = 4;
    int x = 8;

    auto solution = Solution();
    auto num_sqrt = solution.mySqrt(x);
    std::cout << "The solution of this problem is : " << num_sqrt << std::endl;

    return 0;
}
