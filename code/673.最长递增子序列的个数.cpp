/*
 * @lc app=leetcode.cn id=673 lang=cpp
 *
 * [673] 最长递增子序列的个数
 */

// @lc code=start
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        int dp[n],count[n];
        for(int i=0;i<n;i++)
            dp[i] = count[i] = 1;
        
        for(int j=0;j<n;j++)
        {
            for(int i=0;i<j;i++)
            {
                if(nums[i] < nums[j])
                {
                    if(dp[i] + 1 > dp[j])
                    {
                        dp[j] = dp[i] + 1;
                        count[j] = count[i];
                    }
                    else if(dp[i] + 1 == dp[j])
                        count[j] += count[i];
                }
            }
        }

        int maxLength = 0;
        for(auto it:dp)
            maxLength = max(maxLength,it);
        
        int res = 0;
        for(int i=0;i<n;i++)
        {
            if(maxLength == dp[i])
                res+=count[i];
        }
        return res;
    }
};
// @lc code=end

