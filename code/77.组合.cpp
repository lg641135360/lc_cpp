/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution
{
public:
    //     vector<vector<int>> combine(int n, int k) {
    //         //
    //         if(k<= 0 || n <= 0) return res;
    //         vector<int> track;
    //         backtrack(n,k,1,track);
    //         return res;
    //     }

    // private:
    //     vector<vector<int>> res;
    //     // n决定树的宽度，k决定树的深度
    //     void backtrack(int n,int k,int start,vector<int> track){
    //         // 到达叶子节点才更新 res
    //         if(k == track.size()) {
    //             res.push_back(track);
    //             return;
    //         }
    //         // i从start开始递增，横向遍历回溯树
    //         for(int i=start;i<=n;i++){
    //             // 选择
    //             track.push_back(i);
    //             // 回溯
    //             backtrack(n,k,i+1,track);
    //             // 撤销选择
    //             track.pop_back();
    //         }
    //     }
    // 决定是否将当前数字加入到结果中
    // vector<vector<int>> combine(int n, int k) {
    //     vector<vector<int>> ans;
    //     vector<int> comb(k,0);  // 存储k个数字下标的数组
    //     int count= 0;          // 计数
    //     // 从数字1开始 看是否要加入结果集合
    //     backtrack(ans,comb,count,1,n,k);
    //     return ans;
    // }
    // void backtrack(vector<vector<int>> &ans,vector<int> &comb,int &count,int pos,int n,int k){
    //     if(count==k) {
    //         ans.push_back(comb);
    //         return;
    //     }
    //     for(int i =pos;i<=n;i++){
    //         comb[count++] = i; // 选择当前节点
    //         backtrack(ans,comb,count,i+1,n,k);
    //         --count;     // 回到之前节点
    //     }
    // }
    vector<vector<int>> combine(int n, int k)
    {
        res.clear();
        path.clear();
        backtrack(n, k, 1);
        return res;
    }

private:
    vector<vector<int>> res;
    vector<int> path;

    void backtrack(int n,int k,int startIndex)
    {
        if(path.size() == k)
        {
            res.push_back(path);
            return;
        }
        else{
            for (int i = startIndex; i <= n-(k-path.size()) + 1;i++)
            {
                path.push_back(i);
                backtrack(n, k, i + 1);
                path.pop_back();
            }
        }
    }
};
// @lc code=end
