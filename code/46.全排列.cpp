/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution
{
    // public:

    //     vector<vector<int>> permute(vector<int>& nums) {
    //         vector<int> track;
    //         n = nums.size();
    //         used.resize(n,false);
    //         backtrack(nums,track);
    //         return res;
    //     }

    // private:
    //     vector<vector<int>> res;
    //     int n; // nums的长度
    //     vector<bool> used;
    //     void backtrack(vector<int>& nums,vector<int>& track){
    //         if(track.size() == n) {
    //             res.push_back(track);
    //             return;
    //         }
    //         for(int i = 0;i<n;i++){
    //             if(used[i]) continue;
    //             track.push_back(nums[i]);
    //             used[i] = true;
    //             backtrack(nums,track);
    //             track.pop_back();
    //             used[i] = false;
    //         }
    //     }
    // 对于每一个当前位置i，将其与之后的所有位置交换，然后接着处理i+1，直到处理到最后一位
    // 利用回溯法，只对原数组进行处理，处理完了修改回来
    // vector<vector<int>> permute(vector<int>& nums) {
    //     vector<vector<int>> ans;
    //     backtrack(nums,0,ans); // 当前是0位置
    //     return ans;
    // }

    // void backtrack(vector<int> &nums,int index,vector<vector<int>> &ans){
    //     if(index == nums.size() - 1) { // 此时已经到了最后一个位置
    //         // 添加到答案中，这里是对原数组进行操作
    //         ans.push_back(nums);
    //         return ;
    //     }
    //     // 下面这里是i=index而不是index+1
    //     for(int i = index;i<nums.size();i++){
    //         swap(nums[i],nums[index]); // 与之后的元素一一交换
    //         backtrack(nums,index+1,ans);
    //         swap(nums[i],nums[index]);  // 递归完了记得回溯
    //     }
    // }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<bool> used(nums.size(), false);
        backtrack(nums, used);
        return res;
    }

private:
    vector<vector<int>> res;
    vector<int> path;

    void backtrack(vector<int> &nums, vector<bool> &used)
    {
        if (path.size() == nums.size())
        {
            res.push_back(path);
            return;
        }
        else
        {
            for (int i = 0; i < nums.size(); i++)
            {
                if (used[i])
                    continue;
                used[i] = true;
                path.push_back(nums[i]);
                backtrack(nums, used);
                path.pop_back();
                used[i] = false;
            }
        }
    }
};
// @lc code=end
