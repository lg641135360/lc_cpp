/*
 * @lc app=leetcode.cn id=717 lang=cpp
 *
 * [717] 1比特与2比特字符
 */

// @lc code=start
class Solution {
public:

    // 遍历思路
    // 出现一个1，要么是10或者11，直接i加上2
    // 出现一个0，直接i加上1
    // 遍历到倒数第二个：
    //      前面正好是1，最后一个被跳过，i=n
    //      前面不是1，正好走到最后一个，i=n-1
    bool isOneBitCharacter(vector<int>& bits) {
        int n=bits.size();
        int i=0;
        while(i<n-1)
            i+=bits[i]+1;
        // 这里如果能走到n说明走了两步，最后一个0被当做10吸收了，false
        // 走到n-1，说明此时没有被吸收，还有最后一个0，true
        return i==n-1;
    }
};
// @lc code=end

