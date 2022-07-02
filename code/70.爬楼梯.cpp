/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution
{
public:
    // 使用递归
    // int climbStairs(int n) {
    //     // 暴力递归，不行昂 超时了
    //     if(n==0|| n==1) return 1;

    //     return climbStairs(n-1) + climbStairs(n-2);

    // }

    // 斐波那契数列，动态规划1，使用数组
    // int climbStairs(int n) {
    //     vector<int> map(n+1);
    //     map[0] = 1;
    //     map[1] = 1;
    //     // map[2] = 2;
    //     for(int i =2;i<=n;i++)
    //         map[i] = map[i-1] + map[i-2];

    //     return map[n];
    // }

    // 动态规划 优化，最终结果只跟其前面两个有关系
    // int climbStairs(int n)
    // {
    //     vector<int> dp(n + 2, 0);
    //     dp[1] = 1;
    //     dp[2] = 2;
    //     for (int i = 3; i <= n; ++i)
    //         dp[i] = dp[i - 1] + dp[i - 2];
    //     return dp[n];
    // }

    // 完全背包
    int climbStairs(int n)
    {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= 2; j++)
                if (i - j >= 0)
                    dp[i] += dp[i - j];
        }
        return dp[n];
    }
};
// @lc code=end
