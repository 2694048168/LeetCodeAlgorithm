/**
 * @File    : numWays.cpp
 * @Brief   : 青蛙跳台阶问题
 * @Link    : https://leetcode-cn.com/problems/qing-wa-tiao-tai-jie-wen-ti-lcof/
 * @Author  : Wei Li
 * @Date    : 2021-09-10
*/

#include <iostream>

class Solution
{
public:
    int numWays(int n)
    {
        long A[2][2] = {1, 1, 0, 0}; //原矩阵
        long B[2][2] = {0, 1, 1, 1}; //工具矩阵
        long C[2][2] = {1, 0, 0, 1}; //单位矩阵
        while (n)
        { //快速幂
            if (n & 1)
                muti(C, B);
            n >>= 1;
            muti(B, B);
        }
        muti(A, C);
        return A[0][0] % M;
    }
    const int M = 1e9 + 7;
    void muti(long (*A)[2], long (*B)[2])
    {
        long C[2][2] = {0, 0, 0, 0};
        for (int i = 0; i < 2; ++i) //矩阵乘法，warshall算法
            for (int j = 0; j < 2; ++j)
                for (int k = 0; k < 2; ++k)
                    C[i][j] += (A[i][k] * B[k][j]) % M;
        for (int i = 0; i < 2; ++i) //A *= B
            for (int j = 0; j < 2; ++j)
                A[i][j] = C[i][j];
    }
};

// ------------------------------
int main(int argc, char **argv)
{
    int n = 7;
    
    Solution solution;
    auto num_ways = solution.numWays(n);
    std::cout << "The solution of this problem is " << num_ways << std::endl;

    return 0;
}
