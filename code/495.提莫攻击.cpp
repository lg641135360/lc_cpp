/*
 * @lc app=leetcode.cn id=495 lang=cpp
 *
 * [495] 提莫攻击
 */

// @lc code=start
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
      int time =0;
      for(int i=0;i<timeSeries.size()-1;i++){
        if(timeSeries[i]+duration<=timeSeries[i+1]) time+=duration;
        else time += timeSeries[i+1] - timeSeries[i];
      }
      time += duration;
      return time;
    }
};
// @lc code=end

