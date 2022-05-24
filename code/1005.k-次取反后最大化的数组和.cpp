/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 */

// @lc code=start
class Solution
{
public:
    int largestSumAfterKNegations(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end(), [](const int a, const int b)
             { return abs(a) > abs(b); });
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < 0 && k > 0)
            {
                nums[i] *= -1;
                k--;
            }
        }
        if (k % 2 == 1)
            nums[nums.size() - 1] *= -1;
        int res = 0;
        for (int a : nums)
            res += a;
        return res;
    }
};
// @lc code=end
