/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start
class Solution
{
public:
    // int wiggleMaxLength(vector<int>& nums) {
    //     if(nums.size() < 2)
    //         return nums.size();
    //     static const int BEGIN = 0;
    //     static const int UP = 1;
    //     static const int DOWN = 2;

    //     int STATE = BEGIN;
    //     int max_length = 1;

    //     for(int i=1;i<nums.size();++i) {
    //         switch(STATE) {
    //             case BEGIN:
    //                 if(nums[i-1] < nums[i]) {
    //                     STATE = UP;
    //                     max_length ++;
    //                 }
    //                 else if(nums[i-1] > nums[i]) {
    //                     STATE = DOWN;
    //                     max_length ++;
    //                 }
    //                 break;
    //             case UP:
    //                 if(nums[i-1] > nums[i]) {
    //                     STATE = DOWN;
    //                     max_length ++;
    //                 }
    //                 break;
    //             case DOWN:
    //                 if(nums[i-1] < nums[i]) {
    //                     STATE = UP;
    //                     max_length++;
    //                 }
    //                 break;
    //         }
    //     }
    //     return max_length;
    // }

    // int wiggleMaxLength(vector<int> &nums)
    // {
    //     if (nums.size() <= 1)
    //         return nums.size();
    //     int curDiff = 0;
    //     int preDiff = 0;
    //     int res = 1;
    //     for (int i = 0; i < nums.size() - 1; i++)
    //     {
    //         curDiff = nums[i + 1] - nums[i];
    //         if ((curDiff > 0 && preDiff <= 0) || (preDiff >= 0 && curDiff < 0))
    //         {
    //             res++;
    //             preDiff = curDiff;
    //         }
    //     }
    //     return res;
    // }
    int dp[1005][2];
    int wiggleMaxLength(vector<int> &nums)
    {
        memset(dp, 0, sizeof dp);
        dp[0][0] = dp[0][1] = 1;

        for (int i = 1; i < nums.size(); ++i)
        {
            dp[i][0] = dp[i][1] = 1;
            for (int j = 0; j < i; ++j)
            {
                if (nums[j] > nums[i])
                    dp[i][1] = max(dp[i][1], dp[j][0] + 1);
            }

            for (int j = 0; j < i; ++j)
            {
                if (nums[j] < nums[i])
                    dp[i][0] = max(dp[i][0], dp[j][1] + 1);
            }
        }
        return max(dp[nums.size() - 1][0], dp[nums.size() - 1][1]);
    }
};
// @lc code=end
