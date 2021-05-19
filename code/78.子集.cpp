/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> track;
        backtrack(nums,0,track);
        return res;
    }
private:
    vector<vector<int>> res;
    void backtrack(vector<int>& nums,int pos,vector<int>& track){
        res.push_back(track);
        for(int i=pos;i<nums.size();i++){
            track.push_back(nums[i]);
            backtrack(nums,i+1,track);
            track.pop_back();
        }
    }
};
// @lc code=end

