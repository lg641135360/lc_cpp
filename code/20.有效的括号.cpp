/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution
{
public:
    bool isValid(string s)
    {
        // 长度为奇数，直接返回false
        if (s.size() % 2)
            return false;
        stack<char> s_c;
        // 遍历字符串
        for (int i = 0; i < s.size(); ++i)
        {
            // 碰到左括号入栈
            if (isLeft(s, i))
                s_c.push(s[i]);
            else if (!s_c.empty())
            { // 碰到右括号出栈，对比是否配对
                if (isPair(s_c.top(), s[i]))
                    s_c.pop();
                // 不配对，返回false
                else
                    return false;
            }
            else
                return false;
        }
        if (!s_c.empty())
            return false;
        return true;
    }

    bool isLeft(string s, int i)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            return true;
        else
            return false;
    }

    bool isPair(char c1, char c2)
    {
        if ((c1 == '[' && c2 == ']') || (c1 == '{' && c2 == '}') || (c1 == '(' && c2 == ')'))
            return true;
        else
            return false;
    }
};
// @lc code=end
