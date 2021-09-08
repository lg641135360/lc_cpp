/*
 * @lc app=leetcode.cn id=374 lang=cpp
 *
 * [374] 猜数字大小
 */

// @lc code=start
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
      int left = 1,right =n,mid=0;
      // 循环猜的过程就好了
      while(1){
        mid = left + (right-left)/2;
        int ans = guess(mid);
        if(ans==0) return mid;
        else if(ans==-1) right = mid-1;
        else left = mid +1;
      }
      return mid;
    }
};
// @lc code=end

