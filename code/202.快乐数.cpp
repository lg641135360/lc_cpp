/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution
{
public:
  // “快慢指针” 思想，找出循环：“快指针” 走两步，“慢指针”走一步
  // 当两个指针相等 为一个循环
  // 此时，判断是不是因为 1 引起的循环，是的话就是快乐数，否则不是快乐数。
  bool isHappy(int n)
  {
    int slow = n, fast = n;
    do
    {
      slow = bitSquareSum(slow);
      fast = bitSquareSum(fast);
      fast = bitSquareSum(fast);
    } while (slow != fast);

    return fast == 1;
  }

  // 按位求平方和操作
  int bitSquareSum(int n)
  {
    int sum = 0;
    while (n > 0)
    {
      int bit = n % 10;
      sum += bit * bit;
      n = n / 10;
    }
    return sum;
  }
};
// @lc code=end
