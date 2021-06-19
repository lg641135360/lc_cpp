/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */

// @lc code=start
class Solution {
public:
    int hammingWeight(uint32_t n) {
      int count = 0;
      for(int i = 0; i<32&& n >0;i++){
        // 取得最低位置 是否为1
        count += (n&1 ==1)?1:0;
        n >>= 1;
      }
      return count;
    }
};
// @lc code=end

