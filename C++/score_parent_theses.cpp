/**
 * @file score_parent_theses.cpp
 * @author Wei Li (weli_yzzcq@163.com)
 * @brief 括号的分数
 * @cite https://leetcode.cn/problems/score-of-parentheses/
 * @version 0.1
 * @date 2022-10-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <string>
#include <cmath>

/**
 * @brief 括号的分数, 给定一个平衡括号字符串 S，按下述规则计算该字符串的分数：
 * 1. () 得 1 分;
 * 2. AB 得 A + B 分，其中 A 和 B 是平衡括号字符串;
 * 3. (A) 得 2 * A 分，其中 A 是平衡括号字符串
 * 
 * Solution:
 * 1. '(' ---> 1 and ')' ---> -1;
 * 2. sum = 0, and then '()';
 * 3. depth += sum
 * 4. score = 2^(depth);
 * 
 * 时间复杂度: T(n) = big-O(n), n=str.length();
 * 空间复杂度: S(n) = big-O(1), int score_ans;
 * 
 */
class Solution
{
public:
    int scoreOfParentheses(const std::string &str)
    {
        // special case
        if (str.empty())
        {
            return 0;
        }

        int depth_recursive = 0;
        int score_ans = 0; /* score=2^{depth} */
        for (int i = 0; i < str.length(); ++i)
        {
            depth_recursive += (str[i] == '(' ? 1 : -1);

            if (str[i] == ')' && str[i-1] == '(')
            {
                // score_ans += 1 << depth_recursive;
                score_ans += std::pow(2, depth_recursive);
            }
        }

        return score_ans;
    }
};


// ------------------------------------
int main(int argc, char const *argv[])
{
    // const std::string parent_str {"()"}; /* score==1 */
    const std::string parent_str {"()()"}; /* score==2 */
    // const std::string parent_str {"(())"}; /* score==2 */
    // const std::string parent_str {"(()(()))"}; /* score==6 */

    Solution solution;
    int score = solution.scoreOfParentheses(parent_str);
    std::cout << "the score of parent string: " << score << std::endl;

    return 0;
}
