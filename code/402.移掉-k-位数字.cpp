/*
 * @lc app=leetcode.cn id=402 lang=cpp
 *
 * [402] 移掉 K 位数字
 */

// @lc code=start
class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<int> s;    // 使用vector实现栈
        string res = "";
        for(int i=0;i<num.size();++i) {
            int number = num[i] - '0';  // 将最高位char转换成数字
            // 出栈
            while(s.size()!=0 && number<s[s.size()-1] &&k>0) {
                s.pop_back();
                k--;
            }
            // 入栈
            // 当前元素是0也可以入栈
            if(number!=0||s.size()!=0) 
                s.push_back(number);
        }
        while(s.size()!=0&&k>0) {
            s.pop_back();
            k--;
        }
        for(int i=0;i<s.size();++i)
            res += to_string(s[i]);
        if(res=="")
            res="0";
        return res;
    }
};
// @lc code=end

