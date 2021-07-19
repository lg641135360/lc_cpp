/*
 * @lc app=leetcode.cn id=476 lang=cpp
 *
 * [476] 数字的补数
 */

// @lc code=start
class Solution {
public:
    int findComplement(int num) {
        string str_bin = change_int_to_binary(num);
        change_1_and_0(str_bin);
        int res = calulate(str_bin);
        return res;
    }

    string change_int_to_binary(int &num) {
        string tmp;
        string res;
        while(num) {
            tmp += num % 2 + '0';
            num /= 2;
        }
        for(int i=tmp.size()-1;i>=0;--i)
            res += tmp[i];
        return res;
    }

    void change_1_and_0(string &str_bin) {
        for(int i=0;i<str_bin.size();++i) {
            if(str_bin[i] == '1')
                str_bin[i] = '0';
            else str_bin[i] = '1';
        }
    }

    int calulate(string str_bin) {
        int res = 0;
        for(int i=0;i<str_bin.size();++i) {
            res = res * 2 + str_bin[i] - '0';
        }
        return res;
    }

};
// @lc code=end

