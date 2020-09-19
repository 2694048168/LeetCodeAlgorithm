#
# LeetCodeLink ： https://leetcode-cn.com/problems/regular-expression-matching

# 10. 正则表达式匹配
# 给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
# '.' 匹配任意单个字符
# '*' 匹配零个或多个前面的那一个元素
# 所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。
#
# 说明:
# s 可能为空，且只包含从 a-z 的小写字母。
# p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。
#
# 示例 1:
# 输入:
# s = "aa"
# p = "a"
# 输出: false
# 解释: "a" 无法匹配 "aa" 整个字符串。
#
# 示例 2:
# 输入:
# s = "aa"
# p = "a*"
# 输出: true
# 解释: 因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
#

"""
# 动态规划的一般流程三步：暴力的递归解法 -> 带备忘录的递归解法 -> 迭代的动态规划解法
# 思考流程来说， 就分为步骤：找到状态和选择 -> 明确 dp 数组/函数的定义 -> 寻找状态之间的关系
# 
# 这就是思维模式的框架，按照以上的模式来解决问题，养成这种模式思维
"""

class Solution:
    """
    动态规划 = 状态转移方程 + 边界条件
    状态转移方程 = f[i][j] = 
    if(p[j] != '*') = f[i-1][j-1] matches; otherwise false;
    otherwise = f[i-1][j] or f[i][j-2] matches; otherwise f[i][j-2] 
    边界条件 = f[0][0] = true, 即就是空串可以匹配

    逐步匹配、 S.size = m、 P.size = n
    时间复杂度 T(n) = big O(mn)
    空间复杂度 S(n) = big O(mn)
    """

    def isMatch(self, s, p):
        m, n = len(s), len(p)

        def matches(i, j):
            if i == 0:
                return False
            if p[j - 1] == '.':
                return True
            return s[i - 1] == p[j - 1]

        # 状态转移方程
        f = [[False] * (n + 1) for _ in range(m + 1)]
        # 边界条件
        f[0][0] = True
        for i in range(m + 1):
            for j in range(1, n + 1):
                if p[j - 1] == '*':
                    f[i][j] |= f[i][j - 2]
                    if matches(i, j - 1):
                        f[i][j] |= f[i - 1][j]
                else:
                    if matches(i, j):
                        f[i][j] |= f[i - 1][j - 1]
        return f[m][n]


if __name__ == "__main__":
    # [test]
    s = "aa"
    p = "a"
    # p = "a."
    # p = "a*"
    solution = Solution()
    print(solution.isMatch(s, p))
