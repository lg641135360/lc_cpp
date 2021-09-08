/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i =  0,j = nums.size() - 1;
        while(i <= j){
            int mid  = i  + (j - i )/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) j = mid -1;
            else i = mid +1;
        }
        // 此时i已经是target该在的地方了
        return i;
    }
};
// @lc code=end

