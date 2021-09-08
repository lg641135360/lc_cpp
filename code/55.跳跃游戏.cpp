/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> index;
        for(int i=0;i<nums.size();++i)
            index.push_back(i+nums[i]);
        int jump = 0;   // 当前跳到的位置
        int max_index = index[0];  // 当前能跳到最大位置
        while(jump<index.size() && jump<=max_index) {
            if(max_index<index[jump])
                max_index = index[jump];
            jump++;   // 扫描jump
        }
        if(jump==index.size())
            return true;
        return false;
    }
};
// @lc code=end

