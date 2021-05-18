/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> track;
        // 排序去重
        sort(candidates.begin(),candidates.end());
        backtrack(candidates,target,0,track);
        return res;
    }
private:
    vector<vector<int>> res;
    void backtrack(vector<int>& candidates,int target,int start,vector<int>& track){
        if(target == 0){
            res.push_back(track);
            return;
        }
        // 注意循环的条件
        for(int i = start;i<candidates.size() && target-candidates[i] >= 0;i++){
            // 树层去重
            if(i==start || candidates[i] != candidates[i-1]){
                track.push_back(candidates[i]);
                backtrack(candidates,target-candidates[i],i+1,track);
                track.pop_back();
            }
            
        }
    }
};
// @lc code=end

