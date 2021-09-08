/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {
      int i=0,j=0;
      int sN=s.size()-1,tN=t.size()-1;
      for(;i<=sN&&j<=tN;){
        if(s[i]==t[j]){
          i++;
          j++;
        }else j++;
      }
      if(i<=sN&&j==tN+1) return false;
      else return true;
    }
};
// @lc code=end

