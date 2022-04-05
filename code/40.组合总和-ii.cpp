/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution
{
    // public:
    //     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    //         vector<int> track;
    //         // 排序去重
    //         sort(candidates.begin(),candidates.end());
    //         backtrack(candidates,target,0,track);
    //         return res;
    //     }
    // private:
    //     vector<vector<int>> res;
    //     void backtrack(vector<int>& candidates,int target,int start,vector<int>& track){
    //         if(target == 0){
    //             res.push_back(track);
    //             return;
    //         }
    //         // 注意循环的条件
    //         for(int i = start;i<candidates.size() && target-candidates[i] >= 0;i++){
    //             // 树层去重
    //             if(i==start || candidates[i] != candidates[i-1]){
    //                 track.push_back(candidates[i]);
    //                 backtrack(candidates,target-candidates[i],i+1,track);
    //                 track.pop_back();
    //             }

    //         }
    //     }

    // 递归调用时，计算已选择元素的sum，sum>target，剪枝，不再进行更深的搜索
    // vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    // {
    //     vector<vector<int>> res;
    //     vector<int> track;
    //     set<vector<int>> res_set;
    //     sort(candidates.begin(), candidates.end());
    //     generate(0, candidates, res, track, res_set, 0, target);
    //     return res;
    // }

    // void generate(int i, vector<int> &nums, vector<vector<int>> &res, vector<int> &track, set<vector<int>> &res_set,
    //               int sum, int target)
    // {
    //     // 当元素已经选完或track中元素和sum超出target
    //     if (i >= nums.size() || sum > target)
    //         return;
    //     sum += nums[i];
    //     track.push_back(nums[i]);
    //     // 当track中元素和已经是target且未添加时
    //     if (sum == target && res_set.find(track) == res_set.end())
    //     {
    //         res.push_back(track);
    //         res_set.insert(track);
    //     }
    //     generate(i + 1, nums, res, track, res_set, sum, target);
    //     sum -= nums[i];
    //     track.pop_back();
    //     generate(i + 1, nums, res, track, res_set, sum, target);
    // }
    // public:
    //     vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    //     {
    //         vector<bool> used(candidates.size(), false);
    //         sort(candidates.begin(), candidates.end());
    //         backtrack(candidates, target, 0, 0, used);
    //         return res;
    //     }

    // private:
    //     vector<vector<int>> res;
    //     vector<int> path;

    //     void backtrack(vector<int> &candidates, int target, int sum, int startIndex, vector<bool> &used)
    //     {
    //         if (sum == target)
    //         {
    //             res.push_back(path);
    //             return;
    //         }
    //         for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++)
    //         {
    //             if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false)
    //                 continue;
    //             sum += candidates[i];
    //             path.push_back(candidates[i]);
    //             used[i] = true;
    //             backtrack(candidates, target, sum, i + 1, used);
    //             used[i] = false;
    //             sum -= candidates[i];
    //             path.pop_back();
    //         }
    //     }
public:
    // 使用startIndex去重
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
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
        if (sum == target)
        {
            res.push_back(path);
            return;
        }
        else
        {
            for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++)
            {
                if (i > startIndex && candidates[i] == candidates[i - 1])
                    continue;
                sum += candidates[i];
                path.push_back(candidates[i]);
                backtrack(candidates, target, sum, i + 1);
                sum -= candidates[i];
                path.pop_back();
            }
        }
    }
};
// @lc code=end
