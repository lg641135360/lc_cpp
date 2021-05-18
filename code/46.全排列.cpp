/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        used.resize(n,false);
        vector<int> track;
        backtrack(nums,track);
        return res;
    }

private:
    vector<vector<int>> res;
    int n;
    vector<bool> used;
    void backtrack(vector<int>& nums,vector<int>& track){
        if(track.size() == n) {
            res.push_back(track);
            return;
        }
        for(int i = 0; i < n; i++){
            // 这个不能少了，这里直接把取过的跳过
            if(used[i]) continue;
            if(i>0 && nums[i] == nums[i-1] && !used[i-1]) 
                continue;
            track.push_back(nums[i]);
            used[i] = true;
            backtrack(nums,track);
            track.pop_back();
            used[i] = false;
        }
    }
};
// @lc code=end

