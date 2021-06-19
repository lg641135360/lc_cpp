/*
 * @lc app=leetcode.cn id=190 lang=cpp
 *
 * [190] 颠倒二进制位
 */

// @lc code=start
class Solution {
public:
    // 让n&1每次取得最低位，每次将n右移一位，加入结果
    uint32_t reverseBits(uint32_t n) {
      uint32_t res = 0;
      for(int i = 0;i<32&&n>0;++i){
        // 首先将n与1相与，取得最低位，再将其左移31-i位（就成了32位数字）
        // 然后将每一位的结果都收集(或操作)起来，最后拼装成32位的数字
        res |= (n & 1) << (31 - i);
        // 求得低位后，将n右移，进入循环
        n >>= 1;
      }
      return res;
    }
};
// @lc code=end

