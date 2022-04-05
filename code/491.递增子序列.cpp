/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 递增子序列
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        backtrack(nums, 0);
        return res;
    }

private:
    vector<vector<int>> res;
    vector<int> path;
    void backtrack(vector<int> &nums, int startIndex)
    {
        if (path.size() > 1)
            res.push_back(path);
        int used[201] = {0}; // 这里使用数组来进行去重操作，题目说数值范围[-100, 100]
        for (int i = startIndex; i < nums.size(); i++)
        {
            if ((!path.empty() && nums[i] < path.back()) || used[nums[i] + 100] == 1)
            {
                continue;
            }
            used[nums[i] + 100] = 1; // 记录这个元素在本层用过了，本层后面不能再用了
            path.push_back(nums[i]);
            backtrack(nums, i + 1);
            path.pop_back();
        }
    }
};
// @lc code=end
