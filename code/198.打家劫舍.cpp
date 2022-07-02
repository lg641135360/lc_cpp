/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution
{
public:
    // int rob(vector<int> &nums)
    // {
    //     if (nums.size() == 0)
    //         return 0;
    //     if (nums.size() == 1)
    //         return nums[0];
    //     // 进行到这里，至少有两个元素
    //     vector<int> dp(nums.size(), 0);
    //     dp[0] = nums[0];
    //     dp[1] = max(nums[0], nums[1]);
    //     for (int i = 2; i < nums.size(); ++i)
    //         dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    //     return dp[nums.size() - 1];
    // }

    int rob(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++)
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        return dp[nums.size() - 1];
    }
};
// @lc code=end
