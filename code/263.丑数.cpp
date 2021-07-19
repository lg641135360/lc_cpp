/*
 * @lc app=leetcode.cn id=263 lang=cpp
 *
 * [263] 丑数
 */

// @lc code=start
class Solution {
public:
    bool isUgly(int num) {
        for (int i=2; i<6 && num; i++)
            // 把能除尽的都除掉
            while (num % i == 0)
                num /= i;
        return num == 1;
    }
};
// @lc code=end

