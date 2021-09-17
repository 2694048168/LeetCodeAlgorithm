/**
 * @File    : minNumber.cpp
 * @Brief   : 把数组排成最小的数
 * @Link    : https://leetcode-cn.com/problems/ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof/
 * @Author  : Wei Li
 * @Date    : 2021-09-17
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Solution
{
public:
    std::string minNumber(std::vector<int> &nums)
    {
        std::vector<std::string> strs;
        for (int i = 0; i < nums.size(); i++)
            strs.push_back(std::to_string(nums[i]));
        quickSort(strs, 0, strs.size() - 1);
        std::string res;
        for (std::string s : strs)
            res.append(s);
        return res;
    }

private:
    void quickSort(std::vector<std::string> &strs, int l, int r)
    {
        if (l >= r)
            return;
        int i = l, j = r;
        while (i < j)
        {
            while (strs[j] + strs[l] >= strs[l] + strs[j] && i < j)
                j--;
            while (strs[i] + strs[l] <= strs[l] + strs[i] && i < j)
                i++;
            std::swap(strs[i], strs[j]);
        }
        std::swap(strs[i], strs[l]);
        quickSort(strs, l, i - 1);
        quickSort(strs, i + 1, r);
    }
};

// -----------------------------
int main(int argc, char **argv)
{
    // std::vector<int> nums{10, 2};
    std::vector<int> nums{3, 30, 34, 5, 9};

    Solution solution;
    auto min_number = solution.minNumber(nums);
    std::cout << "The solution of this problem is " << min_number << std::endl;

    return 0;
}
