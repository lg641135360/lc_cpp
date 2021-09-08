/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */

// @lc code=start
class Solution {
public:
    vector<int> countBits(int n) {
      vector<int> res;
      for(int i=0;i<=n;i++){
        bitset<32> bit(i);
        res.push_back(bit.count());
      }
      return res;
    }
};
// @lc code=end

