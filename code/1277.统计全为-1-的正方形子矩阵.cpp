/*
 * @lc app=leetcode.cn id=1277 lang=cpp
 *
 * [1277] 统计全为 1 的正方形子矩阵
 */

// @lc code=start
class Solution
{
public:
    // int countSquares(vector<vector<int>> &mat)
    // {
    //     int m = mat.size();
    //     int n = mat[0].size();
    //     int len = min(m, n);
    //     vector<vector<vector<bool>>> dp(m, vector<vector<bool>>(n, vector<bool>(len, false)));
    //     int count = 0;
    //     for (int i = 0; i < m; i++)
    //     {
    //         for (int j = 0; j < n; j++)
    //         {
    //             dp[i][j][0] = (mat[i][j] == 1);
    //             count += dp[i][j][0] ? 1 : 0;
    //         }
    //     }
    //     for (int i = 1; i < m; i++)
    //     {
    //         for (int j = 1; j < n; j++)
    //         {
    //             for (int k = 1; k < len; k++)
    //             {
    //                 dp[i][j][k] = (mat[i][j] == 1 && dp[i - 1][j][k - 1] && dp[i][j - 1][k - 1] && dp[i - 1][j - 1][k - 1]);
    //                 if (dp[i][j][k])
    //                 {
    //                     count++;
    //                 }
    //             }
    //         }
    //     }
    //     return count;
    // }

    int countSquares(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int ans = 0;
        for (int i = 0; i < m; i++)
            ans += dp[i][0] = mat[i][0];
        for (int j = 0; j < n; j++)
            ans += dp[0][j] = mat[0][j];
        if (mat[0][0] == 1)
            ans--;
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (mat[i][j] == 1)
                {
                    dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                    ans += dp[i][j];
                }
            }
        }
        return ans;
    }
};
// @lc code=end
