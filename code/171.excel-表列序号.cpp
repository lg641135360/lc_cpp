/*
 * @lc app=leetcode.cn id=171 lang=cpp
 *
 * [171] Excel 表列序号
 */

// @lc code=start
class Solution {
public:
    // 只有一位 该字符减去65+1即可
    // 两位 26 + 第二个字符 减去65+1 乘以26 + 第二位减去65+1\
    // 控制一个循环 计算从第一位到最后一位的和
    int titleToNumber(string columnTitle) {
        int number = 0;
        int ii=0;
        for(int i=columnTitle.size()-1;i>=0;--i) {
            number += min_six_five_plus_one(columnTitle[i]) * pow(26,ii++);
        }
        return number;
    }

    int min_six_five_plus_one(const char &c) {
        return c-65+1;
    }
};
// @lc code=end

