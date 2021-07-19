/*
 * @lc app=leetcode.cn id=414 lang=cpp
 *
 * [414] 第三大的数
 */

// @lc code=start
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s;
        for(int i=0;i<nums.size();++i) {
            if(s.size() < 3)
                s.insert(nums[i]);
            // else if和if只能运行一个
            else if(nums[i] > *(s.begin())&& s.find(nums[i]) == s.end()) {
                s.erase(s.begin());
                s.insert(nums[i]);
            }
        }
        if(s.size() < 3) return *(--s.end());
        return *(s.begin());
    }
};
// @lc code=end

