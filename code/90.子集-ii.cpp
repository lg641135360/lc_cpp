// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem90.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution
{
    // public:
    // 有重复元素就需要排序，将重复元素排列在一起好去重复
    //     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    //         vector<int> track;
    //         sort(nums.begin(),nums.end()); // 去重需要排序
    //         backtrack(nums,0,track);
    //         return res;
    //     }
    // private:
    //     vector<vector<int>> res;
    //     void backtrack(vector<int>& nums,int start, vector<int>& track){
    //         res.push_back(track);
    //         // 跟无重复数字版本唯一区别：在每个组合上去除重复
    //         for(int i= start; i< nums.size(); i++){
    //             // 嵌套一个if，挑选出
    //             // 前元素与现元素相同时，直接剪枝，第一个条件是隐藏条件
    //             // 不用used数组是因为使用了start索引，不需要从0重新开始遍历
    //             if(i>start && nums[i] == nums[i-1])
    //                 continue;

    //                 // 选择
    //             track.push_back(nums[i]);
    //             // 递归回溯
    //             backtrack(nums,i+1,track);
    //             // 回撤
    //             track.pop_back();

    //         }
    //     }

    // vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    //     vector<vector<int>> res;
    //     vector<int> track;
    //     set<vector<int>> res_set;  // 去重使用集合set
    //     sort(nums.begin(),nums.end());  // 对nums进行排序
    //     res.push_back(track);    // 先传入一个处理逻辑不一样的空集
    //     generate(0,nums,res,track,res_set);
    //     return res;
    // }

    // void generate(int i,vector<int> &nums,
    //                 vector<vector<int>> &res,
    //                 vector<int> &track,set<vector<int>> &res_set){
    //     if(i>=nums.size()) return ;
    //     track.push_back(nums[i]);
    //     if(res_set.find(track) == res_set.end()){
    //         res.push_back(track);     // 去重结果集中没找到就插入
    //         res_set.insert(track);
    //     }
    //     // 使用第i个元素
    //     generate(i+1,nums,res,track,res_set);
    //     // 回溯并且调用下一层递归
    //     track.pop_back();
    //     generate(i+1,nums,res,track,res_set);
    // }
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtrack(nums, 0, used);
        return res;
    }

private:
    vector<vector<int>> res;
    vector<int> path;
    void backtrack(vector<int> &nums, int startIndex, vector<bool> &used)
    {
        res.push_back(path);
        for (int i = startIndex; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false)
                continue;
            path.push_back(nums[i]);
            used[i] = true;
            backtrack(nums, i + 1, used);
            used[i] = false;
            path.pop_back();
        }
    }
};
// @lc code=end
