/**
 * LeetCodeLink: https://leetcode-cn.com/problems/assign-cookies/
 * 
 * 455. 分发饼干
 * 
 */

class Solution:
    """solution 贪心算法或贪心思想采用贪心的策略

    至于具体实现，因为需要获得大小关系，一个便捷的方法就是把孩子和饼干分别排序。
    这样就可以从饥饿度最小的孩子和大小最小的饼干出发，计算有多少个对子可以满足条件。
    """
    def findContentChildren(self, children: List[int], cookies: List[int]) -> int:
        # children.sort()
        # cookies.sort()
        children = sorted(children, reverse=False)
        cookies = sorted(cookies,reverse=False)

        child: int = 0
        cookie: int = 0
        while (child != len(children) and cookie != len(cookies)):
            # 满足条件的情况
            if children[child] <= cookies[cookie]:
                child += 1
            
            cookie += 1
        
        return child
};