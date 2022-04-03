/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution
{
    // public:
    //     vector<vector<int>> permuteUnique(vector<int>& nums) {
    //         vector<int> track;
    //         n = nums.size();
    //         used.resize(n,false);
    //         sort(nums.begin(),nums.end());
    //         backtrack(nums,track);
    //         return res;
    //     }
    // private:
    //     vector<vector<int>> res;
    //     int n;
    //     vector<bool> used;
    //     void backtrack(vector<int>& nums,vector<int>& track){
    //         if(track.size()==n){
    //             res.push_back(track);
    //             return;
    //         }
    //         for(int i = 0;i<nums.size();i++){
    //             if(used[i]) continue;
    //             if(i >0&& nums[i] == nums[i-1] && !used[i-1]) continue;
    //             used[i] = true;
    //             track.push_back(nums[i]);
    //             backtrack(nums,track);
    //             track.pop_back();
    //             used[i] = false;

    //         }
    //     }

public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
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
                if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false)
                    continue;
                if (used[i] == false)
                {
                    used[i] = true;
                    path.push_back(nums[i]);
                    backtrack(nums, used);
                    path.pop_back();
                    used[i] = false;
                }
            }
        }
    }
};
// @lc code=end
