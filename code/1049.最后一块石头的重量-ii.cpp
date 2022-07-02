/*
 * @lc app=leetcode.cn id=1049 lang=cpp
 *
 * [1049] 最后一块石头的重量 II
 */

// @lc code=start
class Solution
{
public:
    int lastStoneWeightII(vector<int> &stones)
    {
        vector<int> dp(1501, 0);
        int sum = 0;
        for (int i = 0; i < stones.size(); i++)
            sum += stones[i];
        int target = sum / 2;
        for (int i = 0; i < stones.size(); i++)
        {
            for (int j = target; j >= stones[i]; j--)
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
        }
        return sum - dp[target] - dp[target];
    }
};
// @lc code=end
