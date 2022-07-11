/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        // base case
        if (nums.size() == 3)
            return nums[0] + nums[1] + nums[2];

        int res = nums[0] + nums[1] + nums[2];

        sort(nums.begin(), nums.end());
        // 遍历最小值
        for (int i = 0; i < nums.size(); i++)
        {
            int l = i + 1, r = nums.size() - 1;
            while (l < r)
            {
                int x = nums[i] + nums[l] + nums[r];
                if(abs(x-target) < abs(res-target))
                    res = x;
                if(x > target)
                    r--;
                else if(x < target)
                    l++;
                else
                    return target;
            }
        }
        return res;
    }
};
// @lc code=end
