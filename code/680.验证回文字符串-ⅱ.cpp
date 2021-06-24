/*
 * @lc app=leetcode.cn id=680 lang=cpp
 *
 * [680] 验证回文字符串 Ⅱ
 */

// @lc code=start
class Solution {
public:
    // 最多删除一个 == 可以不删除或删除一个
    // 头尾双指针
    bool validPalindrome(string s) {
        int l = 0,r = s.size() - 1;
        int cnt = 0;
        while(l<r){
            if(s[l] == s[r]) {
                l ++;
                r --;
            }
            // 这里发现分歧点，应该退出循环
            else break;
            // else {
            //     s.erase(s.begin()+l);
            //     cnt ++;
            //     // l++;
            // }
        }
        // 判断退出循环的几种情况
        if(l==r) return true; // 正常退出

        // 情况1 删除l指向元素
        int newL = l +1,newR = r;
        // 两个标志位
        bool flag1 = true,flag2=true;
        while(newL<newR){
            if(s[newL] == s[newR])
            {
                ++newL;
                --newR;
            }
            else
            {
                flag1 = false; // 不是第一种情况
                break;
            }
        }

        // 情况2：删除r指向元素
        newL = l,newR=r-1;
        while(newL<newR){
            if(s[newL] == s[newR])
            {
                ++newL;
                --newR;
            }
            else
            {
                flag2 = false; // 不是第二种情况
                break;
            }
        }
        return flag1||flag2; // 两种情况有一种就可以了
    }
};
// @lc code=end

