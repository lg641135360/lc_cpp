/*
 * @lc app=leetcode.cn id=231 lang=cpp
 *
 * [231] 2 的幂
 */

// @lc code=start
class Solution {
public:
    // 将数字转换成2进制，所有位只有一个1就是2的幂次
    bool isPowerOfTwo(int n) {
      // 正数才有进行判断的意义
      if(n>0){
        // 首先将数字转换成二进制
        bitset<32> bit(n);

        // 再考察二进制数中的1的个数
        if(bit.count()!=1) return false;
        else return true;
      }
      // 负数全不是
      else return false;
    }
};
// @lc code=end

