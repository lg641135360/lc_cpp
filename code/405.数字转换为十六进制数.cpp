/*
 * @lc app=leetcode.cn id=405 lang=cpp
 *
 * [405] 数字转换为十六进制数
 */

// @lc code=start
class Solution {
public:
    // 循环除以16，加到一个string中，最后逆置字符串即可
    // 只能用于正数
    // 负数 取反加一
    // string toHex(int num) {
    //     string res;

    //     if(num>=0) {
    //         process(num,res);
    //     } 
    //     else {
    //         // 转换成2进制，按位取反，补码（加一），转16进制
    //         int tmp = -num;  // -2 ==> 2
    //         char chars[32];
    //         sprintf(chars,"%")

    //     }
        

    //     return res;
    // }

    // void process(int num,string &res) {
    //     while(num) {
    //         int tmp = num % 16;
    //         res += int_to_string(tmp);
    //         num /= 16;
    //     }
        
    //     reverse(res.begin(),res.end());
    // }

    // string int_to_string(int n) {
    //     string res;
    //     if(n<10) {
    //         res = to_string(n);
    //         return res;
    //     }
    //     else {
    //         switch (n)
    //     {
    //         case 10:
    //             res = "a";
    //             break;
    //         case 11:
    //             res="b";
    //             break;
    //         case 12:
    //             res="c";
    //             break;
    //         case 13:
    //             res="d";
    //             break;
    //         case 14:
    //             res="e";
    //             break;
    //         default:   // 15
    //             res="f";
    //             break;
    //         }
    //     }
    //     return res;
    // }

    // 调库
    // string toHex(int num) {
    //     char buff[233];
    //     memset(buff,0,sizeof buff); // 内存初始化函数，将buff指向的前n字节单元用 第三个数字代替
    //     sprintf(buff,"%x",num);
    //     return string(buff);
    // }

    // 使用位运算，每4位，对应1个16进制数字
    // 使用0xf(00...01111b)获取num的低4位。
    // >>算数位移，其中正数右移左边补0，负数右移左边补1。
    // 位移运算并不能保证num==0，需要使用32位int保证（对应16进制小于等于8位）。
    string toHex(int num) {
        if (num == 0) return "0";
        string hex = "0123456789abcdef", ans = "";
        while(num && ans.size() < 8){
            ans = hex[num & 0xf] + ans;
            num >>=  4; 
        }
        return ans;
    }
};
// @lc code=end

