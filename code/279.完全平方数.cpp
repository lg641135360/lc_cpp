/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
class Solution
{
public:
    // dp
    // int numSquares(int n)
    // {
    //     vector<int> dp(n + 1, INT_MAX);
    //     dp[0] = 0;
    //     for (int i = 1; i * i <= n; i++)
    //         for (int j = 1; j <= n; j++)
    //             if (j - i * i >= 0)
    //                 dp[j] = min(dp[j - i * i] + 1, dp[j]);
    //     return dp[n];
    // }

    int numSquares(int n)
    {
        // 构造完全平方数数组
        list<int> square_nums;
        for (int i = 1; i * i <= n; ++i)
            square_nums.push_back(i * i);

        // 使用set去重复
        set<int> que;
        que.insert(n);

        int level = 0;
        while(!que.empty())
        {
            level += 1;
            set<int> next_que;

            for(int remain : que)
            {
                for(int square : square_nums)
                {
                    // 余数是完全平方数，退出循环
                    if(remain == square)
                        return level;
                    else if(remain < square)
                        break;
                    else
                        next_que.insert(remain - square);
                }
            }
            que = next_que;
        }
        return level;
    }
};
// @lc code=end
