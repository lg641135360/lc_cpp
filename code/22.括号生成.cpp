/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
    // 什么是合法的括号
    // 1.左括号与右括号的数量不能超过n
    // 2.每放一个左括号，才可放一个右括号，也就是右括号不能先于左括号放
    // 递归限制条件
    // 1.左右括号数量，最多n个 2.若左括号数量<=右括号，不可放右括号递归
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate("",n,n,res);
        return res;
    }

    void generate(string item,int left,int right,vector<string> &res){
        if(!left&&!right){   // 当左右括号都放光了
            res.push_back(item);
            return;
        }
        if(left>0){   // 先放左括号
            generate(item+"(",left-1,right,res);
        }
        if(left < right) // 当放左括号数量多于右括号时，才需要放右括号
            generate(item+")",left,right-1,res);
    }
};
// @lc code=end

