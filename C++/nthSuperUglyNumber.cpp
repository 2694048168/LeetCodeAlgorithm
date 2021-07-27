/**
 * @File    : nthSuperUglyNumber.cpp
 * @Brief   : 超级丑数
 * @Link    : https://leetcode-cn.com/problems/super-ugly-number/
 * @Author  : Wei Li
 * @Date    : 2021-07-27
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

class Solution
{
public:
    int nthSuperUglyNumber(int n, std::vector<int> &primes)
    {
        int *nums = new int[n];
        std::memset(nums, 0, sizeof(int) * n);
        nums[0] = 1;

        int np = primes.size();
        // primes的对应nums的序号
        int *p = new int[np];
        std::memset(p, 0, sizeof(int) * np);

        // 从1~n-1开始遍历
        for (int i = 1; i < n; ++i)
        {
            // 或许所有质数结果里最小的数作为下一个数字
            int currMin = INT_MAX;
            for (int j = 0; j < np; ++j)
            {
                currMin = std::min(currMin, nums[p[j]] * primes[j]);
            }

            nums[i] = currMin;

            // 判断是否和自己结果相等，是则序号+1
            for (int j = 0; j < np; ++j)
            {
                if (currMin == nums[p[j]] * primes[j])
                {
                    ++p[j];
                }
            }
        }

        return nums[n - 1];
    }
};

// ------------------------------
int main(int argc, char **argv)
{
    int n = 12;
    std::vector<int> primes{2, 7, 13, 19};

    Solution solution;
    auto super_ugly_number = solution.nthSuperUglyNumber(n, primes);
    std::cout << "The solution of this problem is " << super_ugly_number << std::endl;

    return 0;
}
