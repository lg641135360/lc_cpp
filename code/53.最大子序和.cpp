/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        dp[0] = nums[0];
        int max_res = dp[0];
        for(int i = 1;i<nums.size();++i){
            dp[i] = max(dp[i-1]+nums[i] ,nums[i]);
            if(max_res<dp[i])
                max_res = dp[i];
        }
        return max_res;
    }
};
// @lc code=end

