/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution
{
public:
    // 使用dp，考虑dp数组元素的含义
    // dp[i][j] 表示从i到j的子串 是否回文
    string longestPalindrome(string s)
    {
        int n = s.size();
        string ans;
        // base base
        if (s.empty())
            return NULL; // 空串没有回文

        int len = 1;

        // dp[i][j]表示下标从i到j的子串是否回文
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = n - 1; i >= 0; i--)
        { // 从后往前遍历
            for (int j = i; j < n; j++)
            {
                if (i == j)
                    dp[i][j] = true; // 一个字符必回文
                else if (j == i + 1) // 只有两个字符时需要判断是否相等
                    dp[i][j] = (s[i] == s[j]);
                else // 三个以上看s[i]与s[j]是否相等且去头尾后是否回文
                    dp[i][j] = ((s[i] == s[j]) && dp[i + 1][j - 1]);
                // 判断完毕，更新最长回文串
                if (dp[i][j])
                {
                    if (j - i + 1 >= len)
                    {
                        len = j - i + 1;
                        ans = s.substr(i, j - i + 1); // 更新最长串
                    }
                }
            }
        }
        return ans;
    }

    // string longestPalindrome(string s)
    // {
    //     if(s.empty())
    //         return s;
    //     int start = 0, maxLen = 0;
    //     for (int i = 0; i < s.size();++i)
    //     {
    //         int len1 = extend(s, i, i);
    //         int len2 = extend(s, i, i + 1);
    //         int len = max(len1, len2);
    //         if(len > maxLen)
    //         {
    //             start = i - (len - 1) / 2;
    //             maxLen = len;
    //         }
    //     }
    //     return s.substr(start, maxLen);
    // }

    // int extend(string &s, int L, int R)
    // {
    //     while (L >= 0 && R < s.size() && s[L] == s[R])
    //     {
    //         ++L;
    //         --R;
    //     }
    //     return R - L + 1;
    // }
};
// @lc code=end
