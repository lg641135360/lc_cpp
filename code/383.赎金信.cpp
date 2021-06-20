/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
class Solution {
public:
    // 整点憨憨想法
    bool canConstruct(string ransomNote, string magazine) {
      sort(ransomNote.begin(),ransomNote.end());
      sort(magazine.begin(),magazine.end());
      int r=ransomNote.size()-1;
      int m=magazine.size()-1;
      int i=0,j=0;
      for(;i<=r&&j<=m;){
        if(ransomNote[i] == magazine[j]) {
          i++;
          j++;
        }else j++;
      }
      if(i<=r&&j==m+1) return false;
      else return true;
    }
    

};
// @lc code=end

