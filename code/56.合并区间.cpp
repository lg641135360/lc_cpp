/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> res;
        if (intervals.size() == 0)
            return res;
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[0] < b[0]; });
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++)
        {
            if (res.back()[1] >= intervals[i][0])
            { // 合并区间
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
            else
            {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};
// @lc code=end
