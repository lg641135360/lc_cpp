/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        // base case
        if (height.size() == 0)
            return 0;
        int begin = 0, end = height.size() - 1;
        int res = INT_MIN;
        while (begin < end)
        {
            res = max(res, min(height[begin], height[end]) * (end - begin));
            if (height[begin] <= height[end])
                begin++;
            else
                end--;
        }
        return res;
    }
};
// @lc code=end
