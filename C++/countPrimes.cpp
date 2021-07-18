/**
 * @File    : countPrimes.cpp
 * @Brief   :  计数质数 数学问题
 * @Link    : https://leetcode-cn.com/problems/count-primes/
 * @Author  : Wei Li
 * @Date    : 2021-07-18
*/

/**数学问题
 * 1. 公倍数和公因数
 * 利用辗转相除法，求解两个数的最大公因数 greatest common divisor， gcd；
 * 将两个数相乘后再除以最大公因数即可得到最小公倍数 least common multiple, lcm；
 * 同时利用扩展欧几里得算法求解最大公因数的同时获取对应的系数；
 * 
 * 2. 质数(素数)
 * 针对大于 1 的自然数，除了 1 和本身之外不再有其他因数的自然数，素数；
 * 每一个数都可以分解为质数的乘积
 * 
 */

#include <iostream>
#include <vector>
#include <cmath>

class Solution
{
public:
    int countPrimes(int n)
    {
        std::vector<int> isPrime(n, 1);
        int ans = 0;
        for (int i = 2; i < n; ++i)
        {
            if (isPrime[i])
            {
                ans += 1;
                if ((long long)i * i < n)
                {
                    for (int j = i * i; j < n; j += i)
                    {
                        isPrime[j] = 0;
                    }
                }
            }
        }
        return ans;
    }
};

// 优化
class Solution
{
public:
    int countPrimes(int n)
    {
        std::vector<int> primes;
        std::vector<int> isPrime(n, 1);
        for (int i = 2; i < n; ++i)
        {
            if (isPrime[i])
            {
                primes.push_back(i);
            }
            for (int j = 0; j < primes.size() && i * primes[j] < n; ++j)
            {
                isPrime[i * primes[j]] = 0;
                if (i % primes[j] == 0)
                {
                    break;
                }
            }
        }
        return primes.size();
    }
};

// -------------------------------
int main(int argc, char **argv)
{
    int n = 10;
    // int n = 1;

    Solution solution;
    auto num_prime = solution.countPrimes(n);
    std::cout << "The solution of this problem is " << num_prime << std::endl;

    return 0;
}
