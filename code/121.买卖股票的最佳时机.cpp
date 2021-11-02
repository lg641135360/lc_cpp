/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    // 只能买卖一次，滑动窗口，左边是最小，右边是最大
    int maxProfit(vector<int>& prices) {
        // 滑动窗口左边界 begin
        int begin = 0;
        int res = 0;

        for(int i=1;i<prices.size();) {
            // 只有当begin位置大于当前位置，才能移动左边界begin
            // begin位置要存放当前最小值
            if(prices[begin] > prices[i]) {
                begin = i;
                i++;
            }
            else {
                // 更新收益
                res = max((prices[i]-prices[begin]),res);
                i++;
            }

        }
        return res;
    }
};
// @lc code=end

