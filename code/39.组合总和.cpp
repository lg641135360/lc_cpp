/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution
{
    // public:
    //     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    //         vector<int> track;
    //         sort(candidates.begin(),candidates.end());  // 树层之间需要去处重复，排序
    //         backtrack(candidates,target,0,track);
    //         return res;
    //     }
    // private:
    //     vector<vector<int>> res;
    //     // 参数不够，无法得到重复数字相加结果
    //     void backtrack(vector<int>& candidates,int target,int start,vector<int>& track){
    //         // 当target被减到0，那么已经凑出来了
    //         if(target==0){
    //             res.push_back(track);
    //             return ;
    //         }
    //         // 遍历结束条件,
    //         // 结束条件有两个，一个是到最后一个元素，另一个是target<当前元素
    //         for(int i=start;i<candidates.size() && target>= candidates[i]; i++){
    //             // 选择
    //             track.push_back(candidates[i]);
    //             // 回溯
    //             // 这里索引依然传入i，只有因为允许重复选值
    //             backtrack(candidates,target-candidates[i],i,track);
    //             // 撤销
    //             track.pop_back();
    //         }
    //     }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, 0);
        return res;
    }

private:
    vector<vector<int>> res;
    vector<int> path;

    void backtrack(vector<int> &candidates, int target, int sum, int startIndex)
    {
        if (sum > target)
            return;
        else if (sum == target)
        {
            res.push_back(path);
            return;
        }
        else
        {
            for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++)
            {
                sum += candidates[i];
                path.push_back(candidates[i]);
                backtrack(candidates, target, sum, i); // 不用i+1表示重复选
                sum -= candidates[i];
                path.pop_back();
            }
        }
    }
};
// @lc code=end
