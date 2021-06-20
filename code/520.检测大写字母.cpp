/*
 * @lc app=leetcode.cn id=520 lang=cpp
 *
 * [520] 检测大写字母
 */

// @lc code=start
class Solution {
public:
    bool detectCapitalUse(string word) {
      int n = word.size();
      int count = 0;
      bool first = false;
      string lower = word;
      for(int i=0;i<n;i++){
        if(word[i] >= 'A' && word[i] <= 'Z'){
          lower[i] += 32;
          count++;
        }
      }
      if(word[0] >= 'A' && word[0] <= 'Z') first = true;
      // 当大写字母个数不是n且大于一个时
      if(count != n && count>1) return false;
      else if(count==n) return true;
      else if(first && count == 1) return true;
      else if(count == 0) return true;
      else return false;
    }
};
// @lc code=end

