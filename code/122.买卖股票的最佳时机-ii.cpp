/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
    // [7,1,5,6]最大是第二天买入，第四天卖出
    // 为什么是第四天而不是第三天？
    // 可以简化为第三天卖出之后同一天又买进了
    // 只要今天比昨天大，就可以卖出（隐藏的）
    // 贪心 只要今天比昨天大，就贪心进行交易（加上差值）
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for(int i =1;i<prices.size();i++)
            if(prices[i] > prices[i-1])
                ans += prices[i] - prices[i-1];
        return ans;
    }
};
// @lc code=end

