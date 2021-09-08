/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */

// @lc code=start
class Solution {
public:
    // 偷懒方法 结果结果还不错？双90？
    // int findMin(vector<int>& nums) {
    //     sort(nums.begin(),nums.end());
    //     return nums[0];
    // }

    // 二分法
    // 根据这种旋转法则，nums肯定可以被拆分成两个有序数组
    int findMin(vector<int>& nums) {
        int min_ = INT_MAX;
        for(int i = nums.size()-1;i>=0;i--)
            if(nums[i] < min_) min_ = nums[i];
        return min_;
    }
};
// @lc code=end

