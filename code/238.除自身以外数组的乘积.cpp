/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
class Solution {
public:
    // 当nums长度太长时,超时 n^2
    // vector<int> productExceptSelf(vector<int>& nums) {
    //     vector<int> res(nums.begin(),nums.end());
    //     for(int i=0;i<nums.size();++i) {
    //         int n = 1;
    //         for(int j=0;j<nums.size();++j) {
    //             if(j!=i) n*= nums[j];
    //             else continue;
    //         }
    //         res[i] = n;
    //     }
    //     return res;
    // }

    // O(n) 时间复杂度完成 ==> 一次循环
    // 两个数组，L(i) 和 R(i)
    // L(i)  表示索引i元素左边元素积,R(i)则是i下标元素右边元素积
    // 最后遍历整个数组，将L(i) * R(i)即可
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> L(n,1);
        vector<int> R(n,1);
        vector<int> res(n,1);

        // 填充L(i)数组
        // 这里L(0)左边没有元素，直接就是1
        for(int i=1;i<n;++i) 
            L[i] = L[i-1] * nums[i-1];
        for(int i=n-2;i>=0;--i)
            R[i] = R[i+1] * nums[i+1];

        // 遍历数组，累积每个位置的L(i) * R(i)
        for(int i=0;i<n;++i)
            res[i] = L[i] * R[i];
        return res;
    }
};
// @lc code=end

