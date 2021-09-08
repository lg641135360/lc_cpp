/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    // 使用快慢指针
    void moveZeroes(vector<int>& nums) {
        int slowIndex = 0;
        for(int fastIndex = 0; fastIndex<nums.size() ;fastIndex++){
            // 不为0就交换位置，将0后移
            if(nums[fastIndex] != 0){
                swap(nums[slowIndex++],nums[fastIndex]);
            }
            // fastIndex指向位置为0，就将fastIndex后移
        }
    }
};
// @lc code=end

