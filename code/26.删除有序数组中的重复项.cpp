/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    // 使用双指针，慢指针指向第一个元素，快指针指向第二个
    // 遍历整个数组，当相等时候，j++即可；当ij指向元素不等时，用j处值覆盖i处值。最后返回i+1
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int i=0,j=1;
        for(;j<nums.size();j++){
            if(nums[i] != nums[j]){
                i++;
                nums[i] = nums[j];
            }
        }
        return i +1;
    }
};
// @lc code=end

