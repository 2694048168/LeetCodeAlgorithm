/**
 * @File    : pickIndex.cpp
 * @Brief   : 按权重随机选择
 * @Link    : https://leetcode-cn.com/problems/random-pick-with-weight/
 * @Author  : Wei Li
 * @Date    : 2021-07-19
*/

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <memory>

// 前缀和与二分搜索
class Solution
{
public:
    Solution(std::vector<int> weights) : sums(std::move(weights))
    {
        std::partial_sum(sums.begin(), sums.end(), sums.begin());
    }
    int pickIndex()
    {
        int pos = (rand() % sums.back()) + 1;
        return std::lower_bound(sums.begin(), sums.end(), pos) - sums.begin();
    }

private:
    std::vector<int> sums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
int main(int argc, char **argv)
{
    std::vector<int> weights{1, 3};

    auto solution = std::make_unique<Solution>(weights);
    auto param_1 = solution->pickIndex();

    std::cout << "The solution of this problem is " << param_1 << std::endl;

    return 0;
}
