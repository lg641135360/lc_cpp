/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 翻转字符串里的单词
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        // 预处理：将字符串前面的空格去除
        // 在字符串最后添加空格
        // 将单词之间的多余空格去除
        trim_and_add_(s);

        // 根据空格判断一个单词，逐个加入数组
        vector<string> s_vector;
        generate_vector(s,s_vector);
        
        // 逆序单词数组
        reverse(s_vector.begin(), s_vector.end());

        // 将逆序后单词数组逐个加入字符串
        string res;
        for(string s_:s_vector) {
            res+=s_;
            res+=" ";
        }
            
        // 去除最后一个空格
        res = res.erase(res.size()-1,1);
        return res;
    }

    void trim_and_add_(string &s) {
        // 找出第一个不是空格的位置
        int i=0;
        for(;i<s.size();++i) 
            if(s[i] != ' ') break;
        // 此时第一个非空格字符不在第一个位置
        if(i!=0) s = s.substr(i);

        // 给最后一个位置插入空格
        if(s[s.size()-1] != ' ') s.push_back(' ');

        // 去除连续空格
        for(int i=0;i<s.size();++i) 
            while(s[i]==' ' && s[i+1]==' ')
                s.erase(i,1);    // 删除从下标i开始的1个元素
    }

    void generate_vector(string &s,vector<string> &s_vector) {
        string tmp;
        for(int i=0;i<s.size();++i) {
            if(s[i] != ' ') tmp += s[i];
            else {
                s_vector.push_back(tmp);
                tmp = "";
            }
        }
    }
};
// @lc code=end

