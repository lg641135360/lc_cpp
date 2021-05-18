/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> track;
        backtrack(k,n,1,track);
        return res;
    }

private:
    vector<vector<int>> res;
    void backtrack(int k,int n,int start,vector<int>& track){
        if(n < 0 || track.size() > k) return;
        if(track.size() == k && n==0){
            res.push_back(track);
            return;
        }
        for(int i = start;i<=9;i++){
            track.push_back(i);
            // 这里为什么用的k呢
            backtrack(k,n-i,i+1,track);
            track.pop_back();
        }
    }
};
// @lc code=end

