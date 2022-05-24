/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int result = 0;
        int minPrice = prices[0]; // 记录最低价格
        for (int i = 1; i < prices.size(); i++)
        {
            // 情况二：相当于买入
            if (prices[i] < minPrice)
                minPrice = prices[i];

            // 情况三：保持原有状态（因为此时买则不便宜，卖则亏本）
            if (prices[i] >= minPrice && prices[i] <= minPrice + fee)
            {
                continue;
            }

            // 计算利润，可能有多次计算利润，最后一次计算利润才是真正意义的卖出
            if (prices[i] > minPrice + fee)
            {
                result += prices[i] - minPrice - fee;
                minPrice = prices[i] - fee; // 情况一，这一步很关键
            }
        }
        return result;
    }
};
// @lc code=end
