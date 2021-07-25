/*
 * @lc app=leetcode.cn id=278 lang=cpp
 *
 * [278] 第一个错误的版本
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    // 超时
    // int firstBadVersion(int n) {
    //     int badVersion = -1;
    //     for(int i=1;i<=n;++i) {
    //         if(isBadVersion(i)) {
    //             badVersion = i;
    //             break;
    //         }
    //         else continue;
    //     }
    //     return badVersion;                       
    // }

    int firstBadVersion(int n) { 
        long start = 1;
        long end = n;
        while(start<=end) {
            long mid = start + (end - start) / 2;
            if(isBadVersion(mid)) 
                end = mid-1;
            else start = mid + 1;
        } 
        return (int)start;
    }
};
// @lc code=end

