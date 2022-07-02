/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i * i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (j - i * i >= 0)
                    dp[j] = min(dp[j - i * i] + 1, dp[j]);
        return dp[n];
    }
};
// @lc code=end
