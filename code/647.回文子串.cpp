/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

// @lc code=start
class Solution {
public:
    // 同5，使用dp[i][j]表示下标从i到j的串是否回文
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;

        // base case
        if(s.empty())
            return 0;

        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for(int i=n-1;i>=0;--i)
        {
            for(int j=i;j<n;j++)
            {
                if(i == j)   // 只有一个字符肯定是回文
                    dp[i][j] = true;
                else if(j == i+1)  // 两个则需要判断是否相同
                {
                    dp[i][j] = (s[i] == s[j]);
                }
                else // 3个及以上则需判断头尾是否相同以及去掉头尾后是否回文
                    dp[i][j]=((s[i] == s[j]) && dp[i+1][j-1]);
                if(dp[i][j])  // 判断完了及时更新回文串的数目
                    count++;
            }
        }
        return count;
    }
};
// @lc code=end

