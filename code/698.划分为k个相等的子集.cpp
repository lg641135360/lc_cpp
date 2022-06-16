/*
 * @lc app=leetcode.cn id=698 lang=cpp
 *
 * [698] 划分为k个相等的子集
 */

// @lc code=start
class Solution
{
public:
    bool canPartitionKSubsets(vector<int> &nums, int k)
    {
        int sum = 0;

        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];
        if (sum % k != 0)
            return false;

        vector<int> dp(160000, 0);

        int target = sum / k;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = target; j >= nums[i]; j--)
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
        }

        if (dp[target] == target)
            return true;
        return false;
    }
};
// @lc code=end
