/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        string sum = "";
        int la=a.size()-1;
        int lb=b.size()-1;
        int c=0;    // 进位标志符
        
        // 加法器
        while(la>=0&&lb>=0) {
            int tmp = a[la] - '0' + b[lb] - '0' + c; //此处进位
            c = tmp/2;   // 判断是否进位，若相加为2则说明进位
            sum = (char)('0'+ tmp%2) + sum; // 反着连接两个字符
            la --;
            lb --;
        }
        // 当某一个还有剩余时
        while(la>=0)
        {
            int tmp = a[la] - '0' + c;
            c = tmp/2;
            sum = (char)('0' + tmp%2) + sum;
            la--;
        }
        while(lb>=0)
        {
            int tmp = b[lb] - '0' + c;
            c = tmp/2;
            sum = (char)('0' + tmp%2) + sum;
            lb--;
        }
        //如果最高位需要进位
        if(c == 1)
            sum = "1" + sum;
        return sum;
    }
};
// @lc code=end

