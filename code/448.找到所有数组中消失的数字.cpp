/*
 * @lc app=leetcode.cn id=448 lang=cpp
 *
 * [448] 找到所有数组中消失的数字
 */

// @lc code=start
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        set<int> tmp;
        vector<int> res;
        for(int n:nums)
            tmp.insert(n);
        for(int i=1;i<=nums.size();++i) {
            if(tmp.find(i) == tmp.end())
                res.push_back(i);
        }
        return res;
    }
};
// @lc code=end

