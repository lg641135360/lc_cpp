/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */

// @lc code=start
class Solution {
public:
    // string reverseStr(string s, int k) {
    //     if(s.size() % (2*k) < k) {
    //         for(int i=0,j=i+k-1;i<(s.size()-s.size()%(2*k));i+=(2*k),j=i+k-1){
    //             while(i<j)
    //                 swap(s[i++],s[j--]);
    //         }
    //         for(int i=s.size()-s.size()%(2*k),j=s.size()-1;i<=j;i++,j--) {
    //             swap(s[i],s[j]);
    //         }
    //         return s;
    //     }
    //     else {
    //         for(int i=0,j=i+k-1;i<(s.size()-s.size()%(2*k));i+=(2*k),j=i+k-1){
    //             while(i<j)
    //                 swap(s[i++],s[j--]);
    //         }
    //         for(int i=s.size()-s.size()%(2*k),j=i+k-1;i<=j;i++,j--) {
    //             swap(s[i],s[j]);
    //         }
    //         return s;
    //     }
    // }

    // 调库
    string reverseStr(string s, int k) {
        for(int i=0;i<s.size();i+=(2*k)) {
            // 每隔2k个字符的前k个反转
            // 剩余字符小于2k但大于等于k的，反转前k个
            if(i+k <= s.size()) {
                reverse(s.begin()+i,s.begin()+i+k);
                continue;
            }
            // 剩余字符少于k个，剩余字符全部反转
            reverse(s.begin()+i,s.begin()+s.size());
        }
        return s;
    }
};
// @lc code=end

