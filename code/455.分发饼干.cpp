/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
      sort(g.begin(),g.end());
      sort(s.begin(),s.end());
      int child = 0;       // child表示满足了几个孩子
      int cookie = 0;      // cookie代表尝试了几个糖果
      while(child<g.size()&&cookie<s.size()) {
        if(g[child] <= s[cookie]) 
            child++;
        cookie++;
      }
      return child;
    }
};
// @lc code=end

