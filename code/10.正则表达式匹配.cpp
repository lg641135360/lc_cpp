/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
class Solution
{
public:
    // 双指针  匹配不了aab c*a*b*
    // bool isMatch(string s, string p) {
    //     int m = s.size();
    //     int n = p.size();

    //     int i,j;
    //     for(i=0,j=0;i<m&&j<n;)
    //     {
    //         if(s[i] == p[j] && isChar(s[i]))
    //         {
    //             i++;   // 匹配到了，直接将初始串后移
    //             j++;
    //         }
    //         else

    //     }
    // }

    // bool isDot(char c)
    // {
    //     if(c=='.')
    //         return true;
    //     else return false;
    // }

    // bool isStar(char c)
    // {
    //     if(c=='*')
    //         return true;
    //     else return false;
    // }

    // bool isChar(char c)
    // {
    //     if(!isDot(c) && !isStar(c))
    //         return true;
    //     else return false;
    // }

    // 从左到右dfs匹配回溯剪枝
    // bool isMatch(string s, string p)
    // {
    //     return matching(s, p, 0, 0);
    // }

    // bool matching(string s, string p, int ps, int pp)
    // {
    //     // 匹配成功
    //     if (ps >= s.size() && pp >= p.size())
    //         return true;

    //     bool flag = false;
    //     if (pp < p.size() - 1 && p[pp + 1] == '*')
    //     {
    //         // 进行匹配且成功
    //         if (ps < s.size() && (p[pp] == '.' || p[pp] == s[ps]))
    //         {
    //             flag |= matching(s, p, ps + 1, pp);
    //         }
    //         if (!flag) // 剪枝
    //             flag |= matching(s, p, ps, pp + 2);
    //         else
    //         {
    //             if (ps < s.size() && (p[pp] == s[ps] || p[pp] == '.'))
    //                 flag = matching(s, p, ps + 1, pp + 1);
    //             else
    //                 return false;
    //         }
    //     }
    //     return flag;
    // }

    // bool isMatch(string s, string p)
    // {
    //     // 在p为空后，只需要查看s是否为空即可
    //     if (p.empty())
    //         return s.empty();

    //     // 查看首元素是否一致
    //     bool first_match = !s.empty() && (s[0] == p[0] || p[0] == '.');
    //     // 若下一个字符为*
    //     if (p.size() >= 2 && p[1] == '*')
    //     {
    //         return (bool)(isMatch(s, p.substr(2)) || (first_match && isMatch(s.substr(1), p)));
    //     }
    //     // 一般情况
    //     else
    //         return bool(first_match && isMatch(s.substr(1), p.substr(1)));
    // }

    bool first_match(string s, string p, int i, int j)
    {
        return s[i] == p[j] || p[j] == '.';
    }

    bool isMatch(string s, string p)
    {
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1));
        dp[0][0] = true;

        // dp数组初始化
        for (int j = 2; j <= p.size(); j++)
            dp[0][j] = p[j - 1] == '*' && dp[0][j - 2];

        for (int i = 0; i < s.size(); i++)
            for (int j = 0; j < p.size(); j++)
            {
                if (p[j] == '*')
                    dp[i + 1][j + 1] = dp[i + 1][j - 1] || first_match(s, p, i, j - 1) && dp[i][j + 1];
                else
                    dp[i + 1][j + 1] = first_match(s, p, i, j) && dp[i][j];
            }
        return dp[s.size()][p.size()];
    }
};
// @lc code=end
