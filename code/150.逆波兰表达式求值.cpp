/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution
{
public:
    // 逆波兰表达式：后序遍历
    // 完全二叉树
    // int evalRPN(vector<string>& tokens) {
    //     for(int i=2;i<tokens.size();) {
    //         // 找到一个运算符
    //         if(!isNum(tokens[i].c_str())) {
    //             compute_(tokens,i);
    //             i -=1;
    //         }
    //         else i++;
    //     }
    //     return stoi(tokens[0]);
    // }

    // void compute_(vector<string> &tokens,int i) {
    //     // 加减乘除
    //     if(tokens[i] == "+") {
    //         int res = stoi(tokens[i-2]) + stoi(tokens[i-1]);
    //         tokens.insert(tokens.begin()+i-2,to_string(res));
    //         tokens.erase(tokens.begin()+i-1,tokens.begin()+i+2);
    //     }
    //     else if(tokens[i] == "-") {
    //         int res = stoi(tokens[i-2]) - stoi(tokens[i-1]);
    //         tokens.insert(tokens.begin()+i-2,to_string(res));
    //         tokens.erase(tokens.begin()+i-1,tokens.begin()+i+2);
    //     }
    //     else if(tokens[i] == "*") {
    //         int res = stoi(tokens[i-2]) * stoi(tokens[i-1]);
    //         tokens.insert(tokens.begin()+i-2,to_string(res));
    //         tokens.erase(tokens.begin()+i-1,tokens.begin()+i+2);
    //     }
    //     else {
    //         int res = stoi(tokens[i-2]) / stoi(tokens[i-1]);
    //         tokens.insert(tokens.begin()+i-2,to_string(res));
    //         tokens.erase(tokens.begin()+i-1,tokens.begin()+i+2);
    //     }
    // }

    // // 整数第一个字符要么是`-`，要么没有
    // bool isNum(const char* str) {
    //     bool isNum = false;

    //     int index = 0;
    //     for (; *str != '\0'; str++, index++)
    //     {
    //         switch (*str)
    //         {
    //         // 当前是数字时，设置标志符为true
    //         case '0':
    //         case '1':
    //         case '2':
    //         case '3':
    //         case '4':
    //         case '5':
    //         case '6':
    //         case '7':
    //         case '8':
    //         case '9':
    //             isNum = true;
    //             break;
    //         // 前面有符号时，设置为
    //         case '-':
    //         // case '+':
    //             if (index != 0)
    //             {
    //                 return false;
    //             }
    //             break;
    //         default:
    //             return false;
    //         }
    //     }
    //     if (!isNum)
    //     {
    //         return false;
    //     }
    //     return true;
    // }

    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;
        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
            {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                if (tokens[i] == "+")
                    st.push(num2 + num1);
                if (tokens[i] == "-")
                    st.push(num2 - num1);
                if (tokens[i] == "*")
                    st.push(num2 * num1);
                if (tokens[i] == "/")
                    st.push(num2 / num1);
            }
            else
                st.push(stoi(tokens[i]));
        }
        int res = st.top();
        st.pop();
        return res;
    }
};
// @lc code=end
