/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
class Solution
{
public:
    // bool isSubsequence(string s, string t)
    // {
    //     int i = 0, j = 0;
    //     int sN = s.size() - 1, tN = t.size() - 1;
    //     for (; i <= sN && j <= tN;)
    //     {
    //         if (s[i] == t[j])
    //         {
    //             i++;
    //             j++;
    //         }
    //         else
    //             j++;
    //     }
    //     if (i <= sN && j == tN + 1)
    //         return false;
    //     else
    //         return true;
    // }

    bool isSubsequence(string s, string t)
    {
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 1; j <= t.size(); j++)
            {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = dp[i][j - 1];
            }
        }
        if (dp[s.size()][t.size()] == s.size())
            return true;
        else
            return false;
    }
};
// @lc code=end
