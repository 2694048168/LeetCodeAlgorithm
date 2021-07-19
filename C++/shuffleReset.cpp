/**
 * @File    : shuffleReset.cpp
 * @Brief   : 打乱数组
 * @Link    : https://leetcode-cn.com/problems/shuffle-an-array/
 * @Author  : Wei Li
 * @Date    : 2021-07-19
*/

#include <iostream>
#include <vector>
#include <memory>

class Solution
{
    std::vector<int> origin;

public:
    Solution(std::vector<int> nums) : origin(std::move(nums))
    {
    }

    /** Resets the array to its original configuration and return it. */
    std::vector<int> reset()
    {
        return origin;
    }

    /** Returns a random shuffling of the array. */
    std::vector<int> shuffle()
    {
        if (origin.empty())
        {
            return {};
        }

        std::vector<int> shuffled(origin);
        int n = origin.size();
        // 可以使用反向或者正向洗牌， 效果相同。
        // 反向洗牌：
        for (int i = n - 1; i >= 0; --i)
        {
            std::swap(shuffled[i], shuffled[rand() % (i + 1)]);
        }
        // 正向洗牌：
        // for (int i = 0; i < n; ++i) {
        // int pos = rand() % (n - i);
        // swap(shuffled[i], shuffled[i+pos]);
        // }
        return shuffled;
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

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
int main(int argc, char **argv)
{
    std::vector<int> nums{1, 2, 3};

    // Solution *obj = new Solution(nums);
    // std::vector<int> param_1 = obj->reset();
    // std::vector<int> param_2 = obj->shuffle();

    auto solution = std::make_unique<Solution>(nums);
    auto param_1 = solution->reset();
    auto param_2 = solution->shuffle();

    std::cout << "The solution of this problem is " << std::endl;
    DisplayElement(nums);
    DisplayElement(param_1);
    DisplayElement(param_2);

    // delete obj;
    // obj = nullptr;

    return 0;
}
