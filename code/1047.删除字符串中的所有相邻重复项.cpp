/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
class Solution
{
public:
    // 栈？
    string removeDuplicates(string s)
    {
        for (char c : s)
        {
            if (st.empty() || c != st.top())
                st.push(c);
            else
                st.pop();
        }
        string res = "";
        while (!st.empty())
        {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }

private:
    stack<char> st;
};
// @lc code=end
