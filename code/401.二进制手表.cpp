/*
 * @lc app=leetcode.cn id=401 lang=cpp
 *
 * [401] 二进制手表
 */

// @lc code=start
class Solution {
public:
    // 回溯
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        
        // bfs遍历回溯
        for(int hours=0;hours<12;++hours) {
            for(int minute = 0;minute < 60; ++minute) {
                string tmp = "";
                if(countOne(hours) + countOne(minute) == num)
                {
                    tmp += to_string(hours) + ":";

                    if(minute < 10)    // 小于10需要补0
                        tmp += "0";
                    tmp += to_string(minute);
                    res.push_back(tmp);
                }
            }
        }
        return res;
    }

    // 返回输入数据中二进制的个数
    // 内置于gcc中，将8bit的数字所有数字的1的个数放在一个表中
    // 查表
    int countOne(int num) {
        return __builtin_popcount(num);
    }
};
// @lc code=end

