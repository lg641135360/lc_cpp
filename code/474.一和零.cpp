/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 */

// @lc code=start
class Solution
{
public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (string s : strs)
        {
            int oneNum = 0, zeroNum = 0;
            for (char c : s)
            {
                if (c == '0')
                    zeroNum++;
                else
                    oneNum++;
            }
            for (int i = m; i >= zeroNum; i--)
                for (int j = n; j >= oneNum; j--)
                    dp[i][j] = max(dp[i][j], dp[i - zeroNum][j - oneNum] + 1);
        }
        return dp[m][n];
    }
};
// @lc code=end
