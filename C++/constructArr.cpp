/**
 * @File    : constructArr.cpp
 * @Brief   : 构建乘积数组
 * @Link    : https://leetcode-cn.com/problems/gou-jian-cheng-ji-shu-zu-lcof/
 * @Author  : Wei Li
 * @Date    : 2021-09-24
*/

#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<int> constructArr(std::vector<int> &a)
    {
        int n = a.size();
        // 返回结果的计算
        std::vector<int> b(n, 1);
        // 从上到下，左下角的遍历
        for (int i = 1; i < n; ++i)
        {
            b[i] *= b[i - 1] * a[i - 1];
        }

        int accu = 1; // 累计乘积的结果，用于和b[i] 来计算
        // 从下到上，左上角的遍历
        for (int i = n - 2; i >= 0; --i)
        {
            accu *= a[i + 1];
            b[i] *= accu;
        }

        return b;
    }
};

template <typename T>
void DisplayElement(const T &container)
{
    for (auto element : container)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

// ------------------------------
int main(int argc, char **argv)
{
    std::vector<int> nums{1, 2, 3, 4, 5};

    Solution solution;
    auto construct_array = solution.constructArr(nums);
    std::cout << "The solution of this problem is :" << std::endl;
    DisplayElement(construct_array);

    return 0;
}
