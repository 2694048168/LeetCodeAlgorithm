/**
 * @File    : getLeastNumbers.cpp
 * @Brief   : 最小的k个数
 * @Link    : https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/
 * @Author  : Wei Li
 * @Date    : 2021-09-18
*/

#include <iostream>
#include <vector>
#include <queue>

class Solution
{
public:
    std::vector<int> getLeastNumbers(std::vector<int> &arr, int k)
    {
        std::vector<int> vec(k, 0);
        if (k == 0)
        { // 排除 0 的情况
            return vec;
        }
        std::priority_queue<int> Q;
        for (int i = 0; i < k; ++i)
        {
            Q.push(arr[i]);
        }
        for (int i = k; i < (int)arr.size(); ++i)
        {
            if (Q.top() > arr[i])
            {
                Q.pop();
                Q.push(arr[i]);
            }
        }
        for (int i = 0; i < k; ++i)
        {
            vec[i] = Q.top();
            Q.pop();
        }
        return vec;
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
    // std::vector<int> arr{3, 2, 1};
    std::vector<int> arr{3, 2, 1, 7, 3, 9, 0};
    int k = 2;

    Solution solution;
    auto get_leaest_number = solution.getLeastNumbers(arr, k);
    std::cout << "The solution of this problem is " << std::endl;
    DisplayElement(get_leaest_number);

    return 0;
}
