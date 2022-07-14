/*
 * @lc app=leetcode.cn id=224 lang=cpp
 *
 * [224] 基本计算器
 */

// @lc code=start
class Solution
{
public:
    // 字符串中有4种东西，其中' '字符可以先去除，不影响计算
    // 利用栈，对其进行运算符后序计算
    // 只有加减法，直接打开括号计算
    int calculate(string s)
    {
        stack<int> sign; //栈顶记录当前符号
        sign.push(1);    //默认为正

        int res = 0, num = 0, op = 1;
        for (char ch : s)
        {                               //空格可以不管，直接忽略
            if (ch >= '0' && ch <= '9') //取出完整数值
            {
                num = num * 10 + (ch - '0');
                continue;
            }
            res += op * num; //计算一个运算符
            num = 0;         //数值清空

            if (ch == '+')
                op = sign.top();
            else if (ch == '-')
                op = -sign.top();
            else if (ch == '(')
                sign.push(op); //进入左括号，把左括号之前的符号置于栈顶
            else if (ch == ')')
                sign.pop(); //退出括号，弹出栈顶符号
        }

        res += op * num; //计算最后一个数
        return res;
    }
};
// @lc code=end
