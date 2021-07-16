/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
class Solution {
public:
        // 超时惹
    int strStr(string haystack, string needle) {

        // base case
        if(needle.size()==0) return 0;

        int i,j;
        i=j=0;
        int index=0;
        bool isHead=false;
        int m=haystack.size();
        int n=needle.size();
        while(i<m&&j<n) {
            if(haystack[i] != needle[j]) {
                if(!isHead)
                    ++i;
                else {
                    isHead = false;
                    // 重新看
                    i = index + 1;
                    j = 0;
                }
            } 
            if(haystack[i] == needle[j]) {
                if(!isHead) {
                    index = i;
                    isHead = true;
                }
                ++i;
                ++j;
            }
        }
        
        // find it!
        if(j==needle.size()&&isHead) return index;
        // can not find it
        else return -1;
        // return 0;
    }

    // 方法2：调库
    // int strStr(string haystack, string needle) { 
    //     int pos = haystack.find(needle);
    //     if(pos != string::npos)
    //         return pos;
    //     else
    //         return -1;
    // }

    // int strStr(string haystack, string needle) { 
    //     if(needle.size() == 0) return 0;
    //     int m=haystack.size(),n=needle.size();
    //     for(int i=0;i<=m-n;++i) {
    //         if(haystack[i] == needle[0]) {
    //             int j=i+1;
    //             int k=1;
    //             while(j<m&&k<n&&haystack[j] == needle[k]) {
    //                 j++;
    //                 k++;
    //             }
    //             if(k==m) return i;
    //         }
    //     }
    //     return -1;
    // }
};
// @lc code=end

