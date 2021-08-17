/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除有序数组中的重复项 II
 */

// @lc code=start
class Solution {
public:
    // 每个元素 最多出现两次
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        // 当长度小于等于2，不需要更改
        if(n<=2) return n;
        for(int i=0;i<nums.size();) {
            if(i+2<nums.size()) {
                if(nums[i]^nums[i+1]) ++i;
                else if(nums[i]^nums[i+2]) i+=2;
                else {
                    nums.erase(nums.begin()+i);
                    continue;
                }
            }
            else ++i;
        }
        return nums.size();
    }
};
// @lc code=end

