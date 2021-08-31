/**
 * @File    : generate.cpp
 * @Brief   : 杨辉三角
 * @Link    : https://leetcode-cn.com/problems/pascals-triangle/
 * @Author  : Wei Li
 * @Date    : 2021-08-31
*/

#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<std::vector<int>> generate(int numRows)
    {
        std::vector<std::vector<int>> ret(numRows);
        for (int i = 0; i < numRows; ++i)
        {
            ret[i].resize(i + 1);
            ret[i][0] = ret[i][i] = 1;
            for (int j = 1; j < i; ++j)
            {
                ret[i][j] = ret[i - 1][j] + ret[i - 1][j - 1];
            }
        }
        return ret;
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
    int numRows = 5;

    Solution solution;
    auto generate_ranger = solution.generate(numRows);
    std::cout << "The solution of this problem is :" << std::endl;
    DisplayElement(generate_ranger);

    return 0;
}
