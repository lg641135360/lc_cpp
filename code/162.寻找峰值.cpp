/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */

// @lc code=start
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int index = -1;
        for(int i=0;i<nums.size()-1;++i)
            if(nums[i] > nums[i+1]) {
                index = i;
                break;
            }
                
        if(index == -1)
            return nums.size()-1;
        else return index;
    }
};
// @lc code=end