/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        // 
        if(k<= 0 || n <= 0) return res;
        vector<int> track;
        backtrack(n,k,1,track);
        return res;
    }

private:
    vector<vector<int>> res;
    // n决定树的宽度，k决定树的深度
    void backtrack(int n,int k,int start,vector<int> track){
        // 到达叶子节点才更新 res
        if(k == track.size()) {
            res.push_back(track);
            return;
        }
        // i从start开始递增，横向遍历回溯树
        for(int i=start;i<=n;i++){
            // 选择
            track.push_back(i);
            // 回溯
            backtrack(n,k,i+1,track);
            // 撤销选择
            track.pop_back();
        }
    }
};
// @lc code=end

