/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
class Solution {
public:
    // 没想到好方法
    int firstMissingPositive(vector<int>& nums) {
        
        int n = nums.size();
        for (int i = 0; i < n; i++) 
            if (nums[i] <= 0)     // 负数转正，移到
                nums[i] = n + 1;
        for (int i = 0; i < n; i++) 
            if (abs(nums[i]) <= n && nums[abs(nums[i]) - 1] > 0) 
                nums[abs(nums[i]) - 1] *= -1;
        for (int i = 0; i < n; i++) 
            if (nums[i] > 0) 
                return i + 1;
        return n + 1;
    }
};
// @lc code=end

