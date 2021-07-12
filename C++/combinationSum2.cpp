/**
 * @File    : combinationSum2.cpp
 * @Brief   : 给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 * @Link    : https://leetcode-cn.com/problems/combination-sum-ii/
 * @Author  : Wei Li
 * @Date    : 2021-07-12
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
private:
    std::vector<std::pair<int, int>> freq;
    std::vector<std::vector<int>> ans;
    std::vector<int> sequence;

public:
    void dfs(int pos, int rest)
    {
        if (rest == 0)
        {
            ans.push_back(sequence);
            return;
        }
        if (pos == freq.size() || rest < freq[pos].first)
        {
            return;
        }

        dfs(pos + 1, rest);

        int most = std::min(rest / freq[pos].first, freq[pos].second);
        for (int i = 1; i <= most; ++i)
        {
            sequence.push_back(freq[pos].first);
            dfs(pos + 1, rest - i * freq[pos].first);
        }
        for (int i = 1; i <= most; ++i)
        {
            sequence.pop_back();
        }
    }

    std::vector<std::vector<int>> combinationSum2(std::vector<int> &candidates, int target)
    {
        std::sort(candidates.begin(), candidates.end());
        for (int num : candidates)
        {
            if (freq.empty() || num != freq.back().first)
            {
                freq.emplace_back(num, 1);
            }
            else
            {
                ++freq.back().second;
            }
        }
        dfs(0, target);
        return ans;
    }
};


template <typename T>
void DisplayElement(const T &container)
{
    for (auto element = container.begin(); element != container.end(); ++element)
    {
        for (auto value = element->begin(); value != element->end(); ++value)
        {
            std::cout << *value << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}


// -------------------------------
int main(int argc, char **argv)
{
    std::vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;

    Solution solution;
    auto vec_combine = solution.combinationSum2(candidates, target);
    DisplayElement(vec_combine);

    return 0;
}
