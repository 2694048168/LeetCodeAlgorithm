/**
 * @File    : minWindow.cpp
 * @Brief   : 最小覆盖子串 滑动窗口策略 & 双指针策略
 * @Link    : https://leetcode-cn.com/problems/minimum-window-substring/
 * @Author  : Wei Li
 * @Date    : 2021-07-07
*/

#include <iostream>
#include <string>
#include <vector>
#include <memory>

// 思路二：滑动窗口 + 字符数组
class Solution
{
public:
    std::string minWindow(std::string S, std::string T)
    {
        std::vector<int> chars(128, 0);
        std::vector<bool> flag(128, false);
        // 首先统计 T 中的字符情况
        for (size_t i = 0; i < T.size(); ++i)
        {
            flag[T[i]] = true;
            ++chars[T[i]];
        }
        // 移动滑动窗口，不断更改统计数据
        int cnt = 0, left = 0, min_left = 0, min_size = S.size() + 1;
        for (size_t right = 0; right < S.size(); ++right)
        {
            if (flag[S[right]])
            {
                if (--chars[S[right]] >= 0)
                {
                    ++cnt;
                }

                // 若目前滑动窗口已包含T中全部字符，
                // 则尝试将l右移， 在不影响结果的情况下获得最短子字符串
                while (cnt == T.size())
                {
                    if (right - left + 1 < min_size)
                    {
                        min_left = left;
                        min_size = right - left + 1;
                    }
                    if (flag[S[left]] && ++chars[S[left]] > 0)
                    {
                        --cnt;
                    }
                    ++left;
                }
            }
        }
        return min_size > S.size()? "": S.substr(min_left, min_size);
    }
};


template <typename T>
void DisplayElement(const T& container)
{
    for (auto element = container.begin(); element != container.end(); ++element)
    {
        std::cout << *element << " ";
    }
    std::cout << std::endl
              << container.size() << std::endl;
}


// --------------------------------
int main(int argc, char **argv)
{
    std::string s = "ADOBECODEBANC", t = "ABC";

    // auto solution = Solution();
    // Solution solution;
    auto solution = std::make_unique<Solution>();
    std::string min_str = solution->minWindow(s, t);
    // std::string min_str = solution.minWindow(s, t);
    DisplayElement(min_str);

    return 0;
}
