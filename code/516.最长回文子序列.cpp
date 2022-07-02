/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 */

// @lc code=start
class Solution
{
public:
    // int longestPalindromeSubseq(string s)
    // {
    //     int n = static_cast<int>(s.size());
    //     if (0 == n)
    //         return 0;

    //     int dp[n][n];
    //     memset(dp, 0, sizeof(dp));
    //     for (int i = 0; i < n; i++)
    //         dp[i][i] = 1; // 初始化状态

    //     for (int i = n - 1; i >= 0; i--)
    //     {
    //         for (int j = i + 1; j < n; j++)
    //         {
    //             if (s[i] == s[j])
    //                 dp[i][j] = 2 + dp[i + 1][j - 1];
    //             else
    //                 dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
    //         }
    //     }
    //     return dp[0][n - 1];
    // }

    int longestPalindromeSubseq(string s)
    {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for (int i = 0; i < s.size(); i++)
            dp[i][i] = 1;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < s.size(); j++)
            {
                if (s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        return dp[0][s.size() - 1];
    }
};
// @lc code=end
