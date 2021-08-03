/*
 * @lc app=leetcode.cn id=696 lang=cpp
 *
 * [696] 计数二进制子串
 */

// @lc code=start
class Solution {
public:
    // 滑动窗口
    // 特别长的例子过不来
    // int countBinarySubstrings(string s) {
    //     // base case
    //     if(s.size() == 1) return 0;

    //     int begin = 0;
    //     int count = 0;
    //     int zero_count = 0;
    //     int one_count= 0;
    //     if(s[begin] == '0') zero_count = 1;
    //     else one_count = 1;
    //     for(int i = 1;i<s.size();) {
    //         if(s[i] == '1') {
    //             one_count ++; 
    //             ++i;
    //         }  
    //         else {
    //             zero_count ++;
    //             ++i;
    //         }

    //         if(one_count == zero_count) {
    //             count++;
    //             // 重新计数
    //             one_count = 0;
    //             zero_count = 0;
    //             begin ++;
    //             i=begin+1;
    //             if(i==s.size()) break;
    //             if(s[begin] == '0') zero_count = 1;
    //             else one_count = 1;
                
    //         }
    //         else if(i==s.size()) {
    //             // 重新计数
    //             one_count = 0;
    //             zero_count = 0;
    //             begin ++;
    //             i=begin+1;
    //             if(i==s.size()) break;
    //             if(s[begin] == '0') zero_count = 1;
    //             else one_count = 1;
    //         }
    //     }
    //     return count;
    // }

    // 通过一个vector记录连续0或1的个数
    // 例如 s = 00111011 counts=[2,3,1,2]
    // 计算0011产生min(u,v)个连续01串
    int countBinarySubstrings(string s) {
        s += '-';  // 添加一个简化计算
        vector<int> counts;
        // 滑动窗口
        int begin=0;
        int count=0;
        for(int i=1;i<s.size();) {
            if(s[begin] != s[i]) {
                counts.push_back(i-begin);
                begin = i;
                i++;
            }
            else i++;
        }
        for(int i=1;i<counts.size();++i) 
            count += min(counts[i],counts[i-1]);
        return count;
    }
};
// @lc code=end

