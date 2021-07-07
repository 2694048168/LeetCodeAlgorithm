/**
 * @File    : merge.cpp
 * @Brief   : 合并两个有序数组 双指针策略
 * @Link    : https://leetcode-cn.com/problems/merge-sorted-array/
 * @Author  : Wei Li
 * @Date    : 2021-07-07
*/

#include <iostream>
#include <vector>


// --------------------------------------------------------------------------------------------
// 注意 这里使用了 ++ 和--的小技巧： a++ 和 ++a 都是将 a 加 1，但是 a++ 返回值为 a，
// 而 ++a 返回值为 a+1。如果只是希望增加 a 的值，而不需要返回值，则推荐使用 ++a，其运行速度会略快一些。
// --------------------------------------------------------------------------------------------
class Solution
{
public:
    void merge(std::vector<int>& num1, int m, std::vector<int>& num2, int n)
    {
        int pos = m-- + n-- - 1;
        while (m >= 0 && n >= 0)
        {
            num1[pos--] = num1[m] > num2[n] ? num1[m--]: num2[n--];
        }
        while (n >= 0)
        {
            num1[pos--] = num2[n--];
        }
    }
};


template <typename T>
void DisplayElement(const T& container)
{
    for (auto element = container.begin(); element != container.end(); ++element)
    {
        // std::cout << *element << std::endl;
        std::cout << *element << " ";
    }
    std::cout << std::endl
              << container.size() << std::endl;
}


// -------------------------------
int main(int argc, char** argv)
{
    std::vector<int> num1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    std::vector<int> num2 = {2, 5, 6};
    int n = 3;

    std::cout << "------------Before merging------------" << std::endl;
    DisplayElement(num1);
    auto solution = Solution();
    solution.merge(num1, m, num2, n);
    std::cout << "------------After merging------------" << std::endl;
    DisplayElement(num1);
    
    return 0;
}
