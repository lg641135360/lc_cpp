/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        dp[0] = 1;
        int LIS = 1;  // 将最大的选择出来
        for(int i =1;i<nums.size();++i){
            dp[i] = 1;  // 基准值（有的元素为结尾长度就是1）
            for(int j=0;j<i;++j)
                if(nums[i] > nums[j]&&dp[i]<dp[j]+1)
                    dp[i] = dp[j] + 1;
            if(LIS<dp[i])
                LIS = dp[i];
        }
        return LIS;
    }
};
// @lc code=end

