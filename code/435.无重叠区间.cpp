/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

// @lc code=start
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // base case
        if(intervals.size()<1) return 0;
        int n = intervals.size();
        // 使用自定义的排序方法来按照结束时间最短排序（贪心，结束时间越早，获得的区间越多，那么需要移除的区间数越少）
        // 这里使用lambam表达式来描述排序函数
        sort(intervals.begin(),intervals.end(),[](vector<int>a,vector<int> b){return a[1] < b[1];});
        int count=0,prev = intervals[0][1];
        for(int i=1;i<n;i++){
            // 后一个开始时间小于前一个的结束时间（也就是发生了冲突）
            // 这里冲突了，prev不更新
            if(intervals[i][0] < prev) count++;
            // 不冲突时才需要更新prev
            else prev=intervals[i][1];
        }
        return count;
    }
};
// @lc code=end

