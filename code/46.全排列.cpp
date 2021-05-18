/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> track;
        n = nums.size();
        used.resize(n,false);
        backtrack(nums,track);
        return res;
    }
    
private:
    vector<vector<int>> res;
    int n; // nums的长度
    vector<bool> used;
    void backtrack(vector<int>& nums,vector<int>& track){
        if(track.size() == n) {
            res.push_back(track);
            return;
        }
        for(int i = 0;i<n;i++){
            if(used[i]) continue;
            track.push_back(nums[i]);
            used[i] = true;
            backtrack(nums,track);
            track.pop_back();
            used[i] = false; 
        }
    }
    
    
};
// @lc code=end

