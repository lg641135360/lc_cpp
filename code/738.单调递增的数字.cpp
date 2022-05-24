/*
 * @lc app=leetcode.cn id=738 lang=cpp
 *
 * [738] 单调递增的数字
 */

// @lc code=start
class Solution
{
public:
    // int monotoneIncreasingDigits(int n)
    // {
    //     for (int i = n; i > 0; i--)
    //         if (checkNum(i))
    //             return i;
    //     return 0;
    // }

    // private:
    //     bool checkNum(int num)
    //     {
    //         int max = 10;
    //         while (num)
    //         {
    //             int t = num % 10;
    //             if (max >= t)
    //                 max = t;
    //             else
    //                 return false;
    //             num = num / 10;
    //         }
    //         return true;
    //     }

    int monotoneIncreasingDigits(int N)
    {
        string strNum = to_string(N);
        // flag用来标记赋值9从哪里开始
        // 设置为这个默认值，为了防止第二个for循环在flag没有被赋值的情况下执行
        int flag = strNum.size();
        for (int i = strNum.size() - 1; i > 0; i--)
        {
            if (strNum[i - 1] > strNum[i])
            {
                flag = i;
                strNum[i - 1]--;
            }
        }
        for (int i = flag; i < strNum.size(); i++)
        {
            strNum[i] = '9';
        }
        return stoi(strNum);
    }
};
// @lc code=end
