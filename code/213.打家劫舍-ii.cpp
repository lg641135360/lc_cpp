/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution
{
public:
    // dp[i]表示以i为结束位置的最大偷盗金额
    // dp2[i] 表示不以i为结束位置的最大偷盗金额
    // int rob(vector<int> &nums)
    // {
    //     int n = nums.size();
    //     // base case
    //     vector<int> dp(n, 0);
    //     vector<int> dp2(n, 0);

    //     if (nums.size() == 1)
    //     {
    //         dp[0] = nums[0];
    //         dp2[0] = 0;
    //         return max(dp[n - 1], dp2[n - 1]);
    //     }
    //     if (nums.size() == 2)
    //     {
    //         dp[0] = nums[0];
    //         dp2[0] = 0;
    //         dp[1] = nums[1];
    //         dp2[1] = nums[0];
    //         return max(dp[n - 1], dp2[n - 1]);
    //     }
    //     if (nums.size() == 3)
    //     {
    //         dp[0] = nums[0];
    //         dp2[0] = 0;
    //         dp[1] = nums[1];
    //         dp2[1] = nums[0];
    //         dp[2] = nums[2];
    //         dp2[2] = max(dp[1], dp2[1]);
    //         return max(dp[n - 1], dp2[n - 1]);
    //     }

    //     // 此时应大于三个数字
    //     bool hao = true;
    //     for (int i = 3; i < nums.size(); ++i)
    //     {
    //         dp[0] = nums[0];
    //         dp2[0] = 0;
    //         dp[1] = nums[1];
    //         dp2[1] = nums[0];
    //         dp[2] = nums[2];
    //         dp2[2] = max(dp[1], dp2[1]);

    //         // 取两个的最大值
    //         // 要看第一个元素是否被选
    //         if (hao) // 此时没加
    //             dp[i] = dp2[i - 1] + nums[i];
    //         else
    //             dp[i] = dp2[i - 1] + nums[i] - nums[0];
    //         // 尝试加上第一个被取消的元素
    //         // [200,3,140,20,10] 第一个元素加了两次，这里可以使用别的方法

    //         dp2[i] = max(dp2[i - 1], dp[i - 1] + nums[0]);
    //     }

    //     return max(dp[n - 1], dp2[n - 1]);
    // }

    // 第一个和最后一个不能同时抢
    // dp1[i] 前i家抢到最大值 不抢第一家
    // dp2[i] 前i家抢到最大值 不抢最后一家
    // int rob(vector<int> &nums)
    // {
    //     int n = nums.size();

    //     if (n == 1)
    //         return nums[0];
    //     else if (n == 2)
    //         return nums[0] > nums[1] ? nums[0] : nums[1];
    //     // 此时n>=3
    //     else
    //     {
    //         vector<int> dp1(n, 0);
    //         vector<int> dp2(n, 0);

    //         // 初始化
    //         dp1[0] = 0;       // 不抢第一家
    //         dp2[0] = 0;       // 不抢最后一家
    //         dp1[1] = nums[1]; // 不抢第一家，这里则选择第二家
    //         dp2[1] = nums[0]; // 不抢最后一家，这里选择第一家

    //         // for
    //         for (int i = 2; i < n; i++)
    //         {
    //             // 不抢第一家
    //             dp1[i] = max(dp1[i - 1], dp1[i - 2] + nums[i]);
    //             // 不抢最后一家 dp[i-2]没有抢最后一家nums[i-2]，所以可以加
    //             dp2[i] = max(dp2[i - 1], dp2[i - 2] + nums[i - 1]);
    //         }
    //         return max(dp1[n - 1], dp2[n - 1]);
    //     }
    // }

    int rob(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        int result1 = robRange(nums, 0, nums.size() - 2); // 情况二
        int result2 = robRange(nums, 1, nums.size() - 1); // 情况三
        return max(result1, result2);
    }

private:
    int robRange(vector<int> &nums, int start, int end)
    {
        if (end == start)
            return nums[start];
        vector<int> dp(nums.size());
        dp[start] = nums[start];
        dp[start + 1] = max(nums[start], nums[start + 1]);
        for (int i = start + 2; i <= end; i++)
        {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[end];
    }
};
// @lc code=end
