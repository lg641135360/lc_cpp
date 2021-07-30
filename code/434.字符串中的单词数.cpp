/*
 * @lc app=leetcode.cn id=434 lang=cpp
 *
 * [434] 字符串中的单词数
 */

// @lc code=start
class Solution {
public:
    // int countSegments(string s) {
    //     // 去除头尾部的空格
    //     trim_(s);
    //     // base case
    //     if(s.size()==0) return 0;
        
    //     int word_count = 0;
    //     int begin = 0;
    //     for(int i=1;i<s.size()-1;++i)
    //         if(s[i] == ' ') word_count ++;
    //     word_count++;
    //     return word_count;
    // }

    // void trim_(string &s) {
    //     int begin=0;
    //     int end=s.size()-1;
    //     while(s[begin] == ' ' && begin<= end) begin++;
    //     while(s[end]==' ' && end>=begin) end--;
    //     s = s.substr(begin,end-begin+1);
    // }

    int countSegments(string s) {
        int begin;
        int end;
        int count = 0;
        int i;
        int j;
        for(i=0;i<s.size();++i) {
            if(s[i] != ' ') {
                begin = i;
                break;
            }
        }
        if(i == s.size()) return 0;
        for(j=s.size()-1;j>=0;--j) 
            if(s[j] != ' ') {
                end = j;
                break;
            }
        // [begin,end]是单词的范围
        for(;begin<=end;++begin) {
            if(s[begin] == ' ') {
                // 将越界判断放前面，如果false就不会进行下标越界的访问
                if(begin+1<=end && s[begin+1] == ' ')
                    continue;
                else count ++;
            }
        }
        count++;
        return count;
    }
};
// @lc code=end

