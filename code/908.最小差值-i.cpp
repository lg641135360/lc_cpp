/*
 * @lc app=leetcode.cn id=908 lang=cpp
 *
 * [908] 最小差值 I
 */

// @lc code=start
class Solution
{
public:
    int smallestRangeI(vector<int> &nums, int k)
    {
        // 排序
        sort(nums.begin(), nums.end());
        if (nums[nums.size() - 1] - nums[0] <= 2 * k)
            return 0;
        else
            return nums[nums.size() - 1] - nums[0] - 2 * k;
    }
};
// @lc code=end
