/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution
{
public:
    // 只能买卖一次，滑动窗口，左边是最小，右边是最大
    int maxProfit(vector<int> &prices)
    {
        // 滑动窗口左边界 begin
        int begin = 0;
        int res = 0;

        for (int i = 1; i < prices.size();)
        {
            // 只有当begin位置大于当前位置，才能移动左边界begin
            // begin位置要存放当前最小值
            if (prices[begin] > prices[i])
            {
                begin = i;
                i++;
            }
            else
            {
                // 更新收益
                res = max((prices[i] - prices[begin]), res);
                i++;
            }
        }
        return res;
    }

    // dp`DP[i][j][k]`表示在第`i`天，是否持有（其中`j`为`0`表示未持有，`1`表示持有）
    // 以及卖出几次（`k`为`0`表示卖出`0`次，`1`表示卖出`1`次，`2`表示卖出两次）的情况下，最大利润
    // int maxProfit(vector<int> &prices)
    // {
    //     int m = prices.size();
    //     int dp[m][2][3];

    //     // 处理第一天
    //     // 第一天没有买入
    //     dp[0][0][0] = 0;
    //     dp[0][0][1] = 0;
    //     dp[0][0][2] = 0;

    //     // 第一天不能已卖出
    //     dp[0][1][0] = -prices[0];
    //     dp[0][1][1] = -prices[0];
    //     dp[0][1][2] = -prices[0];

    //     // 处理后续日期
    //     for (int i = 1; i < m; i++)
    //     {
    //         dp[i][0][0] = 0;
    //         dp[i][0][1] = max(dp[i - 1][1][0] + prices[i], dp[i - 1][0][1]);
    //         dp[i][0][2] = max(dp[i - 1][1][1] + prices[i], dp[i - 1][0][2]);
    //         dp[i][1][0] = max(dp[i - 1][0][0] - prices[i], dp[i - 1][1][0]);
    //         dp[i][1][1] = max(dp[i - 1][0][1] - prices[i], dp[i - 1][1][1]);
    //         dp[i][1][2] = 0;
    //     }

    //     return max(dp[m - 1][0][1], dp[m - 1][0][2]);
    // }
};
// @lc code=end
