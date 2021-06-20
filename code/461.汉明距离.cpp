/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 */

// @lc code=start
class Solution {
public:
    int hammingDistance(int x, int y) {
      bitset<32> bitX(x);
      bitset<32> bitY(y);
      int count=0;
      for(int i = 0;i<32;i++){
        if(bitX[i]!=bitY[i]) count++;
      }
      return count;
    }
};
// @lc code=end

