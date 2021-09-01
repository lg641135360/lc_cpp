/*
 * @lc app=leetcode.cn id=201 lang=cpp
 *
 * [201] 数字范围按位与
 */

// @lc code=start
class Solution {
public:
    // 离谱，超时了[1,2147483647]
    // 考虑剪枝
    // int rangeBitwiseAnd(int left, int right) {
    //     bitset<32> res(4294967295);
    //     for(int i=left;i<=right;i++) {
    //         bitset<32> tmp(i);
    //         res &= tmp;
    //     }
    //     return (int)res.to_ullong();
    // }

    int getTheHighestOneIndex(bitset<32> &num) {
        for(int i=31;i>=0;--i)
            if(num.test(i))
                return i;
        return -1;
    }
    int countHighestOnesNumber(bitset<32> &num,int highestOneIndex) {
        int i=highestOneIndex-1;
        for(;i>=0;--i)
            // 找到第一个不为1的数字下标
            if(!num.test(i))
                break;
        return highestOneIndex-i;
    }

    // 考虑剪枝，其值往往由最小值限定，1出现的位置
    // 当最大值的1能出现在最小值的1最高位后面
    // int rangeBitwiseAnd(int left, int right) {
    //     // base case
    //     if(left == right) return left;

    //     bitset<32> low(left);
    //     bitset<32> high(right);

    //     int highOneLeft = getTheHighestOneIndex(low);
    //     int highOneRight = getTheHighestOneIndex(high);

    //     if(highOneLeft < highOneRight) return 0;
    //     // 相等时，留下最高位，看两个数字高位连续有多少个1
    //     else return min(countHighestOnesNumber(low,highOneLeft),countHighestOnesNumber(high,highOneRight));
            
    // }

    void compute(bitset<32> &num,int &res) {
        for(int i=31;i>=0;i--)
            if(num.test(i))
                res += pow(2,i);
    }

    void resetZero(bitset<32> &num,int i) {
        for(int index=i;i>=0;i--)
            num.reset(i);
    }

    // 最终方案：找到left从最高位到最低位与right相同的数字，也就是最后结果
    int rangeBitwiseAnd(int left, int right) {
        // base case
        if(left == right) return left;

        bitset<32> low(left);
        bitset<32> high(right);

        int res = 0;
        // 当右值的最高位大于左值的最高位
        // 此时一定会出现全0情况
        if(getTheHighestOneIndex(high) > getTheHighestOneIndex(low)) return 0;
        // 此时两者的最高位相同
        for(int i=getTheHighestOneIndex(low);i>=0;) {
            // 两个数位置相同，继续遍历
            if(low[i] == high[i]) --i;
            // 两个位置不同，set 0 beyond i
            else {
                resetZero(low,i);
                break;
            }
        }
        compute(low,res);
        return res;
    }
};
// @lc code=end

