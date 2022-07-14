/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        if(s.size() < 2)
            return 0;
        vector<int> res;
        // 利用栈记录上次匹配的位置
        stack<int> st;
        for (int i = 0; i < s.size();i++)
        {
            if(!st.empty() && s[i] == ')')
            {
                int tmp = st.top();
                st.pop();
                // 将这次匹配的(的索引加入数组
                res.push_back(tmp);
                // 将这次匹配的)的索引加入数组
                res.push_back(i);
            }
            // 遇到(将其索引加入栈
            if(s[i] == '(')
                st.push(i);
        }
        sort(res.begin(), res.end());
        int i = 0;
        int ans = 0;
        int n = res.size();
        while(i < n)
        {
            int j = i;
            // 当后一个比现在这个刚好大1，说明连续
            while(j < n-1 && res[j+1] == res[j] +1)
                j += 1;
            // 重新计算最长的连续
            ans = max(ans, j - i + 1);
            // 遍历下一个位置
            i = j + 1;
        }
        return ans;
    }

    // int longestValidParentheses(string s)
    // {
    //     int maxLen = 0;
    //     int len = s.size();
    //     vector<int> dp(len, 0);
    //     for (int i = 1; i < len; i++)
    //     {
    //         if (s[i] == ')')
    //         {
    //             if (s[i - 1] == '(')
    //             {
    //                 if (i - 2 >= 0)
    //                     dp[i] = dp[i - 2] + 2;
    //                 else
    //                     dp[i] = 2;
    //             }
    //             else if (s[i - dp[i - 1] - 1] == '(')
    //             {
    //                 if (i - dp[i - 1] - 2 >= 0)
    //                     dp[i] = dp[i - 1] + 2 + dp[i - dp[i - 1] - 2];
    //                 else
    //                     dp[i] = dp[i - 1] + 2;
    //             }
    //         }
    //         maxLen = max(maxLen, dp[i]);
    //     }
    //     return maxLen;
    // }
};
// @lc code=end
