/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 丢失的数字
 */

// @lc code=start
class Solution {
public:
    // 拉胯方法
    int missingNumber(vector<int>& nums) {
        set<int> s;
        for(auto n:nums)
            s.insert(n);
        for(int i=0;i<=nums.size();++i) {
            if(s.find(i) == s.end()) 
                return i;
        }
        return -1;
    }
};
// @lc code=end

