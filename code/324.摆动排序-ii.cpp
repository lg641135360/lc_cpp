/*
 * @lc app=leetcode.cn id=324 lang=cpp
 *
 * [324] 摆动排序 II
 */

// @lc code=start
class Solution {
public:
    // 一半小，一半大
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size() <= 2)
            return ;
        for(int i=1;i<nums.size()/2;i+=2) 
            swap(nums[i],nums[nums.size() - i -1]);
    }
};
// @lc code=end

