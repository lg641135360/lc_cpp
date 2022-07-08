/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
class Solution
{
public:
    // int minimumTotal(vector<vector<int>> &triangle)
    // {
    //     // 保证有二维
    //     if (triangle.size() == 0)
    //         return 0;
    //     vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(), 0)); // 这里注意triangle的形状
    //     for (int i = 0; i < dp.size(); ++i)                                       // 最后一行赋值
    //         dp[dp.size() - 1][i] = triangle[dp.size() - 1][i];
    //     for (int i = dp.size() - 2; i >= 0; --i)
    //     {
    //         for (int j = 0; j < triangle[i].size(); ++j)
    //             dp[i][j] = min(dp[i + 1][j] + triangle[i][j], dp[i + 1][j + 1] + triangle[i][j]);
    //     }
    //     return dp[0][0];
    // }

    int minimumTotal(vector<vector<int>> &t)
    {
        // dp[i][j]：从底到i,j位置的最短路径和
        vector<vector<int>> dp(t.size(), vector<int>(t.size(), 0));
        // 初始化dp数组，最后一行的值都为其本身
        for (int i = 0; i < dp.size();i++)
            dp[dp.size() - 1][i] = t[dp.size() - 1][i];
        // 状态转移方程 dp[i][j] = min(dp[i+1][j],dp[i+1][j+1]) + t[i][j];
        // 遍历顺序：从下到上，从左到右（从状态转移方程可知
        for (int i = dp.size() - 2; i >= 0;--i)
            for (int j = 0; j < t[i].size();++j)
                dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + t[i][j];
        return dp[0][0];
    }
};
// @lc code=end
