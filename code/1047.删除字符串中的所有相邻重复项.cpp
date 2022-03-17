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
        // base
        if (s.size() == 1)
            return s;

        st.push(s[0]);
        int index = 1;
        while (!st.empty() && index < s.size())
        {
            if (s[index] == st.top())
            {
                s.erase(index - 1, 2);
                st.pop();
                index--;
                // 空了再加
                if (st.empty())
                    st.push(s[index++]);
            }
            else
                st.push(s[index++]);
        }
        return s;
    }

private:
    stack<char> st;
};
// @lc code=end
