/*
 * @lc app=leetcode.cn id=60 lang=cpp
 *
 * [60] 排列序列
 */

// @lc code=start
class Solution {
public:
     // 方法1：使用回溯法的思路思考，则每当选择一个数加入排列时，可以计算出剩下的数还有多少种排列的可能，
    // 即可以计算出当前被选择的数的排列总数，设用 remain_fac 表示， remain_fac = 剩下的待选择的数的阶乘。
    // 然后将 remain_fac 与 k 进行大小比较，若小于 k ，则说明所要求的第 k 个排列不在以 当前选定的数 为开头的所有排列中，直接跳过
    // 一次递归到底就能找到 第 k 个排列
    string getPermutation(int n, int k) {
        vector<bool> isUsed(n + 1, false);          // 用于标记每个数是否用过
        string res = "";                            // 用于返回的结果排列序列

        dfs(isUsed, res, n, k);
        return res;
    }
    // 递归实现
    void dfs(vector<bool> &isUsed, string &res, int n, int k){
        int res_len = res.size();
        if(res_len == n){    // 结束条件，当前排列已经结束
            return;
        }
        int remain_fac = factorial(n - res_len - 1);  // 剩下的数的全排列的个数
        for(int i = 1; i <= n; ++i){                  // 遍历 [1, n]
            if(isUsed[i]){                            // 跳过已使用的数
                continue;
            }
            if(remain_fac > 0 && remain_fac < k){     // 剩下的数的全排列个数小于当前 k ，说明第 k 个排列肯定不在当前的递归子树中，直接跳过该递归
                k -= remain_fac;                      // 剪枝
                continue;
            }
            res = res + static_cast<char>('0' + i);
            isUsed[i] = true;
            dfs(isUsed, res, n, k);
                                                      // 因为是一次递归直接到叶子，所以不需要还原状态
        }
    }
    // 求 n 的阶乘 或者直接使用数组：factorial = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880}
    int factorial(int n){
        int res = 1;
        while(n > 0){
            res *= n;
            n--;
        }
        return res;
    }
};
// @lc code=end

